
/*
  wla - part of wla dx gb-z80/z80/6502/65c02/68000/6800/6801/6809/65816/huc6280/spc-700/8008/8080/SuperFX
  macro assembler package by ville helin <ville.helin@iki.fi>. this is gpl software.
*/

#include "flags.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "defines.h"
#include "parse.h"
#include "include.h"
#include "phase_1.h"
#include "phase_2.h"
#include "phase_3.h"
#include "phase_4.h"
#include "listfile.h"
#include "hashmap.h"
#include "printf.h"
#include "mersenne.h"
#include "stack.h"


FILE *g_file_out_ptr = NULL;

#if defined(AMIGA)
__near long __stack = 200000;
#endif

char s_version_string[] = "$VER: wla-" WLA_NAME " 10.6a (30.7.2023)";
char s_wla_version[] = "10.6";

extern struct incbin_file_data *g_incbin_file_data_first, *g_ifd_tmp;
extern struct file_name_info *g_file_name_info_first;
extern struct label_def *g_label_tmp, *g_labels;
extern struct map_t *g_global_unique_label_map;
extern struct macro_static *g_macros_first;
extern struct map_t *g_defines_map;
extern struct export_def *g_export_first, *g_export_last;
extern struct repeat_runtime *g_repeat_stack;
extern struct section_def *g_sections_first;
extern struct macro_runtime *g_macro_stack;
extern struct label_def *g_unknown_labels;
extern struct label_def *g_unknown_header_labels;
extern struct filepointer *g_filepointers;
extern struct map_t *g_namespace_map;
extern struct after_section *g_after_sections;
extern struct label_sizeof *g_label_sizeofs;
extern struct block_name *g_block_names;
extern struct stringmaptable *g_stringmaptables;
extern struct array *g_arrays_first;
extern struct structure *g_structures_first;
extern struct structure **g_saved_structures;
extern struct string *g_fopen_filenames_first, *g_fopen_filenames_last;
extern struct function *g_functions_first, *g_functions_last;
extern struct namespace *g_namespaces_first;
extern char g_mem_insert_action[MAX_NAME_LENGTH*3 + 1024];
extern char *g_label_stack[256], *g_tmp, *g_global_listfile_cmds;
extern char *g_include_in_tmp, *g_tmp_a;
extern char *g_rom_banks, *g_rom_banks_usage_table;
extern char *g_include_dir, *g_buffer, *g_full_name;
extern int g_include_in_tmp_size, g_tmp_a_size, *g_banks, *g_bankaddress;
extern int g_saved_structures_count, g_sizeof_g_tmp, g_global_listfile_items, *g_global_listfile_ints;

int g_output_format = OUTPUT_NONE, g_verbose_level = 0, g_test_mode = OFF;
int g_extra_definitions = OFF, g_commandline_parsing = ON, g_makefile_rules = NO, g_makefile_add_phony_targets = NO;
FILE *g_makefile_rule_file = NULL;
int g_listfile_data = NO, g_quiet = NO, g_use_incdir = NO, g_little_endian = YES;
int g_create_sizeof_definitions = YES, g_global_label_hint = HINT_NONE, g_keep_empty_sections = NO;
int g_can_calculate_a_minus_b = YES, g_is_file_isolated_counter = 0;
int g_continue_parsing_after_an_error = NO, g_continued_parsing_after_an_error = NO;
int g_allow_labels_without_colon = YES;

char *g_final_name = NULL, *g_asm_name = NULL;

struct ext_include_collection g_ext_incdirs;

static struct structure **s_deletable_structures = NULL;
static int s_deletable_structures_max = 0, s_deletable_structures_count = 0;

#if defined(Z80)
extern char *g_sdsctag_name_str, *g_sdsctag_notes_str, *g_sdsctag_author_str;
#endif

#if defined(WIN32)
/* arbitrary, since TMP_MAX can be rather large. */
static char *s_tmpfile_names[256];
static int s_num_tmpfiles = 0;
#endif

PROFILE_GLOBALS();


static int _allocate_global_buffers(void) {

  g_tmp = calloc(g_sizeof_g_tmp, 1);

  if (g_tmp == NULL)
    return FAILED;

  return SUCCEEDED;
}


static void _free_global_buffers(void) {

  free(g_tmp);
}


static int _parse_and_add_definition(char *c, int contains_flag) {

  char n[MAX_NAME_LENGTH + 1], *value;
  int i, k;

  /* skip the flag? */
  if (contains_flag == YES)
    c += 2;
  
  for (i = 0; i < MAX_NAME_LENGTH && *c != 0 && *c != '='; i++, c++)
    n[i] = *c;
  n[i] = 0;

  if (*c == 0)
    return add_a_new_definition(n, 0.0, NULL, DEFINITION_TYPE_VALUE, 0);
  else if (*c == '=') {
    c++;
    if (*c == 0)
      return FAILED;

    value = c;

    /* hexadecimal value? */
    if (*c == '$' || (*c == '0' && (*(c+1) == 'x' || *(c+1) == 'X')) || ((c[strlen(c)-1] == 'h' || c[strlen(c)-1] == 'H') && ((*c >= '0' && *c <= '9') || (*c >= 'a' && *c <= 'f') || (*c >= 'A' && *c <= 'F')))) {
      if (*c == '$')
        c++;
      else if (*c == '0' && (*(c+1) == 'x' || *(c+1) == 'X'))
        c += 2;
      for (i = 0; *c != 0; c++) {
        if (*c >= '0' && *c <= '9')
          i = (i << 4) + *c - '0';
        else if (*c >= 'a' && *c <= 'f')
          i = (i << 4) + *c - 'a' + 10;
        else if (*c >= 'A' && *c <= 'F')
          i = (i << 4) + *c - 'A' + 10;
        else if ((*c == 'h' || *c == 'H') && *(c+1) == 0)
          break;
        else {
          fprintf(stderr, "_PARSE_AND_ADD_DEFINITION: Error in value (%s).\n", value);
          return FAILED;
        }
      }
      return add_a_new_definition(n, (double)i, NULL, DEFINITION_TYPE_VALUE, 0);
    }

    /* binary value? */
    if (*c == '%' || (*c == '0' && (*(c+1) == 'b' || *(c+1) == 'B'))) {
      if (*c == '%')
        c++;
      else
        c += 2;
      for (i = 0, k = 0; *c != 0 && k < 32; k++, c++) {
        if (*c == '0' || *c == '1')
          i = (i << 1) + *c - '0';
        else {
          fprintf(stderr, "_PARSE_AND_ADD_DEFINITION: Error in value (%s).\n", value);
          return FAILED;
        }
      }
      return add_a_new_definition(n, (double)i, NULL, DEFINITION_TYPE_VALUE, 0);
    }
    
    /* decimal value? */
    if (*c >= '0' && *c <= '9') {
      for (i = 0; *c != 0; c++) {
        if (*c >= '0' && *c <= '9')
          i = (i * 10) + *c - '0';
        else {
          fprintf(stderr, "_PARSE_AND_ADD_DEFINITION: Error in value (%s).\n", value);
          return FAILED;
        }
      }
      return add_a_new_definition(n, (double)i, NULL, DEFINITION_TYPE_VALUE, 0);
    }

    /* quoted string? */
    if (*c == '"' && c[strlen(c) - 1] == '"') {
      char *s = calloc(strlen(c) + 1, 1);
      int result, t;

      c++;
      for (t = 0; *c != 0; c++, t++) {
        if (*c == '\\' && *(c + 1) == '"') {
          c++;
          s[t] = '"';
        }
        else if (*c == '"') {
          c++;
          break;
        }
        else
          s[t] = *c;
      }
      s[t] = 0;
      
      if (*c == 0)
        result = add_a_new_definition(n, 0.0, s, DEFINITION_TYPE_STRING, (int)strlen(s));
      else {
        fprintf(stderr, "_PARSE_AND_ADD_DEFINITION: Incorrectly terminated quoted string (%s).\n", value);
        result = FAILED;
      }
      
      free(s);
      return result;
    }

    /* unquoted string */
    return add_a_new_definition(n, 0.0, c, DEFINITION_TYPE_STRING, (int)strlen(c));
  }

  return FAILED;
}


static int _parse_and_add_incdir(char* c, int contains_flag) {

  int old_count = g_ext_incdirs.count, index, buffer_size, j;
  char **new_array;
  char n[MAX_NAME_LENGTH + 1];

  /* increment for the new entry, then re-allocate the array */
  g_ext_incdirs.count++;
  new_array = calloc(g_ext_incdirs.count * sizeof(char*), 1);
  for (index = 0; index < old_count; index++)
    new_array[index] = g_ext_incdirs.names[index];
 
  free(g_ext_incdirs.names);
  g_ext_incdirs.names = new_array;
  buffer_size = g_ext_incdirs.max_name_size_bytes;
  g_ext_incdirs.names[old_count] = calloc(buffer_size, 1);

  /* skip the flag? */
  if (contains_flag == YES)
    c += 2;

  for (j = 0; j < MAX_NAME_LENGTH && *c != 0; j++, c++)
    n[j] = *c;
  n[j] = 0;

  if (*c != 0)
    return FAILED;

  localize_path(n);

#if defined(MSDOS)
  snprintf(g_ext_incdirs.names[old_count], buffer_size, "%s\\", n);
#else
  snprintf(g_ext_incdirs.names[old_count], buffer_size, "%s/", n);
#endif

  g_use_incdir = YES;

  return SUCCEEDED;
}


static int _parse_flags(char **flags, int flagc, int *print_usage) {

  int asm_name_def = 0, count, test_given = NO;
  char *str_build;
  
  for (count = 1; count < flagc; count++) {
    if (!strcmp(flags[count], "-o")) {
      if (g_output_format != OUTPUT_NONE)
        return FAILED;
      g_output_format = OUTPUT_OBJECT;
      if (count + 1 < flagc) {
        /* set output */
        g_final_name = calloc(strlen(flags[count+1])+1, 1);
        strcpy(g_final_name, flags[count+1]);
      }
      else
        return FAILED;

      g_test_mode = OFF;
      count++;
      continue;
    }
    else if (!strcmp(flags[count], "-l")) {
      if (g_output_format != OUTPUT_NONE)
        return FAILED;
      g_output_format = OUTPUT_LIBRARY;
      if (count + 1 < flagc) {
        /* set output */
        g_final_name = calloc(strlen(flags[count+1])+1, 1);
        strcpy(g_final_name, flags[count+1]);
      }
      else
        return FAILED;

      g_test_mode = OFF;
      count++;
      continue;
    }
    else if (!strcmp(flags[count], "-D")) {
      if (count + 1 < flagc) {
        if (count + 3 < flagc) {
          if (!strcmp(flags[count+2], "=")) {
            int length = (int)strlen(flags[count+1])+(int)strlen(flags[count+3])+2;
            str_build = calloc(length, 1);
            snprintf(str_build, length, "%s=%s", flags[count+1], flags[count+3]);
            if (_parse_and_add_definition(str_build, NO) == FAILED) {
              *print_usage = NO;
              free(str_build);
              return FAILED;
            }
            free(str_build);
            count += 2;
          }
          else {
            if (_parse_and_add_definition(flags[count+1], NO) == FAILED) {
              *print_usage = NO;
              return FAILED;
            }
          }
        }
        else {
          if (_parse_and_add_definition(flags[count+1], NO) == FAILED) {
            *print_usage = NO;
            return FAILED;
          }
        }
      }
      else
        return FAILED;

      count++;
      continue;
    }
    else if (!strcmp(flags[count], "-I")) {
      if (count + 1 < flagc) {
        /* get arg */
        _parse_and_add_incdir(flags[count+1], NO);
      }
      else
        return FAILED;

      count++;
      continue;
    }
    else if (!strcmp(flags[count], "-i")) {
      g_listfile_data = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-k")) {
      g_keep_empty_sections = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-v")) {
      g_verbose_level = 100;
      continue;
    }
    else if (!strcmp(flags[count], "-v1")) {
      g_verbose_level = 1;
      continue;
    }
    else if (!strcmp(flags[count], "-v2")) {
      g_verbose_level = 2;
      continue;
    }
    else if (!strcmp(flags[count], "-w")) {
      g_allow_labels_without_colon = NO;
      continue;
    }
    else if (!strcmp(flags[count], "-h")) {
      g_global_label_hint = HINT_16BIT;
      continue;
    }
    else if (!strcmp(flags[count], "-s")) {
      g_create_sizeof_definitions = NO;
      continue;
    }
    else if (!strcmp(flags[count], "-d")) {
      g_can_calculate_a_minus_b = NO;
      continue;
    }
    else if (!strcmp(flags[count], "-t")) {
      g_test_mode = ON;
      test_given = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-M")) {
      g_makefile_rules = YES;
      g_test_mode = ON;
      g_verbose_level = 0;
      g_quiet = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-MP")) {
      g_makefile_add_phony_targets = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-MF")) {
      if (count + 1 < flagc) {
        g_makefile_rule_file = fopen(flags[count+1], "w");
        if (g_makefile_rule_file == NULL)
          return FAILED;
      }
      else
        return FAILED;
      count++;
      continue;
    }
    else if (!strcmp(flags[count], "-q")) {
      g_quiet = YES;
      continue;
    }
    else if (!strcmp(flags[count], "-x")) {
      g_extra_definitions = ON;
      continue;
    }
    else if (!strcmp(flags[count], "-c")) {
      g_continue_parsing_after_an_error = YES;
      continue;
    }
    else {
      if (count == flagc - 1) {
        g_asm_name = calloc(strlen(flags[count]) + 1, 1);
        strcpy(g_asm_name, flags[count]);
        count++;
        asm_name_def++;
      }
      else {
        /* legacy support? */
        if (strncmp(flags[count], "-D", 2) == 0) {
          /* old define */
          if (_parse_and_add_definition(flags[count], YES) == FAILED) {
            *print_usage = NO;
            return FAILED;
          }
          continue;
        }
        else if (strncmp(flags[count], "-I", 2) == 0) {
          /* old include directory */
          _parse_and_add_incdir(flags[count], YES);
          continue;
        }
        else
          return FAILED;
      }
    }
  }

  /* make sure test mode is still turned on! */
  if (test_given == YES)
    g_test_mode = ON;
  
  if (asm_name_def <= 0)
    return FAILED;
  
  return SUCCEEDED;
}


static void _remember_deletable_structure(struct structure *st) {

  int i;

  /* do we already remember the structure? */
  for (i = 0; i < s_deletable_structures_count; i++) {
    if (s_deletable_structures[i] == st)
      return;
  }

  if (s_deletable_structures_count >= s_deletable_structures_max) {
    s_deletable_structures_max += 256;
    s_deletable_structures = realloc(s_deletable_structures, sizeof(struct structure *) * s_deletable_structures_max);
    if (s_deletable_structures == NULL) {
      fprintf(stderr, "_remember_deletable_structure(): Out of memory error.\n");
      return;
    }
  }
  
  s_deletable_structures[s_deletable_structures_count++] = st;
}


static void _mark_struct_deleted(struct structure *st) {

  struct structure_item *si = st->items;

  if (st->alive == NO)
    return;

  st->items = NULL;
  st->alive = NO;
  
  while (si != NULL) {
    struct structure_item *tmp = si;

    if (si->type == STRUCTURE_ITEM_TYPE_UNION)
      _mark_struct_deleted(si->union_items);
    /* don't free si->instance for STRUCTURE_ITEM_TYPE_INSTANCE since that's a reusable
       structure */
    si = si->next;
    free(tmp);
  }

  _remember_deletable_structure(st);
}


static void _procedures_at_exit(void) {

  struct file_name_info *f, *ft;
  struct export_def *export_tmp;
  struct section_def *s1, *s2;
  struct label_def *l1, *l2;
  struct macro_static *m;
  struct filepointer *f1, *f2;
  struct after_section *as;
  struct label_sizeof *ls;
  struct block_name *bn;
  struct array *ar1, *ar2;
  struct string *strings;
  int i, index;
  
  /* free all the dynamically allocated data structures and close open files */
  if (g_file_out_ptr != NULL) {
    fclose(g_file_out_ptr);
    g_file_out_ptr = NULL;
  }

#if defined(WIN32)
  for (i = 0; i < s_num_tmpfiles; i++) {
    if (s_tmpfile_names[i] != NULL) {
      if (s_tmpfile_names[i][0] == '\\')
        remove(&s_tmpfile_names[i][1]);
      else
        remove(s_tmpfile_names[i]);
      
      free(s_tmpfile_names[i]);
      s_tmpfile_names[i] = NULL;
    }
  }

  s_num_tmpfiles = 0;
#endif
  
  free(g_macro_stack);
  free(g_repeat_stack);
  free(g_final_name);
  free(g_asm_name);
  free(g_include_dir);
  free(g_full_name);

  /* NOTE: the implementation of structures leaked memory and the only way i (Ville Helin) was able to
     fix the leak was to collect all allocated structures, and then unroll them here and free them
     all here, finally... if you come up with a better solution, thank you */
  for (i = 0; i < g_saved_structures_count; i++)
    _mark_struct_deleted(g_saved_structures[i]);
  for (i = 0; i < s_deletable_structures_count; i++)
    free(s_deletable_structures[i]);
  free(g_saved_structures);
  free(s_deletable_structures);

  /*
  st = g_structures_first;
  while (st != NULL) {
    struct structure *st2 = st->next;
    _free_struct(st);
    st = st2;
  }
  */

  for (i = 0; i < 256; i++)
    free(g_label_stack[i]);

  /* NOTE! freeing the sections must come before freeing g_defines_map, as section's nspace
     requires that. don't really know why, but Valgrind pointed to that direction, it has
     something to do with section->nspace->label_map... */
  s1 = g_sections_first;
  while (s1 != NULL) {
    free(s1->data);
    free(s1->listfile_cmds);
    free(s1->listfile_ints);
    if (s1->label_map != NULL) {
      hashmap_free(s1->label_map);
      s1->label_map = NULL;
    }
    if (s1->nspace != NULL) {
      if (s1->nspace->label_map != NULL) {
        hashmap_free(s1->nspace->label_map);
        s1->nspace->label_map = NULL;
      }
    }
    s2 = s1->next;
    free(s1);
    s1 = s2;
  }

  if (g_defines_map != NULL) {
    struct definition *e;
    e = hashmap_begin_iteration(g_defines_map);
    while (e != NULL) {
      free(e->alias);
      free(e->string);
      e = hashmap_next_iteration(g_defines_map);
    }
    hashmap_free_all_elements(g_defines_map);
    hashmap_free(g_defines_map);
  }

  if (g_global_unique_label_map != NULL) {
    /* don't free_all_elements, since labels contains _all_ labels. */
    hashmap_free(g_global_unique_label_map);
  }

  if (g_namespace_map != NULL) {
    hashmap_free_all_elements(g_namespace_map);
    hashmap_free(g_namespace_map);
  }

  m = g_macros_first;
  while (m != NULL) {
    /* free the argument labels */
    if (m->nargument_names > 0) {
      for (i = 0; i < m->nargument_names; i++)
        free(m->argument_names[i]);
      free(m->argument_names);
    }
    g_macros_first = m->next;
    free(m);
    m = g_macros_first;
  }

  g_label_tmp = g_labels;
  while (g_label_tmp != NULL) {
    g_labels = g_label_tmp->next;
    free(g_label_tmp);
    g_label_tmp = g_labels;
  }

  l1 = g_unknown_labels;
  while (l1 != NULL) {
    l2 = l1->next;
    free(l1);
    l1 = l2;
  }

  l1 = g_unknown_header_labels;
  while (l1 != NULL) {
    l2 = l1->next;
    free(l1);
    l1 = l2;
  }

  ls = g_label_sizeofs;
  while (ls != NULL) {
    g_label_sizeofs = ls->next;
    free(ls);
    ls = g_label_sizeofs;
  }

  bn = g_block_names;
  while (bn != NULL) {
    g_block_names = bn->next;
    free(bn);
    bn = g_block_names;
  }
  
  export_tmp = g_export_first;
  while (export_tmp != NULL) {
    g_export_last = export_tmp->next;
    free(export_tmp);
    export_tmp = g_export_last;
  }

  g_ifd_tmp = g_incbin_file_data_first;
  while(g_ifd_tmp != NULL) {
    g_incbin_file_data_first = g_ifd_tmp->next;
    free(g_ifd_tmp->data);
    free(g_ifd_tmp->name);
    free(g_ifd_tmp);
    g_ifd_tmp = g_incbin_file_data_first;
  }

  while (g_namespaces_first != NULL) {
    struct namespace *next = g_namespaces_first->next;
    free(g_namespaces_first);
    g_namespaces_first = next;
  }

  free_stack_calculations();

  while (g_functions_first != NULL) {
    struct function *fun = g_functions_first->next;

    for (i = 0; i < g_functions_first->nargument_names; i++)
      free(g_functions_first->argument_names[i]);
    free(g_functions_first);

    g_functions_first = fun;
  }
  
  as = g_after_sections;
  while (as != NULL) {
    g_after_sections = as->next;
    free(as);
    as = g_after_sections;
  }

  strings = g_fopen_filenames_first;
  while (strings != NULL) {
    struct string *strings_next = strings->next;

    free(strings->string);
    free(strings);
    strings = strings_next;
  }
  
  free(g_buffer);
  free(g_include_in_tmp);
  free(g_tmp_a);
  free(g_rom_banks);
  free(g_rom_banks_usage_table);
  free(g_banks);
  free(g_bankaddress);
  free(g_global_listfile_cmds);
  free(g_global_listfile_ints);

  f = g_file_name_info_first;
  while (f != NULL) {
    free(f->name);
    ft = f->next;
    free(f);
    f = ft;
  }

  f1 = g_filepointers;
  while (f1 != NULL) {
    f2 = f1->next;
    if (f1->f != NULL)
      fclose(f1->f);
    free(f1->filename);
    free(f1);
    f1 = f2;
  }

  ar1 = g_arrays_first;
  while (ar1 != NULL) {
    ar2 = ar1->next;
    free(ar1->data);
    free(ar1);
    ar1 = ar2;
  }
  
  while (g_stringmaptables != NULL) {
    struct stringmaptable *sm = g_stringmaptables;
    while (sm->entries != NULL) {
      struct stringmap_entry *e = sm->entries;
      free(e->bytes);
      free(e->text);
      sm->entries = e->next;
      free(e);
    }
    free(sm->filename);
    free(sm->name);
    g_stringmaptables = sm->next;
    free(sm);
  }

  data_stream_parser_free();
  
  /* cleanup any incdirs we added */
  for (index = 0; index < g_ext_incdirs.count; index++)
    free(g_ext_incdirs.names[index]);
  free(g_ext_incdirs.names);

  free_label_context_allocations();
  
  stack_calculate_free_allocations();
  
  _free_global_buffers();
  
#if defined(Z80)
  free(g_sdsctag_name_str);
  free(g_sdsctag_notes_str);
  free(g_sdsctag_author_str);
#endif

  PROFILE_AT_EXIT();
}


static int _generate_extra_definitions(void) {

  char *q, tmp[256];
  time_t ti;
  int i, length;

  /* generate WLA_TIME */
  time(&ti);
  q = ctime(&ti);
  strcpy(tmp, q);
  /* remove the linefeed */
  length = (int)strlen(tmp);
  for (i = 0; i < length; i++) {
    if (tmp[i] == 0x0A) {
      tmp[i] = 0;
      break;
    }
  }
  
  if (add_a_new_definition("WLA_TIME", 0.0, tmp, DEFINITION_TYPE_STRING, (int)strlen(tmp)) == FAILED)
    return FAILED;
  if (add_a_new_definition("wla_time", 0.0, tmp, DEFINITION_TYPE_STRING, (int)strlen(tmp)) == FAILED)
    return FAILED;
  if (add_a_new_definition("WLA_VERSION", 0.0, s_wla_version, DEFINITION_TYPE_STRING, (int)strlen(s_wla_version)) == FAILED)
    return FAILED;
  if (add_a_new_definition("wla_version", 0.0, s_wla_version, DEFINITION_TYPE_STRING, (int)strlen(s_wla_version)) == FAILED)
    return FAILED;

  return SUCCEEDED;
}


/* TODO: put this and all related into its own .c file */
int create_tmp_file(FILE ** file_out_ptr) {

#if defined(WIN32)
  char *tmpfile_buf;
  char *tmpfile_name;

  *file_out_ptr = NULL;

  if (s_num_tmpfiles >= 255) {
    fprintf(stderr, "CREATE_TMP_FILE: Maximum number of tmpfiles (256) reached.\n");
    return FAILED;
  }
  
  /* windows.h MAX_PATH: https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=registry.
     let's not bring in windows.h for a single constant. */
  tmpfile_buf = malloc(260);

  if (tmpfile_buf == NULL) {
    fprintf(stderr, "CREATE_TMP_FILE: Error allocating a temporary filename buffer.\n");
    return FAILED;
  }
  s_tmpfile_names[s_num_tmpfiles] = tmpfile_buf;

  /* tmpfile uses root of drive on Windows, which is probably not-writable. */
  tmpfile_name = tmpnam(s_tmpfile_names[s_num_tmpfiles]);

  if (tmpfile_name == NULL) {
    fprintf(stderr, "CREATE_TMP_FILE: Error creating a tmp filename.\n");
    return FAILED;
  }

  /* per: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam?view=msvc-170&redirectedfrom=MSDN
     when a file name is prepended with a backslash and no path information,
     such as \fname21, it indicates that the name is valid for the current working
     directory. */
  if (tmpfile_name[0] == '\\')
    tmpfile_name = tmpfile_name + 1;

  *file_out_ptr = fopen(tmpfile_name, "wb+");
#else
  *file_out_ptr = tmpfile();
#endif

  if (*file_out_ptr == NULL) {
    fprintf(stderr, "CREATE_TMP_FILE: Error creating a tmp file.\n");
    return FAILED;
  }

#if defined(WIN32)
  s_num_tmpfiles++;
#endif

  return SUCCEEDED;
}


int main(int argc, char *argv[]) {

  int parse_flags_result, print_usage = YES, n_ctr, q, include_size = 0;
  PROFILE_VARIABLES();

  if (sizeof(double) != 8) {
    fprintf(stderr, "MAIN: sizeof(double) == %d != 8. WLA will not work properly.\n", (int)sizeof(double));
    return 1;
  }

  atexit(_procedures_at_exit);

  /* init the randon number generator with current time */
  init_genrand((unsigned long)time(NULL));

  if (_allocate_global_buffers() == FAILED) {
    fprintf(stderr, "MAIN: Out of memory error while allocating global buffers.\n");
    return 1;
  }
  
  /* initialize our external include dir collection */
  g_ext_incdirs.count = 0;
  g_ext_incdirs.names = NULL;
  g_ext_incdirs.max_name_size_bytes = MAX_NAME_LENGTH + 1;

  /* select little/big endianess */
#if defined(MC6800) || defined(MC6801) || defined(MC6809) || defined(MC68000) || defined(K053248)
  g_little_endian = NO;
#else
  g_little_endian = YES;
#endif

  /* init mem_insert() buffer */
  g_mem_insert_action[0] = 0;
  
  /* init hashmaps */
  g_defines_map = hashmap_new();
  g_global_unique_label_map = hashmap_new();
  g_namespace_map = hashmap_new();

  /* init label stack */
  for (q = 0; q < 256; q++)
    g_label_stack[q] = NULL;
  for (q = 0; q < 256; q++) {
    g_label_stack[q] = calloc(MAX_NAME_LENGTH + 1, 1);
    if (g_label_stack[q] == NULL)
      return 1;
  }

  /* default to output makefile rules to the standard output */
  g_makefile_rule_file = stdout;

  parse_flags_result = FAILED;
  if (argc >= 2) {
    parse_flags_result = _parse_flags(argv, argc, &print_usage);

    if (parse_flags_result == FAILED && print_usage == NO)
      return 1;
    
    if (g_output_format == OUTPUT_NONE) {
      if (parse_flags_result == SUCCEEDED) {
        /* assume object file output name */
        g_output_format = OUTPUT_OBJECT;
        g_final_name = calloc(strlen(g_asm_name)+1, 1);
        for (n_ctr = 0; n_ctr < (int)strlen(g_asm_name) && *((g_asm_name) + n_ctr) != '.'; n_ctr++)
          g_final_name[n_ctr] = *((g_asm_name) + n_ctr);
        g_final_name[n_ctr++] = '.';
        g_final_name[n_ctr++] = 'o';
        g_final_name[n_ctr] = 0;
      }
    }
  }

  if (g_output_format == OUTPUT_NONE || parse_flags_result == FAILED) {
    char title[] = "WLA " ARCH_STR " Macro Assembler v10.6a";
    int length, left, right;

    length = (int)strlen(title);
    left = (70 - 3 - 3 - length) / 2;
    right = 70 - 3 - 3 - left - length;

    printf("----------------------------------------------------------------------\n");
    printf("---");
    for (q = 0; q < left; q++)
      printf(" ");
    printf("%s", title);
    for (q = 0; q < right; q++)
      printf(" ");
    printf("---\n");
    printf("----------------------------------------------------------------------\n");
#if defined(AMIGACPU)
    printf("                         Compiled for " AMIGACPU "\n");
#endif
    printf("                Programmed by Ville Helin in 1998-2008\n");
    printf("        In GitHub since 2014: https://github.com/vhelin/wla-dx\n");

    length = (int)strlen(s_version_string);
    left = (70 - length) / 2;

    for (q = 0; q < left; q++)
      printf(" ");
    printf("%s", s_version_string);
    
    printf("\n\n");

#if defined(WLA_DEBUG)
    printf("***  WLA_DEBUG defined - this executable is running in DEBUG mode  ***\n");
    printf("\n");
#endif

    printf("USAGE: %s [OPTIONS] <OUTPUT> <ASM FILE>\n\n", argv[0]);
    printf("OPTIONS:\n");
    printf("-c  Continue parsing after an error\n");
    printf("-d  Disable WLA's ability to calculate A-B where A and B are labels\n");
    printf("-h  Assume all label references are 16-bit by default (size hints\n");
    printf("    still work)\n");
    printf("-i  Add list file information\n");
    printf("-k  Keep empty sections\n");
    printf("-M  Output makefile rules\n");
    printf("-MP Create a phony target for each dependency other than the main file,\n");
    printf("    use this with -M\n");
    printf("-MF <FILE> Specify a file to write the dependencies to, use with -M\n");
    printf("-q  Quiet\n");
    printf("-s  Don't create _sizeof_* and _paddingof_* definitions\n");
    printf("-t  Test assemble\n");
    printf("-v  Verbose messages\n");
    printf("-v1 Verbose messages (only discard sections)\n");
    printf("-v2 Verbose messages (-v1 plus short summary)\n");
    printf("-w  Require labels to end in a colon\n");
    printf("-x  Extra compile time labels and definitions\n");
    printf("-I <DIR>  Include directory\n");
    printf("-D <DEF>  Declare definition\n\n");
    printf("OUTPUT:\n");
    printf("-o <FILE>  Output object file\n");
    printf("-l <FILE>  Output library file\n\n");
    printf("EXAMPLES:\n");
    printf("%s -M -t -o main.o main.asm\n", argv[0]);
    printf("%s -D VER=1 -D TWO=2 -v -o main.o main.asm\n\n", argv[0]);
    return 0;
  }

  if (strcmp(g_asm_name, g_final_name) == 0) {
    fprintf(stderr, "MAIN: Input and output files share the same name!\n");
    return 1;
  }

  if (create_tmp_file(&g_file_out_ptr) == FAILED)
    return 1;

  /* small inits */
  if (g_extra_definitions == ON)
    _generate_extra_definitions();

  g_commandline_parsing = OFF;

  /* start the process */
  if (include_file(g_asm_name, &include_size, NULL) == FAILED)
    return 1;

  PROFILE_START();  
  if (phase_1() == FAILED)
    return 1;
  PROFILE_END("phase_1");

  PROFILE_START();
    if (phase_2() == FAILED)
    return 1;
  PROFILE_END("phase_2");

  PROFILE_START();
  if (phase_3() == FAILED)
    return 1;
  PROFILE_END("phase_3");

  if (g_listfile_data == YES) {
    if (listfile_collect() == FAILED)
      return 1;
  }

  PROFILE_START();
  if (phase_4() == FAILED)
    return 1;
  PROFILE_END("phase_4");
  
  return 0;
}
