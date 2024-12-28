#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 289
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 103
#define ALIAS_COUNT 0
#define TOKEN_COUNT 44
#define EXTERNAL_TOKEN_COUNT 7
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_identifier = 1,
  sym_string_literal = 2,
  anon_sym_standard = 3,
  anon_sym_library = 4,
  anon_sym_package = 5,
  anon_sym_SEMI = 6,
  anon_sym_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_public = 9,
  anon_sym_private = 10,
  anon_sym_protected = 11,
  anon_sym_dependency = 12,
  anon_sym_from = 13,
  anon_sym_to = 14,
  anon_sym_COLON_COLON = 15,
  anon_sym_STAR = 16,
  anon_sym_TODO = 17,
  anon_sym_import = 18,
  anon_sym_all = 19,
  anon_sym_occurrence = 20,
  sym_attribute_keyword = 21,
  anon_sym_ref = 22,
  anon_sym_LT = 23,
  anon_sym_GT = 24,
  sym_prefix_metadata_annotation = 25,
  anon_sym_COMMA = 26,
  anon_sym_DOT = 27,
  anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT = 28,
  anon_sym_abstract = 29,
  anon_sym_variation = 30,
  anon_sym_specializes = 31,
  anon_sym_COLON_GT = 32,
  sym_attribute_def_keyword = 33,
  anon_sym_comment = 34,
  sym_comment = 35,
  anon_sym_doc = 36,
  anon_sym_locale = 37,
  anon_sym_DQUOTE = 38,
  sym__newline = 39,
  sym__backslash = 40,
  sym__nl_comma = 41,
  sym_float = 42,
  sym_block_comment = 43,
  sym_source_file = 44,
  sym_root_namespace = 45,
  sym_package = 46,
  sym_library_package = 47,
  sym_package_declaration = 48,
  sym_package_body = 49,
  sym_package_member = 50,
  sym_member_prefix = 51,
  sym_definition_element = 52,
  sym_dependency = 53,
  sym_import_stmt = 54,
  sym_membership_import = 55,
  sym_imported_membership = 56,
  sym_imported_namespace = 57,
  sym_membership = 58,
  sym_alias_member = 59,
  sym_initial_node_member = 60,
  sym_transition_source_member = 61,
  sym_namespace_import = 62,
  sym_import_prefix = 63,
  sym_visibility = 64,
  sym_usage_element = 65,
  sym_non_occurrence_usage_element = 66,
  sym_occurrence_usage_element = 67,
  sym_attribute_usage = 68,
  sym_attribute_usage_keyword = 69,
  sym_usage_prefix = 70,
  sym_basic_usage_prefix = 71,
  sym_usage = 72,
  sym_usage_declaration = 73,
  sym_usage_completion = 74,
  sym_identification = 75,
  sym_qualified_name_list = 76,
  sym_relationship_body = 77,
  sym_qualified_name = 78,
  sym_usage_body = 79,
  sym_annotating_element = 80,
  sym_attribute_definition = 81,
  sym_basic_definition_prefix = 82,
  sym_definition_prefix = 83,
  sym_definition = 84,
  sym_definition_declaration = 85,
  sym_definition_body = 86,
  sym_definition_member = 87,
  sym_subclassification_part = 88,
  sym_specializes_keyword = 89,
  sym_owned_subclassification = 90,
  sym_owned_annotation = 91,
  sym_regular_comment = 92,
  sym_documentation = 93,
  aux_sym_source_file_repeat1 = 94,
  aux_sym_package_body_repeat1 = 95,
  aux_sym_dependency_repeat1 = 96,
  aux_sym_imported_membership_repeat1 = 97,
  aux_sym_qualified_name_list_repeat1 = 98,
  aux_sym_relationship_body_repeat1 = 99,
  aux_sym_qualified_name_repeat1 = 100,
  aux_sym_definition_body_repeat1 = 101,
  aux_sym_subclassification_part_repeat1 = 102,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_string_literal] = "string_literal",
  [anon_sym_standard] = "standard",
  [anon_sym_library] = "library",
  [anon_sym_package] = "package",
  [anon_sym_SEMI] = ";",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_public] = "public",
  [anon_sym_private] = "private",
  [anon_sym_protected] = "protected",
  [anon_sym_dependency] = "dependency",
  [anon_sym_from] = "from",
  [anon_sym_to] = "to",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_STAR] = "*",
  [anon_sym_TODO] = "TODO",
  [anon_sym_import] = "import",
  [anon_sym_all] = "all",
  [anon_sym_occurrence] = "occurrence",
  [sym_attribute_keyword] = "attribute_keyword",
  [anon_sym_ref] = "ref",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [sym_prefix_metadata_annotation] = "prefix_metadata_annotation",
  [anon_sym_COMMA] = ",",
  [anon_sym_DOT] = ".",
  [anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT] = "...TODO...",
  [anon_sym_abstract] = "abstract",
  [anon_sym_variation] = "variation",
  [anon_sym_specializes] = "specializes",
  [anon_sym_COLON_GT] = ":>",
  [sym_attribute_def_keyword] = "attribute_def_keyword",
  [anon_sym_comment] = "comment",
  [sym_comment] = "comment",
  [anon_sym_doc] = "doc",
  [anon_sym_locale] = "locale",
  [anon_sym_DQUOTE] = "\"",
  [sym__newline] = "_newline",
  [sym__backslash] = "_backslash",
  [sym__nl_comma] = "_nl_comma",
  [sym_float] = "float",
  [sym_block_comment] = "block_comment",
  [sym_source_file] = "source_file",
  [sym_root_namespace] = "root_namespace",
  [sym_package] = "package",
  [sym_library_package] = "library_package",
  [sym_package_declaration] = "package_declaration",
  [sym_package_body] = "package_body",
  [sym_package_member] = "package_member",
  [sym_member_prefix] = "member_prefix",
  [sym_definition_element] = "definition_element",
  [sym_dependency] = "dependency",
  [sym_import_stmt] = "import_stmt",
  [sym_membership_import] = "membership_import",
  [sym_imported_membership] = "imported_membership",
  [sym_imported_namespace] = "imported_namespace",
  [sym_membership] = "membership",
  [sym_alias_member] = "alias_member",
  [sym_initial_node_member] = "initial_node_member",
  [sym_transition_source_member] = "transition_source_member",
  [sym_namespace_import] = "namespace_import",
  [sym_import_prefix] = "import_prefix",
  [sym_visibility] = "visibility",
  [sym_usage_element] = "usage_element",
  [sym_non_occurrence_usage_element] = "non_occurrence_usage_element",
  [sym_occurrence_usage_element] = "occurrence_usage_element",
  [sym_attribute_usage] = "attribute_usage",
  [sym_attribute_usage_keyword] = "attribute_usage_keyword",
  [sym_usage_prefix] = "usage_prefix",
  [sym_basic_usage_prefix] = "basic_usage_prefix",
  [sym_usage] = "usage",
  [sym_usage_declaration] = "usage_declaration",
  [sym_usage_completion] = "usage_completion",
  [sym_identification] = "identification",
  [sym_qualified_name_list] = "qualified_name_list",
  [sym_relationship_body] = "relationship_body",
  [sym_qualified_name] = "qualified_name",
  [sym_usage_body] = "usage_body",
  [sym_annotating_element] = "annotating_element",
  [sym_attribute_definition] = "attribute_definition",
  [sym_basic_definition_prefix] = "basic_definition_prefix",
  [sym_definition_prefix] = "definition_prefix",
  [sym_definition] = "definition",
  [sym_definition_declaration] = "definition_declaration",
  [sym_definition_body] = "definition_body",
  [sym_definition_member] = "definition_member",
  [sym_subclassification_part] = "subclassification_part",
  [sym_specializes_keyword] = "specializes_keyword",
  [sym_owned_subclassification] = "owned_subclassification",
  [sym_owned_annotation] = "owned_annotation",
  [sym_regular_comment] = "regular_comment",
  [sym_documentation] = "documentation",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_package_body_repeat1] = "package_body_repeat1",
  [aux_sym_dependency_repeat1] = "dependency_repeat1",
  [aux_sym_imported_membership_repeat1] = "imported_membership_repeat1",
  [aux_sym_qualified_name_list_repeat1] = "qualified_name_list_repeat1",
  [aux_sym_relationship_body_repeat1] = "relationship_body_repeat1",
  [aux_sym_qualified_name_repeat1] = "qualified_name_repeat1",
  [aux_sym_definition_body_repeat1] = "definition_body_repeat1",
  [aux_sym_subclassification_part_repeat1] = "subclassification_part_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_string_literal] = sym_string_literal,
  [anon_sym_standard] = anon_sym_standard,
  [anon_sym_library] = anon_sym_library,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_public] = anon_sym_public,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_protected] = anon_sym_protected,
  [anon_sym_dependency] = anon_sym_dependency,
  [anon_sym_from] = anon_sym_from,
  [anon_sym_to] = anon_sym_to,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_TODO] = anon_sym_TODO,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_all] = anon_sym_all,
  [anon_sym_occurrence] = anon_sym_occurrence,
  [sym_attribute_keyword] = sym_attribute_keyword,
  [anon_sym_ref] = anon_sym_ref,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [sym_prefix_metadata_annotation] = sym_prefix_metadata_annotation,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT] = anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT,
  [anon_sym_abstract] = anon_sym_abstract,
  [anon_sym_variation] = anon_sym_variation,
  [anon_sym_specializes] = anon_sym_specializes,
  [anon_sym_COLON_GT] = anon_sym_COLON_GT,
  [sym_attribute_def_keyword] = sym_attribute_def_keyword,
  [anon_sym_comment] = anon_sym_comment,
  [sym_comment] = sym_comment,
  [anon_sym_doc] = anon_sym_doc,
  [anon_sym_locale] = anon_sym_locale,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym__newline] = sym__newline,
  [sym__backslash] = sym__backslash,
  [sym__nl_comma] = sym__nl_comma,
  [sym_float] = sym_float,
  [sym_block_comment] = sym_block_comment,
  [sym_source_file] = sym_source_file,
  [sym_root_namespace] = sym_root_namespace,
  [sym_package] = sym_package,
  [sym_library_package] = sym_library_package,
  [sym_package_declaration] = sym_package_declaration,
  [sym_package_body] = sym_package_body,
  [sym_package_member] = sym_package_member,
  [sym_member_prefix] = sym_member_prefix,
  [sym_definition_element] = sym_definition_element,
  [sym_dependency] = sym_dependency,
  [sym_import_stmt] = sym_import_stmt,
  [sym_membership_import] = sym_membership_import,
  [sym_imported_membership] = sym_imported_membership,
  [sym_imported_namespace] = sym_imported_namespace,
  [sym_membership] = sym_membership,
  [sym_alias_member] = sym_alias_member,
  [sym_initial_node_member] = sym_initial_node_member,
  [sym_transition_source_member] = sym_transition_source_member,
  [sym_namespace_import] = sym_namespace_import,
  [sym_import_prefix] = sym_import_prefix,
  [sym_visibility] = sym_visibility,
  [sym_usage_element] = sym_usage_element,
  [sym_non_occurrence_usage_element] = sym_non_occurrence_usage_element,
  [sym_occurrence_usage_element] = sym_occurrence_usage_element,
  [sym_attribute_usage] = sym_attribute_usage,
  [sym_attribute_usage_keyword] = sym_attribute_usage_keyword,
  [sym_usage_prefix] = sym_usage_prefix,
  [sym_basic_usage_prefix] = sym_basic_usage_prefix,
  [sym_usage] = sym_usage,
  [sym_usage_declaration] = sym_usage_declaration,
  [sym_usage_completion] = sym_usage_completion,
  [sym_identification] = sym_identification,
  [sym_qualified_name_list] = sym_qualified_name_list,
  [sym_relationship_body] = sym_relationship_body,
  [sym_qualified_name] = sym_qualified_name,
  [sym_usage_body] = sym_usage_body,
  [sym_annotating_element] = sym_annotating_element,
  [sym_attribute_definition] = sym_attribute_definition,
  [sym_basic_definition_prefix] = sym_basic_definition_prefix,
  [sym_definition_prefix] = sym_definition_prefix,
  [sym_definition] = sym_definition,
  [sym_definition_declaration] = sym_definition_declaration,
  [sym_definition_body] = sym_definition_body,
  [sym_definition_member] = sym_definition_member,
  [sym_subclassification_part] = sym_subclassification_part,
  [sym_specializes_keyword] = sym_specializes_keyword,
  [sym_owned_subclassification] = sym_owned_subclassification,
  [sym_owned_annotation] = sym_owned_annotation,
  [sym_regular_comment] = sym_regular_comment,
  [sym_documentation] = sym_documentation,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_package_body_repeat1] = aux_sym_package_body_repeat1,
  [aux_sym_dependency_repeat1] = aux_sym_dependency_repeat1,
  [aux_sym_imported_membership_repeat1] = aux_sym_imported_membership_repeat1,
  [aux_sym_qualified_name_list_repeat1] = aux_sym_qualified_name_list_repeat1,
  [aux_sym_relationship_body_repeat1] = aux_sym_relationship_body_repeat1,
  [aux_sym_qualified_name_repeat1] = aux_sym_qualified_name_repeat1,
  [aux_sym_definition_body_repeat1] = aux_sym_definition_body_repeat1,
  [aux_sym_subclassification_part_repeat1] = aux_sym_subclassification_part_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_standard] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_library] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_public] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_private] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_protected] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dependency] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_from] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_to] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TODO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_all] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_occurrence] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_keyword] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_ref] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_prefix_metadata_annotation] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_abstract] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_variation] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_specializes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_def_keyword] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_comment] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_doc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_locale] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__backslash] = {
    .visible = false,
    .named = true,
  },
  [sym__nl_comma] = {
    .visible = false,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_root_namespace] = {
    .visible = true,
    .named = true,
  },
  [sym_package] = {
    .visible = true,
    .named = true,
  },
  [sym_library_package] = {
    .visible = true,
    .named = true,
  },
  [sym_package_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_package_body] = {
    .visible = true,
    .named = true,
  },
  [sym_package_member] = {
    .visible = true,
    .named = true,
  },
  [sym_member_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_definition_element] = {
    .visible = true,
    .named = true,
  },
  [sym_dependency] = {
    .visible = true,
    .named = true,
  },
  [sym_import_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_membership_import] = {
    .visible = true,
    .named = true,
  },
  [sym_imported_membership] = {
    .visible = true,
    .named = true,
  },
  [sym_imported_namespace] = {
    .visible = true,
    .named = true,
  },
  [sym_membership] = {
    .visible = true,
    .named = true,
  },
  [sym_alias_member] = {
    .visible = true,
    .named = true,
  },
  [sym_initial_node_member] = {
    .visible = true,
    .named = true,
  },
  [sym_transition_source_member] = {
    .visible = true,
    .named = true,
  },
  [sym_namespace_import] = {
    .visible = true,
    .named = true,
  },
  [sym_import_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_visibility] = {
    .visible = true,
    .named = true,
  },
  [sym_usage_element] = {
    .visible = true,
    .named = true,
  },
  [sym_non_occurrence_usage_element] = {
    .visible = true,
    .named = true,
  },
  [sym_occurrence_usage_element] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_usage_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_usage_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_basic_usage_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_usage_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_usage_completion] = {
    .visible = true,
    .named = true,
  },
  [sym_identification] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_name_list] = {
    .visible = true,
    .named = true,
  },
  [sym_relationship_body] = {
    .visible = true,
    .named = true,
  },
  [sym_qualified_name] = {
    .visible = true,
    .named = true,
  },
  [sym_usage_body] = {
    .visible = true,
    .named = true,
  },
  [sym_annotating_element] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_basic_definition_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_definition_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_definition_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_definition_body] = {
    .visible = true,
    .named = true,
  },
  [sym_definition_member] = {
    .visible = true,
    .named = true,
  },
  [sym_subclassification_part] = {
    .visible = true,
    .named = true,
  },
  [sym_specializes_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_owned_subclassification] = {
    .visible = true,
    .named = true,
  },
  [sym_owned_annotation] = {
    .visible = true,
    .named = true,
  },
  [sym_regular_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_documentation] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_package_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dependency_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_imported_membership_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_qualified_name_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_relationship_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_qualified_name_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_definition_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_subclassification_part_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_clients = 1,
  field_suppliers = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_clients] = "clients",
  [field_suppliers] = "suppliers",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 2},
  [4] = {.index = 6, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_clients, 1},
    {field_suppliers, 3},
  [2] =
    {field_clients, 2},
    {field_suppliers, 4},
  [4] =
    {field_clients, 3},
    {field_suppliers, 5},
  [6] =
    {field_clients, 4},
    {field_suppliers, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 23,
  [47] = 32,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 53,
  [55] = 52,
  [56] = 56,
  [57] = 57,
  [58] = 57,
  [59] = 6,
  [60] = 60,
  [61] = 14,
  [62] = 62,
  [63] = 45,
  [64] = 60,
  [65] = 8,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 41,
  [75] = 75,
  [76] = 42,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 43,
  [82] = 82,
  [83] = 44,
  [84] = 84,
  [85] = 85,
  [86] = 30,
  [87] = 12,
  [88] = 13,
  [89] = 75,
  [90] = 90,
  [91] = 73,
  [92] = 18,
  [93] = 20,
  [94] = 21,
  [95] = 22,
  [96] = 24,
  [97] = 25,
  [98] = 26,
  [99] = 9,
  [100] = 48,
  [101] = 33,
  [102] = 34,
  [103] = 36,
  [104] = 39,
  [105] = 40,
  [106] = 20,
  [107] = 41,
  [108] = 26,
  [109] = 42,
  [110] = 34,
  [111] = 43,
  [112] = 44,
  [113] = 113,
  [114] = 73,
  [115] = 75,
  [116] = 17,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 84,
  [121] = 85,
  [122] = 122,
  [123] = 123,
  [124] = 6,
  [125] = 8,
  [126] = 119,
  [127] = 118,
  [128] = 90,
  [129] = 129,
  [130] = 45,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 39,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 140,
  [144] = 144,
  [145] = 142,
  [146] = 146,
  [147] = 117,
  [148] = 132,
  [149] = 149,
  [150] = 142,
  [151] = 132,
  [152] = 138,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 135,
  [176] = 176,
  [177] = 173,
  [178] = 156,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 131,
  [183] = 159,
  [184] = 155,
  [185] = 163,
  [186] = 181,
  [187] = 187,
  [188] = 169,
  [189] = 189,
  [190] = 8,
  [191] = 191,
  [192] = 141,
  [193] = 173,
  [194] = 191,
  [195] = 156,
  [196] = 163,
  [197] = 169,
  [198] = 189,
  [199] = 174,
  [200] = 155,
  [201] = 189,
  [202] = 191,
  [203] = 174,
  [204] = 164,
  [205] = 172,
  [206] = 187,
  [207] = 207,
  [208] = 158,
  [209] = 164,
  [210] = 172,
  [211] = 187,
  [212] = 158,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 149,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 218,
  [222] = 222,
  [223] = 8,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 165,
  [228] = 224,
  [229] = 229,
  [230] = 40,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 234,
  [236] = 236,
  [237] = 237,
  [238] = 238,
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 240,
  [245] = 245,
  [246] = 238,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 238,
  [251] = 238,
  [252] = 238,
  [253] = 253,
  [254] = 236,
  [255] = 255,
  [256] = 256,
  [257] = 8,
  [258] = 241,
  [259] = 176,
  [260] = 245,
  [261] = 261,
  [262] = 253,
  [263] = 238,
  [264] = 253,
  [265] = 253,
  [266] = 253,
  [267] = 267,
  [268] = 256,
  [269] = 269,
  [270] = 236,
  [271] = 255,
  [272] = 241,
  [273] = 232,
  [274] = 261,
  [275] = 256,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 247,
  [280] = 269,
  [281] = 253,
  [282] = 249,
  [283] = 167,
  [284] = 168,
  [285] = 171,
  [286] = 247,
  [287] = 249,
  [288] = 261,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(132);
      ADVANCE_MAP(
        '"', 274,
        '#', 254,
        '*', 240,
        ',', 255,
        '.', 257,
        '/', 15,
        ':', 17,
        ';', 225,
        '<', 252,
        '>', 253,
        'T', 21,
        'a', 37,
        'c', 98,
        'd', 56,
        'f', 111,
        'i', 87,
        'l', 74,
        'o', 47,
        'p', 31,
        'r', 57,
        's', 102,
        't', 97,
        'v', 28,
        '{', 226,
        '}', 227,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 2,
        '#', 254,
        ',', 255,
        '.', 256,
        '/', 15,
        ':', 16,
        ';', 225,
        '<', 252,
        'a', 144,
        'd', 159,
        'i', 187,
        'l', 194,
        'o', 152,
        'p', 140,
        'r', 160,
        'v', 136,
        '{', 226,
        '}', 227,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(220);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(240);
      if (lookahead == '.') ADVANCE(5);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == 'T') ADVANCE(134);
      if (lookahead == 'p') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 4:
      if (lookahead == ',') ADVANCE(255);
      if (lookahead == '.') ADVANCE(256);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 't') ADVANCE(97);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      END_STATE();
    case 5:
      if (lookahead == '.') ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(258);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(7);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == ':') ADVANCE(18);
      if (lookahead == ';') ADVANCE(225);
      if (lookahead == 's') ADVANCE(198);
      if (lookahead == '{') ADVANCE(226);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == ';') ADVANCE(225);
      if (lookahead == '<') ADVANCE(252);
      if (lookahead == '{') ADVANCE(226);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '<') ADVANCE(252);
      if (lookahead == 'T') ADVANCE(134);
      if (lookahead == 'i') ADVANCE(187);
      if (lookahead == 'p') ADVANCE(199);
      if (lookahead == '}') ADVANCE(227);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '<') ADVANCE(252);
      if (lookahead == 'f') ADVANCE(202);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 14:
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == 'T') ADVANCE(134);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead == 'p') ADVANCE(199);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 15:
      if (lookahead == '/') ADVANCE(269);
      END_STATE();
    case 16:
      if (lookahead == ':') ADVANCE(239);
      END_STATE();
    case 17:
      if (lookahead == ':') ADVANCE(239);
      if (lookahead == '>') ADVANCE(265);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(265);
      END_STATE();
    case 19:
      if (lookahead == 'D') ADVANCE(22);
      END_STATE();
    case 20:
      if (lookahead == 'D') ADVANCE(23);
      END_STATE();
    case 21:
      if (lookahead == 'O') ADVANCE(19);
      END_STATE();
    case 22:
      if (lookahead == 'O') ADVANCE(241);
      END_STATE();
    case 23:
      if (lookahead == 'O') ADVANCE(9);
      END_STATE();
    case 24:
      if (lookahead == 'O') ADVANCE(20);
      END_STATE();
    case 25:
      if (lookahead == 'T') ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(73);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(122);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(43);
      if (lookahead == 'r') ADVANCE(75);
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(120);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(105);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(48);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(108);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(86);
      END_STATE();
    case 37:
      if (lookahead == 'b') ADVANCE(115);
      if (lookahead == 'l') ADVANCE(83);
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 38:
      if (lookahead == 'b') ADVANCE(84);
      END_STATE();
    case 39:
      if (lookahead == 'b') ADVANCE(127);
      END_STATE();
    case 40:
      if (lookahead == 'b') ADVANCE(112);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(270);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(126);
      END_STATE();
    case 43:
      if (lookahead == 'c') ADVANCE(82);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(228);
      END_STATE();
    case 45:
      if (lookahead == 'c') ADVANCE(130);
      END_STATE();
    case 46:
      if (lookahead == 'c') ADVANCE(29);
      END_STATE();
    case 47:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 48:
      if (lookahead == 'c') ADVANCE(118);
      END_STATE();
    case 49:
      if (lookahead == 'c') ADVANCE(62);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(81);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(123);
      END_STATE();
    case 52:
      if (lookahead == 'd') ADVANCE(221);
      END_STATE();
    case 53:
      if (lookahead == 'd') ADVANCE(232);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(65);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(35);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(71);
      if (lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(272);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(230);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(249);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(247);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(95);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 71:
      if (lookahead == 'f') ADVANCE(266);
      if (lookahead == 'p') ADVANCE(69);
      END_STATE();
    case 72:
      if (lookahead == 'f') ADVANCE(250);
      END_STATE();
    case 73:
      if (lookahead == 'g') ADVANCE(59);
      END_STATE();
    case 74:
      if (lookahead == 'i') ADVANCE(40);
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 75:
      if (lookahead == 'i') ADVANCE(128);
      if (lookahead == 'o') ADVANCE(125);
      END_STATE();
    case 76:
      if (lookahead == 'i') ADVANCE(131);
      END_STATE();
    case 77:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 78:
      if (lookahead == 'i') ADVANCE(100);
      END_STATE();
    case 79:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(36);
      END_STATE();
    case 82:
      if (lookahead == 'k') ADVANCE(27);
      END_STATE();
    case 83:
      if (lookahead == 'l') ADVANCE(245);
      END_STATE();
    case 84:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 85:
      if (lookahead == 'l') ADVANCE(58);
      END_STATE();
    case 86:
      if (lookahead == 'l') ADVANCE(76);
      END_STATE();
    case 87:
      if (lookahead == 'm') ADVANCE(103);
      END_STATE();
    case 88:
      if (lookahead == 'm') ADVANCE(236);
      END_STATE();
    case 89:
      if (lookahead == 'm') ADVANCE(90);
      END_STATE();
    case 90:
      if (lookahead == 'm') ADVANCE(64);
      END_STATE();
    case 91:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 92:
      if (lookahead == 'n') ADVANCE(261);
      END_STATE();
    case 93:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 94:
      if (lookahead == 'n') ADVANCE(117);
      END_STATE();
    case 95:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 96:
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 97:
      if (lookahead == 'o') ADVANCE(238);
      END_STATE();
    case 98:
      if (lookahead == 'o') ADVANCE(89);
      END_STATE();
    case 99:
      if (lookahead == 'o') ADVANCE(88);
      END_STATE();
    case 100:
      if (lookahead == 'o') ADVANCE(92);
      END_STATE();
    case 101:
      if (lookahead == 'o') ADVANCE(107);
      END_STATE();
    case 102:
      if (lookahead == 'p') ADVANCE(67);
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 103:
      if (lookahead == 'p') ADVANCE(101);
      END_STATE();
    case 104:
      if (lookahead == 'r') ADVANCE(79);
      END_STATE();
    case 105:
      if (lookahead == 'r') ADVANCE(129);
      END_STATE();
    case 106:
      if (lookahead == 'r') ADVANCE(77);
      END_STATE();
    case 107:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 108:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 109:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 110:
      if (lookahead == 'r') ADVANCE(113);
      END_STATE();
    case 111:
      if (lookahead == 'r') ADVANCE(99);
      END_STATE();
    case 112:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 113:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 114:
      if (lookahead == 's') ADVANCE(263);
      END_STATE();
    case 115:
      if (lookahead == 's') ADVANCE(121);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(243);
      END_STATE();
    case 117:
      if (lookahead == 't') ADVANCE(268);
      END_STATE();
    case 118:
      if (lookahead == 't') ADVANCE(259);
      END_STATE();
    case 119:
      if (lookahead == 't') ADVANCE(106);
      END_STATE();
    case 120:
      if (lookahead == 't') ADVANCE(78);
      END_STATE();
    case 121:
      if (lookahead == 't') ADVANCE(109);
      END_STATE();
    case 122:
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 123:
      if (lookahead == 't') ADVANCE(66);
      END_STATE();
    case 124:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 126:
      if (lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 127:
      if (lookahead == 'u') ADVANCE(124);
      END_STATE();
    case 128:
      if (lookahead == 'v') ADVANCE(30);
      END_STATE();
    case 129:
      if (lookahead == 'y') ADVANCE(222);
      END_STATE();
    case 130:
      if (lookahead == 'y') ADVANCE(234);
      END_STATE();
    case 131:
      if (lookahead == 'z') ADVANCE(63);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'O') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(148);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead == 'u') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(267);
      if (lookahead == 'p') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(216);
      if (lookahead == 'o') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead == 'u') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'z') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'y')) ADVANCE(219);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_string_literal);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_standard);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_library);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_package);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_public);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_public);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_private);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_protected);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_protected);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_dependency);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_dependency);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_from);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_from);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_to);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_TODO);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_TODO);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_import);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_all);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_all);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_occurrence);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_occurrence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_attribute_keyword);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_ref);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_prefix_metadata_annotation);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(6);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_abstract);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_abstract);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_variation);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_variation);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_specializes);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_specializes);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_COLON_GT);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_attribute_def_keyword);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_attribute_def_keyword);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_comment);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(269);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_doc);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_doc);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_locale);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_locale);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(219);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0, .external_lex_state = 2},
  [6] = {.lex_state = 1, .external_lex_state = 2},
  [7] = {.lex_state = 0, .external_lex_state = 2},
  [8] = {.lex_state = 1, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 2},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 0, .external_lex_state = 2},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0, .external_lex_state = 2},
  [16] = {.lex_state = 0, .external_lex_state = 2},
  [17] = {.lex_state = 0, .external_lex_state = 2},
  [18] = {.lex_state = 0, .external_lex_state = 2},
  [19] = {.lex_state = 0, .external_lex_state = 2},
  [20] = {.lex_state = 0, .external_lex_state = 2},
  [21] = {.lex_state = 0, .external_lex_state = 2},
  [22] = {.lex_state = 0, .external_lex_state = 2},
  [23] = {.lex_state = 0, .external_lex_state = 2},
  [24] = {.lex_state = 0, .external_lex_state = 2},
  [25] = {.lex_state = 0, .external_lex_state = 2},
  [26] = {.lex_state = 0, .external_lex_state = 2},
  [27] = {.lex_state = 0, .external_lex_state = 2},
  [28] = {.lex_state = 0, .external_lex_state = 2},
  [29] = {.lex_state = 0, .external_lex_state = 2},
  [30] = {.lex_state = 0, .external_lex_state = 2},
  [31] = {.lex_state = 0, .external_lex_state = 2},
  [32] = {.lex_state = 0, .external_lex_state = 2},
  [33] = {.lex_state = 0, .external_lex_state = 2},
  [34] = {.lex_state = 0, .external_lex_state = 2},
  [35] = {.lex_state = 0, .external_lex_state = 2},
  [36] = {.lex_state = 0, .external_lex_state = 2},
  [37] = {.lex_state = 0, .external_lex_state = 2},
  [38] = {.lex_state = 0, .external_lex_state = 2},
  [39] = {.lex_state = 0, .external_lex_state = 2},
  [40] = {.lex_state = 0, .external_lex_state = 2},
  [41] = {.lex_state = 0, .external_lex_state = 2},
  [42] = {.lex_state = 0, .external_lex_state = 2},
  [43] = {.lex_state = 0, .external_lex_state = 2},
  [44] = {.lex_state = 0, .external_lex_state = 2},
  [45] = {.lex_state = 0, .external_lex_state = 2},
  [46] = {.lex_state = 0, .external_lex_state = 2},
  [47] = {.lex_state = 0, .external_lex_state = 2},
  [48] = {.lex_state = 0, .external_lex_state = 2},
  [49] = {.lex_state = 3, .external_lex_state = 2},
  [50] = {.lex_state = 0, .external_lex_state = 2},
  [51] = {.lex_state = 0, .external_lex_state = 2},
  [52] = {.lex_state = 3, .external_lex_state = 2},
  [53] = {.lex_state = 3, .external_lex_state = 2},
  [54] = {.lex_state = 3, .external_lex_state = 2},
  [55] = {.lex_state = 3, .external_lex_state = 2},
  [56] = {.lex_state = 0, .external_lex_state = 2},
  [57] = {.lex_state = 3, .external_lex_state = 2},
  [58] = {.lex_state = 3, .external_lex_state = 2},
  [59] = {.lex_state = 12, .external_lex_state = 2},
  [60] = {.lex_state = 10, .external_lex_state = 2},
  [61] = {.lex_state = 0, .external_lex_state = 2},
  [62] = {.lex_state = 0, .external_lex_state = 3},
  [63] = {.lex_state = 0, .external_lex_state = 2},
  [64] = {.lex_state = 10, .external_lex_state = 2},
  [65] = {.lex_state = 12, .external_lex_state = 2},
  [66] = {.lex_state = 10, .external_lex_state = 2},
  [67] = {.lex_state = 0, .external_lex_state = 2},
  [68] = {.lex_state = 0, .external_lex_state = 3},
  [69] = {.lex_state = 0, .external_lex_state = 2},
  [70] = {.lex_state = 0, .external_lex_state = 2},
  [71] = {.lex_state = 14, .external_lex_state = 2},
  [72] = {.lex_state = 0, .external_lex_state = 2},
  [73] = {.lex_state = 13, .external_lex_state = 2},
  [74] = {.lex_state = 0, .external_lex_state = 2},
  [75] = {.lex_state = 13, .external_lex_state = 2},
  [76] = {.lex_state = 0, .external_lex_state = 2},
  [77] = {.lex_state = 0, .external_lex_state = 2},
  [78] = {.lex_state = 0, .external_lex_state = 2},
  [79] = {.lex_state = 0, .external_lex_state = 2},
  [80] = {.lex_state = 14, .external_lex_state = 2},
  [81] = {.lex_state = 0, .external_lex_state = 2},
  [82] = {.lex_state = 0, .external_lex_state = 2},
  [83] = {.lex_state = 0, .external_lex_state = 2},
  [84] = {.lex_state = 1, .external_lex_state = 3},
  [85] = {.lex_state = 1, .external_lex_state = 3},
  [86] = {.lex_state = 0, .external_lex_state = 2},
  [87] = {.lex_state = 0, .external_lex_state = 2},
  [88] = {.lex_state = 0, .external_lex_state = 2},
  [89] = {.lex_state = 13, .external_lex_state = 2},
  [90] = {.lex_state = 1, .external_lex_state = 3},
  [91] = {.lex_state = 13, .external_lex_state = 2},
  [92] = {.lex_state = 0, .external_lex_state = 2},
  [93] = {.lex_state = 0, .external_lex_state = 2},
  [94] = {.lex_state = 0, .external_lex_state = 2},
  [95] = {.lex_state = 0, .external_lex_state = 2},
  [96] = {.lex_state = 0, .external_lex_state = 2},
  [97] = {.lex_state = 0, .external_lex_state = 2},
  [98] = {.lex_state = 0, .external_lex_state = 2},
  [99] = {.lex_state = 0, .external_lex_state = 2},
  [100] = {.lex_state = 0, .external_lex_state = 2},
  [101] = {.lex_state = 0, .external_lex_state = 2},
  [102] = {.lex_state = 0, .external_lex_state = 2},
  [103] = {.lex_state = 0, .external_lex_state = 2},
  [104] = {.lex_state = 0, .external_lex_state = 2},
  [105] = {.lex_state = 0, .external_lex_state = 2},
  [106] = {.lex_state = 0, .external_lex_state = 2},
  [107] = {.lex_state = 0, .external_lex_state = 2},
  [108] = {.lex_state = 0, .external_lex_state = 2},
  [109] = {.lex_state = 0, .external_lex_state = 2},
  [110] = {.lex_state = 0, .external_lex_state = 2},
  [111] = {.lex_state = 0, .external_lex_state = 2},
  [112] = {.lex_state = 0, .external_lex_state = 2},
  [113] = {.lex_state = 0, .external_lex_state = 2},
  [114] = {.lex_state = 13, .external_lex_state = 2},
  [115] = {.lex_state = 13, .external_lex_state = 2},
  [116] = {.lex_state = 0, .external_lex_state = 2},
  [117] = {.lex_state = 1, .external_lex_state = 3},
  [118] = {.lex_state = 11, .external_lex_state = 2},
  [119] = {.lex_state = 11, .external_lex_state = 2},
  [120] = {.lex_state = 4, .external_lex_state = 2},
  [121] = {.lex_state = 4, .external_lex_state = 2},
  [122] = {.lex_state = 3, .external_lex_state = 2},
  [123] = {.lex_state = 3, .external_lex_state = 2},
  [124] = {.lex_state = 11, .external_lex_state = 3},
  [125] = {.lex_state = 10, .external_lex_state = 3},
  [126] = {.lex_state = 11, .external_lex_state = 2},
  [127] = {.lex_state = 11, .external_lex_state = 2},
  [128] = {.lex_state = 4, .external_lex_state = 2},
  [129] = {.lex_state = 4, .external_lex_state = 2},
  [130] = {.lex_state = 0, .external_lex_state = 3},
  [131] = {.lex_state = 0, .external_lex_state = 3},
  [132] = {.lex_state = 0, .external_lex_state = 2},
  [133] = {.lex_state = 0, .external_lex_state = 3},
  [134] = {.lex_state = 0, .external_lex_state = 3},
  [135] = {.lex_state = 0, .external_lex_state = 3},
  [136] = {.lex_state = 0, .external_lex_state = 3},
  [137] = {.lex_state = 0, .external_lex_state = 3},
  [138] = {.lex_state = 0, .external_lex_state = 3},
  [139] = {.lex_state = 0, .external_lex_state = 3},
  [140] = {.lex_state = 0, .external_lex_state = 3},
  [141] = {.lex_state = 0, .external_lex_state = 3},
  [142] = {.lex_state = 0, .external_lex_state = 2},
  [143] = {.lex_state = 0, .external_lex_state = 3},
  [144] = {.lex_state = 0, .external_lex_state = 3},
  [145] = {.lex_state = 0, .external_lex_state = 2},
  [146] = {.lex_state = 0, .external_lex_state = 2},
  [147] = {.lex_state = 4, .external_lex_state = 2},
  [148] = {.lex_state = 0, .external_lex_state = 2},
  [149] = {.lex_state = 0, .external_lex_state = 3},
  [150] = {.lex_state = 0, .external_lex_state = 2},
  [151] = {.lex_state = 0, .external_lex_state = 2},
  [152] = {.lex_state = 0, .external_lex_state = 3},
  [153] = {.lex_state = 0, .external_lex_state = 3},
  [154] = {.lex_state = 0, .external_lex_state = 3},
  [155] = {.lex_state = 11, .external_lex_state = 2},
  [156] = {.lex_state = 0, .external_lex_state = 3},
  [157] = {.lex_state = 0, .external_lex_state = 3},
  [158] = {.lex_state = 0, .external_lex_state = 2},
  [159] = {.lex_state = 0, .external_lex_state = 3},
  [160] = {.lex_state = 10, .external_lex_state = 2},
  [161] = {.lex_state = 0, .external_lex_state = 2},
  [162] = {.lex_state = 0, .external_lex_state = 3},
  [163] = {.lex_state = 0, .external_lex_state = 3},
  [164] = {.lex_state = 11, .external_lex_state = 2},
  [165] = {.lex_state = 0, .external_lex_state = 3},
  [166] = {.lex_state = 11, .external_lex_state = 2},
  [167] = {.lex_state = 0, .external_lex_state = 3},
  [168] = {.lex_state = 0, .external_lex_state = 3},
  [169] = {.lex_state = 0, .external_lex_state = 3},
  [170] = {.lex_state = 0, .external_lex_state = 3},
  [171] = {.lex_state = 0, .external_lex_state = 3},
  [172] = {.lex_state = 11, .external_lex_state = 2},
  [173] = {.lex_state = 0, .external_lex_state = 3},
  [174] = {.lex_state = 11, .external_lex_state = 2},
  [175] = {.lex_state = 0, .external_lex_state = 2},
  [176] = {.lex_state = 0, .external_lex_state = 3},
  [177] = {.lex_state = 0, .external_lex_state = 3},
  [178] = {.lex_state = 0, .external_lex_state = 3},
  [179] = {.lex_state = 0, .external_lex_state = 3},
  [180] = {.lex_state = 0, .external_lex_state = 3},
  [181] = {.lex_state = 0, .external_lex_state = 3},
  [182] = {.lex_state = 0, .external_lex_state = 2},
  [183] = {.lex_state = 0, .external_lex_state = 3},
  [184] = {.lex_state = 11, .external_lex_state = 2},
  [185] = {.lex_state = 0, .external_lex_state = 3},
  [186] = {.lex_state = 0, .external_lex_state = 3},
  [187] = {.lex_state = 11, .external_lex_state = 2},
  [188] = {.lex_state = 0, .external_lex_state = 3},
  [189] = {.lex_state = 11, .external_lex_state = 2},
  [190] = {.lex_state = 11, .external_lex_state = 3},
  [191] = {.lex_state = 11, .external_lex_state = 2},
  [192] = {.lex_state = 0, .external_lex_state = 2},
  [193] = {.lex_state = 0, .external_lex_state = 3},
  [194] = {.lex_state = 11, .external_lex_state = 2},
  [195] = {.lex_state = 0, .external_lex_state = 3},
  [196] = {.lex_state = 0, .external_lex_state = 3},
  [197] = {.lex_state = 0, .external_lex_state = 3},
  [198] = {.lex_state = 11, .external_lex_state = 2},
  [199] = {.lex_state = 11, .external_lex_state = 2},
  [200] = {.lex_state = 11, .external_lex_state = 2},
  [201] = {.lex_state = 11, .external_lex_state = 2},
  [202] = {.lex_state = 11, .external_lex_state = 2},
  [203] = {.lex_state = 11, .external_lex_state = 2},
  [204] = {.lex_state = 11, .external_lex_state = 2},
  [205] = {.lex_state = 11, .external_lex_state = 2},
  [206] = {.lex_state = 11, .external_lex_state = 2},
  [207] = {.lex_state = 0, .external_lex_state = 3},
  [208] = {.lex_state = 0, .external_lex_state = 2},
  [209] = {.lex_state = 11, .external_lex_state = 2},
  [210] = {.lex_state = 11, .external_lex_state = 2},
  [211] = {.lex_state = 11, .external_lex_state = 2},
  [212] = {.lex_state = 0, .external_lex_state = 2},
  [213] = {.lex_state = 0, .external_lex_state = 3},
  [214] = {.lex_state = 0, .external_lex_state = 2},
  [215] = {.lex_state = 0, .external_lex_state = 2},
  [216] = {.lex_state = 0, .external_lex_state = 3},
  [217] = {.lex_state = 0, .external_lex_state = 2},
  [218] = {.lex_state = 0, .external_lex_state = 2},
  [219] = {.lex_state = 0, .external_lex_state = 3},
  [220] = {.lex_state = 0, .external_lex_state = 3},
  [221] = {.lex_state = 0, .external_lex_state = 2},
  [222] = {.lex_state = 0, .external_lex_state = 2},
  [223] = {.lex_state = 13, .external_lex_state = 2},
  [224] = {.lex_state = 11, .external_lex_state = 2},
  [225] = {.lex_state = 0, .external_lex_state = 3},
  [226] = {.lex_state = 0, .external_lex_state = 2},
  [227] = {.lex_state = 0, .external_lex_state = 2},
  [228] = {.lex_state = 11, .external_lex_state = 2},
  [229] = {.lex_state = 0, .external_lex_state = 2},
  [230] = {.lex_state = 0, .external_lex_state = 3},
  [231] = {.lex_state = 0, .external_lex_state = 3},
  [232] = {.lex_state = 0, .external_lex_state = 2},
  [233] = {.lex_state = 0, .external_lex_state = 2},
  [234] = {.lex_state = 1, .external_lex_state = 2},
  [235] = {.lex_state = 1, .external_lex_state = 2},
  [236] = {.lex_state = 0, .external_lex_state = 2},
  [237] = {.lex_state = 0, .external_lex_state = 2},
  [238] = {.lex_state = 0, .external_lex_state = 2},
  [239] = {.lex_state = 3, .external_lex_state = 2},
  [240] = {.lex_state = 0, .external_lex_state = 2},
  [241] = {.lex_state = 0, .external_lex_state = 2},
  [242] = {.lex_state = 0, .external_lex_state = 2},
  [243] = {.lex_state = 0, .external_lex_state = 2},
  [244] = {.lex_state = 0, .external_lex_state = 2},
  [245] = {.lex_state = 0, .external_lex_state = 2},
  [246] = {.lex_state = 0, .external_lex_state = 2},
  [247] = {.lex_state = 0, .external_lex_state = 2},
  [248] = {.lex_state = 0, .external_lex_state = 2},
  [249] = {.lex_state = 0, .external_lex_state = 2},
  [250] = {.lex_state = 0, .external_lex_state = 2},
  [251] = {.lex_state = 0, .external_lex_state = 2},
  [252] = {.lex_state = 0, .external_lex_state = 2},
  [253] = {.lex_state = 11, .external_lex_state = 2},
  [254] = {.lex_state = 0, .external_lex_state = 2},
  [255] = {.lex_state = 11, .external_lex_state = 2},
  [256] = {.lex_state = 0, .external_lex_state = 2},
  [257] = {.lex_state = 11, .external_lex_state = 2},
  [258] = {.lex_state = 0, .external_lex_state = 2},
  [259] = {.lex_state = 0, .external_lex_state = 2},
  [260] = {.lex_state = 0, .external_lex_state = 2},
  [261] = {.lex_state = 0, .external_lex_state = 2},
  [262] = {.lex_state = 11, .external_lex_state = 2},
  [263] = {.lex_state = 0, .external_lex_state = 2},
  [264] = {.lex_state = 11, .external_lex_state = 2},
  [265] = {.lex_state = 11, .external_lex_state = 2},
  [266] = {.lex_state = 11, .external_lex_state = 2},
  [267] = {.lex_state = 0, .external_lex_state = 2},
  [268] = {.lex_state = 0, .external_lex_state = 2},
  [269] = {.lex_state = 1, .external_lex_state = 2},
  [270] = {.lex_state = 0, .external_lex_state = 2},
  [271] = {.lex_state = 11, .external_lex_state = 2},
  [272] = {.lex_state = 0, .external_lex_state = 2},
  [273] = {.lex_state = 0, .external_lex_state = 2},
  [274] = {.lex_state = 0, .external_lex_state = 2},
  [275] = {.lex_state = 0, .external_lex_state = 2},
  [276] = {.lex_state = 0, .external_lex_state = 2},
  [277] = {.lex_state = 0, .external_lex_state = 2},
  [278] = {.lex_state = 0, .external_lex_state = 2},
  [279] = {.lex_state = 0, .external_lex_state = 2},
  [280] = {.lex_state = 1, .external_lex_state = 2},
  [281] = {.lex_state = 11, .external_lex_state = 2},
  [282] = {.lex_state = 0, .external_lex_state = 2},
  [283] = {.lex_state = 0, .external_lex_state = 2},
  [284] = {.lex_state = 0, .external_lex_state = 2},
  [285] = {.lex_state = 0, .external_lex_state = 2},
  [286] = {.lex_state = 0, .external_lex_state = 2},
  [287] = {.lex_state = 0, .external_lex_state = 2},
  [288] = {.lex_state = 0, .external_lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_standard] = ACTIONS(1),
    [anon_sym_library] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_public] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_protected] = ACTIONS(1),
    [anon_sym_dependency] = ACTIONS(1),
    [anon_sym_from] = ACTIONS(1),
    [anon_sym_to] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_TODO] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_all] = ACTIONS(1),
    [anon_sym_occurrence] = ACTIONS(1),
    [sym_attribute_keyword] = ACTIONS(1),
    [anon_sym_ref] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym_prefix_metadata_annotation] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT] = ACTIONS(1),
    [anon_sym_abstract] = ACTIONS(1),
    [anon_sym_variation] = ACTIONS(1),
    [anon_sym_specializes] = ACTIONS(1),
    [anon_sym_COLON_GT] = ACTIONS(1),
    [sym_attribute_def_keyword] = ACTIONS(1),
    [anon_sym_comment] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_doc] = ACTIONS(1),
    [anon_sym_locale] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__backslash] = ACTIONS(1),
    [sym__nl_comma] = ACTIONS(1),
    [sym_float] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(277),
    [sym_root_namespace] = STATE(50),
    [sym_package] = STATE(79),
    [sym_library_package] = STATE(79),
    [sym_package_declaration] = STATE(207),
    [sym_dependency] = STATE(50),
    [aux_sym_source_file_repeat1] = STATE(50),
    [aux_sym_dependency_repeat1] = STATE(158),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_standard] = ACTIONS(7),
    [anon_sym_library] = ACTIONS(9),
    [anon_sym_package] = ACTIONS(11),
    [anon_sym_dependency] = ACTIONS(13),
    [sym_prefix_metadata_annotation] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
    [sym_block_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 29,
    ACTIONS(17), 1,
      anon_sym_package,
    ACTIONS(19), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 1,
      anon_sym_dependency,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(27), 1,
      anon_sym_occurrence,
    ACTIONS(29), 1,
      anon_sym_ref,
    ACTIONS(31), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(35), 1,
      sym_attribute_def_keyword,
    ACTIONS(39), 1,
      anon_sym_doc,
    ACTIONS(41), 1,
      anon_sym_locale,
    STATE(5), 1,
      sym_member_prefix,
    STATE(11), 1,
      sym_attribute_usage,
    STATE(12), 1,
      sym_regular_comment,
    STATE(13), 1,
      sym_documentation,
    STATE(49), 1,
      sym_import_prefix,
    STATE(208), 1,
      aux_sym_dependency_repeat1,
    STATE(222), 1,
      sym_usage_prefix,
    STATE(233), 1,
      sym_visibility,
    STATE(248), 1,
      sym_basic_usage_prefix,
    STATE(267), 1,
      sym_basic_definition_prefix,
    STATE(273), 1,
      sym_definition_prefix,
    ACTIONS(33), 2,
      anon_sym_abstract,
      anon_sym_variation,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
    STATE(10), 2,
      sym_non_occurrence_usage_element,
      sym_occurrence_usage_element,
    STATE(38), 2,
      sym_definition_element,
      sym_usage_element,
    STATE(159), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(4), 3,
      sym_package_member,
      sym_import_stmt,
      aux_sym_package_body_repeat1,
    STATE(30), 4,
      sym_package_declaration,
      sym_dependency,
      sym_annotating_element,
      sym_attribute_definition,
  [100] = 29,
    ACTIONS(43), 1,
      anon_sym_package,
    ACTIONS(46), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      anon_sym_dependency,
    ACTIONS(54), 1,
      anon_sym_import,
    ACTIONS(57), 1,
      anon_sym_occurrence,
    ACTIONS(60), 1,
      anon_sym_ref,
    ACTIONS(63), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(69), 1,
      sym_attribute_def_keyword,
    ACTIONS(75), 1,
      anon_sym_doc,
    ACTIONS(78), 1,
      anon_sym_locale,
    STATE(5), 1,
      sym_member_prefix,
    STATE(11), 1,
      sym_attribute_usage,
    STATE(12), 1,
      sym_regular_comment,
    STATE(13), 1,
      sym_documentation,
    STATE(49), 1,
      sym_import_prefix,
    STATE(208), 1,
      aux_sym_dependency_repeat1,
    STATE(222), 1,
      sym_usage_prefix,
    STATE(233), 1,
      sym_visibility,
    STATE(248), 1,
      sym_basic_usage_prefix,
    STATE(267), 1,
      sym_basic_definition_prefix,
    STATE(273), 1,
      sym_definition_prefix,
    ACTIONS(66), 2,
      anon_sym_abstract,
      anon_sym_variation,
    ACTIONS(72), 2,
      sym_block_comment,
      sym_comment,
    STATE(10), 2,
      sym_non_occurrence_usage_element,
      sym_occurrence_usage_element,
    STATE(38), 2,
      sym_definition_element,
      sym_usage_element,
    STATE(159), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(48), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(3), 3,
      sym_package_member,
      sym_import_stmt,
      aux_sym_package_body_repeat1,
    STATE(30), 4,
      sym_package_declaration,
      sym_dependency,
      sym_annotating_element,
      sym_attribute_definition,
  [200] = 29,
    ACTIONS(17), 1,
      anon_sym_package,
    ACTIONS(23), 1,
      anon_sym_dependency,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(27), 1,
      anon_sym_occurrence,
    ACTIONS(29), 1,
      anon_sym_ref,
    ACTIONS(31), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(35), 1,
      sym_attribute_def_keyword,
    ACTIONS(39), 1,
      anon_sym_doc,
    ACTIONS(41), 1,
      anon_sym_locale,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
    STATE(5), 1,
      sym_member_prefix,
    STATE(11), 1,
      sym_attribute_usage,
    STATE(12), 1,
      sym_regular_comment,
    STATE(13), 1,
      sym_documentation,
    STATE(49), 1,
      sym_import_prefix,
    STATE(208), 1,
      aux_sym_dependency_repeat1,
    STATE(222), 1,
      sym_usage_prefix,
    STATE(233), 1,
      sym_visibility,
    STATE(248), 1,
      sym_basic_usage_prefix,
    STATE(267), 1,
      sym_basic_definition_prefix,
    STATE(273), 1,
      sym_definition_prefix,
    ACTIONS(33), 2,
      anon_sym_abstract,
      anon_sym_variation,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
    STATE(10), 2,
      sym_non_occurrence_usage_element,
      sym_occurrence_usage_element,
    STATE(38), 2,
      sym_definition_element,
      sym_usage_element,
    STATE(159), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(3), 3,
      sym_package_member,
      sym_import_stmt,
      aux_sym_package_body_repeat1,
    STATE(30), 4,
      sym_package_declaration,
      sym_dependency,
      sym_annotating_element,
      sym_attribute_definition,
  [300] = 21,
    ACTIONS(17), 1,
      anon_sym_package,
    ACTIONS(23), 1,
      anon_sym_dependency,
    ACTIONS(27), 1,
      anon_sym_occurrence,
    ACTIONS(29), 1,
      anon_sym_ref,
    ACTIONS(31), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(35), 1,
      sym_attribute_def_keyword,
    ACTIONS(39), 1,
      anon_sym_doc,
    ACTIONS(41), 1,
      anon_sym_locale,
    STATE(11), 1,
      sym_attribute_usage,
    STATE(12), 1,
      sym_regular_comment,
    STATE(13), 1,
      sym_documentation,
    STATE(208), 1,
      aux_sym_dependency_repeat1,
    STATE(222), 1,
      sym_usage_prefix,
    STATE(248), 1,
      sym_basic_usage_prefix,
    STATE(267), 1,
      sym_basic_definition_prefix,
    STATE(273), 1,
      sym_definition_prefix,
    ACTIONS(33), 2,
      anon_sym_abstract,
      anon_sym_variation,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
    STATE(10), 2,
      sym_non_occurrence_usage_element,
      sym_occurrence_usage_element,
    STATE(19), 2,
      sym_definition_element,
      sym_usage_element,
    STATE(30), 4,
      sym_package_declaration,
      sym_dependency,
      sym_annotating_element,
      sym_attribute_definition,
  [371] = 5,
    ACTIONS(83), 1,
      sym_identifier,
    ACTIONS(89), 1,
      anon_sym_LT,
    STATE(40), 1,
      sym_identification,
    ACTIONS(87), 4,
      sym_block_comment,
      anon_sym_RBRACE,
      sym_prefix_metadata_annotation,
      sym_comment,
    ACTIONS(85), 13,
      anon_sym_package,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      anon_sym_doc,
      anon_sym_locale,
  [402] = 15,
    ACTIONS(91), 1,
      anon_sym_package,
    ACTIONS(93), 1,
      anon_sym_dependency,
    ACTIONS(95), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(97), 1,
      sym_attribute_def_keyword,
    ACTIONS(101), 1,
      anon_sym_doc,
    ACTIONS(103), 1,
      anon_sym_locale,
    STATE(82), 1,
      sym_definition_element,
    STATE(87), 1,
      sym_regular_comment,
    STATE(88), 1,
      sym_documentation,
    STATE(212), 1,
      aux_sym_dependency_repeat1,
    STATE(232), 1,
      sym_definition_prefix,
    STATE(267), 1,
      sym_basic_definition_prefix,
    ACTIONS(33), 2,
      anon_sym_abstract,
      anon_sym_variation,
    ACTIONS(99), 2,
      sym_block_comment,
      sym_comment,
    STATE(86), 4,
      sym_package_declaration,
      sym_dependency,
      sym_annotating_element,
      sym_attribute_definition,
  [453] = 3,
    ACTIONS(105), 1,
      sym_identifier,
    ACTIONS(109), 4,
      sym_block_comment,
      anon_sym_RBRACE,
      sym_prefix_metadata_annotation,
      sym_comment,
    ACTIONS(107), 13,
      anon_sym_package,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      anon_sym_doc,
      anon_sym_locale,
  [478] = 1,
    ACTIONS(111), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [498] = 1,
    ACTIONS(113), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [518] = 1,
    ACTIONS(115), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [538] = 1,
    ACTIONS(117), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [558] = 1,
    ACTIONS(117), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [578] = 1,
    ACTIONS(119), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [598] = 1,
    ACTIONS(121), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [618] = 1,
    ACTIONS(123), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [638] = 1,
    ACTIONS(125), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [658] = 1,
    ACTIONS(127), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [678] = 1,
    ACTIONS(129), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [698] = 1,
    ACTIONS(131), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [718] = 1,
    ACTIONS(133), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [738] = 1,
    ACTIONS(135), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [758] = 10,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(137), 1,
      anon_sym_RBRACE,
    ACTIONS(139), 1,
      anon_sym_TODO,
    STATE(7), 1,
      sym_member_prefix,
    STATE(49), 1,
      sym_import_prefix,
    STATE(233), 1,
      sym_visibility,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(183), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(32), 4,
      sym_import_stmt,
      sym_alias_member,
      sym_definition_member,
      aux_sym_definition_body_repeat1,
  [796] = 1,
    ACTIONS(141), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [816] = 1,
    ACTIONS(143), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [836] = 1,
    ACTIONS(145), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [856] = 1,
    ACTIONS(147), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [876] = 1,
    ACTIONS(149), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [896] = 1,
    ACTIONS(151), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [916] = 1,
    ACTIONS(153), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [936] = 1,
    ACTIONS(155), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [956] = 10,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(139), 1,
      anon_sym_TODO,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      sym_member_prefix,
    STATE(49), 1,
      sym_import_prefix,
    STATE(233), 1,
      sym_visibility,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(183), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(37), 4,
      sym_import_stmt,
      sym_alias_member,
      sym_definition_member,
      aux_sym_definition_body_repeat1,
  [994] = 1,
    ACTIONS(159), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1014] = 1,
    ACTIONS(161), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1034] = 1,
    ACTIONS(163), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1054] = 1,
    ACTIONS(165), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1074] = 10,
    ACTIONS(167), 1,
      anon_sym_RBRACE,
    ACTIONS(172), 1,
      anon_sym_TODO,
    ACTIONS(175), 1,
      anon_sym_import,
    STATE(7), 1,
      sym_member_prefix,
    STATE(49), 1,
      sym_import_prefix,
    STATE(233), 1,
      sym_visibility,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(183), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(169), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(37), 4,
      sym_import_stmt,
      sym_alias_member,
      sym_definition_member,
      aux_sym_definition_body_repeat1,
  [1112] = 1,
    ACTIONS(178), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1132] = 1,
    ACTIONS(180), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1152] = 1,
    ACTIONS(182), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1172] = 1,
    ACTIONS(184), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1192] = 1,
    ACTIONS(186), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1212] = 1,
    ACTIONS(188), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1232] = 1,
    ACTIONS(190), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1252] = 1,
    ACTIONS(192), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1272] = 10,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(139), 1,
      anon_sym_TODO,
    ACTIONS(194), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      sym_member_prefix,
    STATE(49), 1,
      sym_import_prefix,
    STATE(233), 1,
      sym_visibility,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(183), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(47), 4,
      sym_import_stmt,
      sym_alias_member,
      sym_definition_member,
      aux_sym_definition_body_repeat1,
  [1310] = 10,
    ACTIONS(25), 1,
      anon_sym_import,
    ACTIONS(139), 1,
      anon_sym_TODO,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
    STATE(7), 1,
      sym_member_prefix,
    STATE(49), 1,
      sym_import_prefix,
    STATE(233), 1,
      sym_visibility,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(183), 2,
      sym_membership_import,
      sym_namespace_import,
    ACTIONS(21), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(37), 4,
      sym_import_stmt,
      sym_alias_member,
      sym_definition_member,
      aux_sym_definition_body_repeat1,
  [1348] = 1,
    ACTIONS(198), 17,
      sym_block_comment,
      anon_sym_package,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_dependency,
      anon_sym_import,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1368] = 9,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(204), 1,
      anon_sym_TODO,
    STATE(133), 1,
      sym_qualified_name,
    STATE(153), 1,
      sym_imported_membership,
    STATE(154), 1,
      sym_membership,
    STATE(219), 1,
      sym_imported_namespace,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(202), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(171), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1402] = 11,
    ACTIONS(7), 1,
      anon_sym_standard,
    ACTIONS(9), 1,
      anon_sym_library,
    ACTIONS(11), 1,
      anon_sym_package,
    ACTIONS(13), 1,
      anon_sym_dependency,
    ACTIONS(15), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(206), 1,
      ts_builtin_sym_end,
    STATE(158), 1,
      aux_sym_dependency_repeat1,
    STATE(207), 1,
      sym_package_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(79), 2,
      sym_package,
      sym_library_package,
    STATE(51), 3,
      sym_root_namespace,
      sym_dependency,
      aux_sym_source_file_repeat1,
  [1440] = 11,
    ACTIONS(208), 1,
      ts_builtin_sym_end,
    ACTIONS(210), 1,
      anon_sym_standard,
    ACTIONS(213), 1,
      anon_sym_library,
    ACTIONS(216), 1,
      anon_sym_package,
    ACTIONS(219), 1,
      anon_sym_dependency,
    ACTIONS(222), 1,
      sym_prefix_metadata_annotation,
    STATE(158), 1,
      aux_sym_dependency_repeat1,
    STATE(207), 1,
      sym_package_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(79), 2,
      sym_package,
      sym_library_package,
    STATE(51), 3,
      sym_root_namespace,
      sym_dependency,
      aux_sym_source_file_repeat1,
  [1478] = 7,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(204), 1,
      anon_sym_TODO,
    ACTIONS(225), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(176), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(202), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(171), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1507] = 7,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(231), 1,
      anon_sym_STAR,
    ACTIONS(233), 1,
      anon_sym_TODO,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(259), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(229), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(285), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1536] = 7,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(204), 1,
      anon_sym_TODO,
    ACTIONS(231), 1,
      anon_sym_STAR,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(176), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(202), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(171), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1565] = 7,
    ACTIONS(225), 1,
      anon_sym_STAR,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(233), 1,
      anon_sym_TODO,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(259), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(229), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(285), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1594] = 2,
    ACTIONS(237), 1,
      anon_sym_import,
    ACTIONS(235), 12,
      sym_block_comment,
      anon_sym_package,
      anon_sym_dependency,
      anon_sym_occurrence,
      anon_sym_ref,
      sym_prefix_metadata_annotation,
      anon_sym_abstract,
      anon_sym_variation,
      sym_attribute_def_keyword,
      sym_comment,
      anon_sym_doc,
      anon_sym_locale,
  [1612] = 6,
    ACTIONS(227), 1,
      sym_identifier,
    ACTIONS(233), 1,
      anon_sym_TODO,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(259), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(229), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(285), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1638] = 6,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(204), 1,
      anon_sym_TODO,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(176), 2,
      sym_membership,
      sym_qualified_name,
    ACTIONS(202), 3,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
    STATE(171), 4,
      sym_member_prefix,
      sym_alias_member,
      sym_initial_node_member,
      sym_transition_source_member,
  [1664] = 6,
    ACTIONS(87), 1,
      anon_sym_RBRACE,
    ACTIONS(239), 1,
      sym_identifier,
    ACTIONS(241), 1,
      anon_sym_LT,
    STATE(105), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(85), 5,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [1688] = 7,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(243), 1,
      anon_sym_specializes,
    ACTIONS(245), 1,
      anon_sym_COLON_GT,
    STATE(64), 1,
      sym_specializes_keyword,
    STATE(143), 1,
      sym_owned_subclassification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(179), 2,
      sym_qualified_name,
      sym_subclassification_part,
  [1712] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(119), 7,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
      anon_sym_comment,
  [1726] = 8,
    ACTIONS(247), 1,
      anon_sym_SEMI,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    ACTIONS(251), 1,
      anon_sym_TODO,
    STATE(27), 1,
      sym_usage,
    STATE(28), 1,
      sym_usage_completion,
    STATE(29), 1,
      sym_usage_body,
    STATE(139), 1,
      sym_usage_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [1752] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(192), 7,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_from,
      anon_sym_TODO,
      anon_sym_import,
  [1766] = 7,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(243), 1,
      anon_sym_specializes,
    ACTIONS(245), 1,
      anon_sym_COLON_GT,
    STATE(64), 1,
      sym_specializes_keyword,
    STATE(140), 1,
      sym_owned_subclassification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(179), 2,
      sym_qualified_name,
      sym_subclassification_part,
  [1790] = 4,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
    ACTIONS(253), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(107), 5,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [1808] = 7,
    ACTIONS(200), 1,
      sym_identifier,
    ACTIONS(243), 1,
      anon_sym_specializes,
    ACTIONS(245), 1,
      anon_sym_COLON_GT,
    STATE(64), 1,
      sym_specializes_keyword,
    STATE(157), 1,
      sym_owned_subclassification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(179), 2,
      sym_qualified_name,
      sym_subclassification_part,
  [1832] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(255), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1845] = 5,
    STATE(60), 1,
      sym_specializes_keyword,
    STATE(225), 1,
      sym_subclassification_part,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(245), 2,
      anon_sym_specializes,
      anon_sym_COLON_GT,
    ACTIONS(257), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [1864] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(259), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1877] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(261), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1890] = 3,
    ACTIONS(265), 1,
      anon_sym_all,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(263), 5,
      sym_identifier,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
  [1905] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(267), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1918] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(271), 1,
      anon_sym_from,
    ACTIONS(273), 1,
      anon_sym_LT,
    STATE(182), 1,
      sym_qualified_name,
    STATE(236), 1,
      sym_qualified_name_list,
    STATE(249), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [1941] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(184), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1954] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      anon_sym_LT,
    ACTIONS(275), 1,
      anon_sym_from,
    STATE(182), 1,
      sym_qualified_name,
    STATE(247), 1,
      sym_identification,
    STATE(256), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [1977] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(186), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [1990] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(277), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2003] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(279), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2016] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(281), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2029] = 3,
    ACTIONS(285), 1,
      anon_sym_all,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(283), 5,
      sym_identifier,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
  [2044] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(188), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2057] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(287), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2070] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(190), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2083] = 4,
    ACTIONS(291), 1,
      anon_sym_DOT,
    STATE(90), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(289), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2100] = 4,
    ACTIONS(291), 1,
      anon_sym_DOT,
    STATE(84), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(293), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2117] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(153), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2130] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(117), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2143] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(117), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2156] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      anon_sym_LT,
    ACTIONS(295), 1,
      anon_sym_from,
    STATE(182), 1,
      sym_qualified_name,
    STATE(275), 1,
      sym_qualified_name_list,
    STATE(286), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2179] = 4,
    ACTIONS(299), 1,
      anon_sym_DOT,
    STATE(90), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(297), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2196] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      anon_sym_LT,
    ACTIONS(302), 1,
      anon_sym_from,
    STATE(182), 1,
      sym_qualified_name,
    STATE(270), 1,
      sym_qualified_name_list,
    STATE(287), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2219] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(127), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2232] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(131), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2245] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(133), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2258] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(135), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2271] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(141), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2284] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(143), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2297] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(145), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2310] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(111), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2323] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(198), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2336] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(159), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2349] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(161), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2362] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(165), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(180), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2388] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(182), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2401] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(131), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2414] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(184), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2427] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(145), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2440] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(186), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2453] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(161), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2466] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(188), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2479] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(190), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2492] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(304), 6,
      ts_builtin_sym_end,
      anon_sym_standard,
      anon_sym_library,
      anon_sym_package,
      anon_sym_dependency,
      sym_prefix_metadata_annotation,
  [2505] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      anon_sym_LT,
    ACTIONS(306), 1,
      anon_sym_from,
    STATE(182), 1,
      sym_qualified_name,
    STATE(254), 1,
      sym_qualified_name_list,
    STATE(282), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2528] = 7,
    ACTIONS(269), 1,
      sym_identifier,
    ACTIONS(273), 1,
      anon_sym_LT,
    ACTIONS(308), 1,
      anon_sym_from,
    STATE(182), 1,
      sym_qualified_name,
    STATE(268), 1,
      sym_qualified_name_list,
    STATE(279), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2551] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(125), 6,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
      anon_sym_import,
  [2564] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(297), 5,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
      anon_sym_DOT,
  [2576] = 6,
    ACTIONS(310), 1,
      sym_identifier,
    ACTIONS(312), 1,
      anon_sym_LT,
    STATE(9), 1,
      sym_definition,
    STATE(68), 1,
      sym_identification,
    STATE(181), 1,
      sym_definition_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2596] = 6,
    ACTIONS(310), 1,
      sym_identifier,
    ACTIONS(312), 1,
      anon_sym_LT,
    STATE(17), 1,
      sym_definition,
    STATE(68), 1,
      sym_identification,
    STATE(181), 1,
      sym_definition_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2616] = 4,
    ACTIONS(314), 1,
      anon_sym_DOT,
    STATE(128), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(289), 3,
      anon_sym_to,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2632] = 4,
    ACTIONS(314), 1,
      anon_sym_DOT,
    STATE(120), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(293), 3,
      anon_sym_to,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2648] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(263), 5,
      sym_identifier,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
  [2660] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(316), 5,
      sym_identifier,
      anon_sym_public,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_TODO,
  [2672] = 5,
    ACTIONS(310), 1,
      sym_identifier,
    ACTIONS(318), 1,
      anon_sym_LT,
    STATE(230), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(87), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2690] = 4,
    ACTIONS(107), 1,
      anon_sym_specializes,
    ACTIONS(320), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(109), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_GT,
  [2706] = 6,
    ACTIONS(310), 1,
      sym_identifier,
    ACTIONS(312), 1,
      anon_sym_LT,
    STATE(68), 1,
      sym_identification,
    STATE(116), 1,
      sym_definition,
    STATE(186), 1,
      sym_definition_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2726] = 6,
    ACTIONS(310), 1,
      sym_identifier,
    ACTIONS(312), 1,
      anon_sym_LT,
    STATE(68), 1,
      sym_identification,
    STATE(99), 1,
      sym_definition,
    STATE(186), 1,
      sym_definition_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2746] = 4,
    ACTIONS(322), 1,
      anon_sym_DOT,
    STATE(128), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(297), 3,
      anon_sym_to,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
  [2762] = 5,
    ACTIONS(180), 1,
      anon_sym_from,
    ACTIONS(314), 1,
      anon_sym_DOT,
    STATE(120), 1,
      aux_sym_qualified_name_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(293), 2,
      anon_sym_to,
      anon_sym_COMMA,
  [2780] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(192), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_specializes,
      anon_sym_COLON_GT,
  [2791] = 4,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    STATE(135), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(325), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2806] = 4,
    ACTIONS(329), 1,
      anon_sym_RBRACE,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [2821] = 4,
    ACTIONS(335), 1,
      anon_sym_COLON_COLON,
    STATE(137), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(333), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2836] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(180), 4,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_specializes,
      anon_sym_COLON_GT,
  [2847] = 4,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    STATE(141), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(337), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2862] = 3,
    STATE(149), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(339), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [2875] = 4,
    ACTIONS(341), 1,
      anon_sym_COLON_COLON,
    STATE(149), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(339), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2890] = 4,
    ACTIONS(345), 1,
      anon_sym_COMMA,
    STATE(144), 1,
      aux_sym_subclassification_part_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(343), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2905] = 5,
    ACTIONS(247), 1,
      anon_sym_SEMI,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    STATE(29), 1,
      sym_usage_body,
    STATE(35), 1,
      sym_usage_completion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [2922] = 3,
    STATE(152), 1,
      aux_sym_subclassification_part_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(347), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [2935] = 4,
    ACTIONS(351), 1,
      anon_sym_COMMA,
    STATE(141), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(349), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2950] = 4,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(132), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [2965] = 4,
    ACTIONS(345), 1,
      anon_sym_COMMA,
    STATE(138), 1,
      aux_sym_subclassification_part_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(347), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2980] = 4,
    ACTIONS(358), 1,
      anon_sym_COMMA,
    STATE(144), 1,
      aux_sym_subclassification_part_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(356), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2995] = 4,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(361), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(148), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [3010] = 4,
    ACTIONS(363), 1,
      anon_sym_RBRACE,
    ACTIONS(365), 1,
      anon_sym_comment,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [3025] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(297), 4,
      anon_sym_to,
      anon_sym_COLON_COLON,
      anon_sym_COMMA,
      anon_sym_DOT,
  [3036] = 4,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [3051] = 4,
    ACTIONS(372), 1,
      anon_sym_COLON_COLON,
    STATE(149), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(370), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3066] = 4,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(375), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(151), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [3081] = 4,
    ACTIONS(331), 1,
      anon_sym_comment,
    ACTIONS(377), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    STATE(146), 2,
      sym_owned_annotation,
      aux_sym_relationship_body_repeat1,
  [3096] = 3,
    STATE(144), 1,
      aux_sym_subclassification_part_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(343), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [3109] = 4,
    ACTIONS(381), 1,
      anon_sym_COLON_COLON,
    STATE(215), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(379), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3124] = 3,
    STATE(136), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(333), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [3137] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(197), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3151] = 4,
    ACTIONS(385), 1,
      anon_sym_SEMI,
    ACTIONS(387), 1,
      anon_sym_LBRACE,
    STATE(83), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3165] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(356), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [3175] = 4,
    ACTIONS(389), 1,
      anon_sym_dependency,
    ACTIONS(391), 1,
      sym_prefix_metadata_annotation,
    STATE(161), 1,
      aux_sym_dependency_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3189] = 4,
    ACTIONS(393), 1,
      anon_sym_SEMI,
    ACTIONS(395), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3203] = 3,
    ACTIONS(399), 1,
      anon_sym_COLON_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(397), 2,
      sym_identifier,
      anon_sym_specializes,
  [3215] = 4,
    ACTIONS(401), 1,
      anon_sym_dependency,
    ACTIONS(403), 1,
      sym_prefix_metadata_annotation,
    STATE(161), 1,
      aux_sym_dependency_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3229] = 4,
    ACTIONS(406), 1,
      anon_sym_SEMI,
    ACTIONS(408), 1,
      anon_sym_LBRACE,
    STATE(113), 1,
      sym_package_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3243] = 4,
    ACTIONS(385), 1,
      anon_sym_SEMI,
    ACTIONS(387), 1,
      anon_sym_LBRACE,
    STATE(74), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3257] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(236), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3271] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(349), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [3281] = 4,
    ACTIONS(412), 1,
      sym_identifier,
    ACTIONS(414), 1,
      anon_sym_LT,
    STATE(242), 1,
      sym_identification,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3295] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(235), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [3305] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(279), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [3315] = 4,
    ACTIONS(393), 1,
      anon_sym_SEMI,
    ACTIONS(395), 1,
      anon_sym_LBRACE,
    STATE(42), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3329] = 4,
    ACTIONS(406), 1,
      anon_sym_SEMI,
    ACTIONS(408), 1,
      anon_sym_LBRACE,
    STATE(67), 1,
      sym_package_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3343] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(416), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [3353] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(241), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3367] = 4,
    ACTIONS(393), 1,
      anon_sym_SEMI,
    ACTIONS(395), 1,
      anon_sym_LBRACE,
    STATE(43), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3381] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(163), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3395] = 4,
    ACTIONS(337), 1,
      anon_sym_to,
    ACTIONS(418), 1,
      anon_sym_COMMA,
    STATE(192), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3409] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(370), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COLON_COLON,
  [3419] = 4,
    ACTIONS(385), 1,
      anon_sym_SEMI,
    ACTIONS(387), 1,
      anon_sym_LBRACE,
    STATE(81), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3433] = 4,
    ACTIONS(393), 1,
      anon_sym_SEMI,
    ACTIONS(395), 1,
      anon_sym_LBRACE,
    STATE(44), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3447] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(420), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_COMMA,
  [3457] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(422), 3,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_TODO,
  [3467] = 4,
    ACTIONS(424), 1,
      anon_sym_SEMI,
    ACTIONS(426), 1,
      anon_sym_LBRACE,
    STATE(24), 1,
      sym_definition_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3481] = 4,
    ACTIONS(325), 1,
      anon_sym_to,
    ACTIONS(418), 1,
      anon_sym_COMMA,
    STATE(175), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3495] = 4,
    ACTIONS(428), 1,
      anon_sym_SEMI,
    ACTIONS(430), 1,
      anon_sym_LBRACE,
    STATE(94), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3509] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(169), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3523] = 4,
    ACTIONS(393), 1,
      anon_sym_SEMI,
    ACTIONS(395), 1,
      anon_sym_LBRACE,
    STATE(41), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3537] = 4,
    ACTIONS(432), 1,
      anon_sym_SEMI,
    ACTIONS(434), 1,
      anon_sym_LBRACE,
    STATE(96), 1,
      sym_definition_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3551] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(261), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3565] = 4,
    ACTIONS(428), 1,
      anon_sym_SEMI,
    ACTIONS(430), 1,
      anon_sym_LBRACE,
    STATE(109), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3579] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(173), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3593] = 3,
    ACTIONS(436), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(109), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3605] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(156), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3619] = 4,
    ACTIONS(349), 1,
      anon_sym_to,
    ACTIONS(438), 1,
      anon_sym_COMMA,
    STATE(192), 1,
      aux_sym_qualified_name_list_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3633] = 4,
    ACTIONS(428), 1,
      anon_sym_SEMI,
    ACTIONS(430), 1,
      anon_sym_LBRACE,
    STATE(111), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3647] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(178), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3661] = 4,
    ACTIONS(428), 1,
      anon_sym_SEMI,
    ACTIONS(430), 1,
      anon_sym_LBRACE,
    STATE(112), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3675] = 4,
    ACTIONS(428), 1,
      anon_sym_SEMI,
    ACTIONS(430), 1,
      anon_sym_LBRACE,
    STATE(107), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3689] = 4,
    ACTIONS(385), 1,
      anon_sym_SEMI,
    ACTIONS(387), 1,
      anon_sym_LBRACE,
    STATE(76), 1,
      sym_relationship_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3703] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(177), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3717] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(185), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3731] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(188), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3745] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(193), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3759] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(195), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3773] = 4,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(131), 1,
      sym_qualified_name,
    STATE(196), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3787] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(254), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3801] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(258), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3815] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(288), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3829] = 4,
    ACTIONS(406), 1,
      anon_sym_SEMI,
    ACTIONS(408), 1,
      anon_sym_LBRACE,
    STATE(70), 1,
      sym_package_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3843] = 4,
    ACTIONS(391), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(441), 1,
      anon_sym_dependency,
    STATE(161), 1,
      aux_sym_dependency_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3857] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(270), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3871] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(272), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3885] = 4,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(182), 1,
      sym_qualified_name,
    STATE(274), 1,
      sym_qualified_name_list,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3899] = 4,
    ACTIONS(391), 1,
      sym_prefix_metadata_annotation,
    ACTIONS(443), 1,
      anon_sym_dependency,
    STATE(161), 1,
      aux_sym_dependency_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3913] = 4,
    ACTIONS(247), 1,
      anon_sym_SEMI,
    ACTIONS(249), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym_usage_body,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3927] = 3,
    ACTIONS(11), 1,
      anon_sym_package,
    STATE(162), 1,
      sym_package_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3938] = 3,
    ACTIONS(445), 1,
      anon_sym_COLON_COLON,
    STATE(217), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3949] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(447), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3958] = 3,
    ACTIONS(449), 1,
      anon_sym_COLON_COLON,
    STATE(217), 1,
      aux_sym_imported_membership_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [3969] = 3,
    ACTIONS(452), 1,
      anon_sym_locale,
    STATE(92), 1,
      sym_regular_comment,
    ACTIONS(99), 2,
      sym_block_comment,
      sym_comment,
  [3980] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(454), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3989] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(456), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [3998] = 3,
    ACTIONS(458), 1,
      anon_sym_locale,
    STATE(18), 1,
      sym_regular_comment,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
  [4009] = 3,
    ACTIONS(460), 1,
      sym_attribute_keyword,
    STATE(62), 1,
      sym_attribute_usage_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4020] = 3,
    ACTIONS(107), 1,
      anon_sym_from,
    ACTIONS(253), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4031] = 3,
    ACTIONS(410), 1,
      sym_identifier,
    STATE(227), 1,
      sym_qualified_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4042] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(462), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [4051] = 3,
    ACTIONS(11), 1,
      anon_sym_package,
    STATE(170), 1,
      sym_package_declaration,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4062] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(349), 2,
      anon_sym_to,
      anon_sym_COMMA,
  [4071] = 3,
    ACTIONS(383), 1,
      sym_identifier,
    STATE(165), 1,
      sym_qualified_name,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4082] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(464), 2,
      anon_sym_RBRACE,
      anon_sym_comment,
  [4091] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(182), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [4100] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
    ACTIONS(466), 2,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [4109] = 2,
    ACTIONS(468), 1,
      sym_attribute_def_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4117] = 2,
    ACTIONS(470), 1,
      anon_sym_import,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4125] = 2,
    ACTIONS(472), 1,
      sym_string_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4133] = 2,
    ACTIONS(474), 1,
      sym_string_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4141] = 2,
    ACTIONS(476), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4149] = 2,
    ACTIONS(478), 1,
      anon_sym_library,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4157] = 2,
    ACTIONS(480), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4165] = 2,
    ACTIONS(482), 1,
      anon_sym_DOT_DOT_DOTTODO_DOT_DOT_DOT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4173] = 2,
    STATE(101), 1,
      sym_regular_comment,
    ACTIONS(99), 2,
      sym_block_comment,
      sym_comment,
  [4181] = 2,
    ACTIONS(484), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4189] = 2,
    STATE(229), 1,
      sym_regular_comment,
    ACTIONS(99), 2,
      sym_block_comment,
      sym_comment,
  [4197] = 2,
    ACTIONS(486), 1,
      sym_attribute_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4205] = 2,
    STATE(33), 1,
      sym_regular_comment,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
  [4213] = 2,
    STATE(25), 1,
      sym_regular_comment,
    ACTIONS(37), 2,
      sym_block_comment,
      sym_comment,
  [4221] = 2,
    ACTIONS(488), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4229] = 2,
    ACTIONS(490), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4237] = 2,
    ACTIONS(492), 1,
      sym_attribute_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4245] = 2,
    ACTIONS(494), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4253] = 2,
    ACTIONS(496), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4261] = 2,
    ACTIONS(498), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4269] = 2,
    ACTIONS(500), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4277] = 2,
    ACTIONS(502), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4285] = 2,
    ACTIONS(504), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4293] = 2,
    ACTIONS(506), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4301] = 2,
    ACTIONS(508), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4309] = 2,
    ACTIONS(510), 1,
      sym_identifier,
    ACTIONS(109), 2,
      sym_block_comment,
      sym_comment,
  [4317] = 2,
    ACTIONS(512), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4325] = 2,
    ACTIONS(370), 1,
      anon_sym_COLON_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4333] = 2,
    STATE(97), 1,
      sym_regular_comment,
    ACTIONS(99), 2,
      sym_block_comment,
      sym_comment,
  [4341] = 2,
    ACTIONS(514), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4349] = 2,
    ACTIONS(516), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4357] = 2,
    ACTIONS(518), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4365] = 2,
    ACTIONS(520), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4373] = 2,
    ACTIONS(522), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4381] = 2,
    ACTIONS(524), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4389] = 2,
    ACTIONS(526), 1,
      sym_attribute_def_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4397] = 2,
    ACTIONS(528), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4405] = 2,
    ACTIONS(530), 1,
      sym_string_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4413] = 2,
    ACTIONS(532), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4421] = 2,
    ACTIONS(534), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4429] = 2,
    ACTIONS(536), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4437] = 2,
    ACTIONS(538), 1,
      sym_attribute_def_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4445] = 2,
    ACTIONS(540), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4453] = 2,
    ACTIONS(542), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4461] = 2,
    ACTIONS(544), 1,
      sym_attribute_def_keyword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4469] = 2,
    ACTIONS(546), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4477] = 2,
    ACTIONS(548), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4485] = 2,
    ACTIONS(550), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4493] = 2,
    ACTIONS(552), 1,
      sym_string_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4501] = 2,
    ACTIONS(554), 1,
      sym_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4509] = 2,
    ACTIONS(556), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4517] = 2,
    ACTIONS(235), 1,
      anon_sym_COLON_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4525] = 2,
    ACTIONS(279), 1,
      anon_sym_COLON_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4533] = 2,
    ACTIONS(416), 1,
      anon_sym_COLON_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4541] = 2,
    ACTIONS(558), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4549] = 2,
    ACTIONS(560), 1,
      anon_sym_from,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
  [4557] = 2,
    ACTIONS(562), 1,
      anon_sym_to,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 100,
  [SMALL_STATE(4)] = 200,
  [SMALL_STATE(5)] = 300,
  [SMALL_STATE(6)] = 371,
  [SMALL_STATE(7)] = 402,
  [SMALL_STATE(8)] = 453,
  [SMALL_STATE(9)] = 478,
  [SMALL_STATE(10)] = 498,
  [SMALL_STATE(11)] = 518,
  [SMALL_STATE(12)] = 538,
  [SMALL_STATE(13)] = 558,
  [SMALL_STATE(14)] = 578,
  [SMALL_STATE(15)] = 598,
  [SMALL_STATE(16)] = 618,
  [SMALL_STATE(17)] = 638,
  [SMALL_STATE(18)] = 658,
  [SMALL_STATE(19)] = 678,
  [SMALL_STATE(20)] = 698,
  [SMALL_STATE(21)] = 718,
  [SMALL_STATE(22)] = 738,
  [SMALL_STATE(23)] = 758,
  [SMALL_STATE(24)] = 796,
  [SMALL_STATE(25)] = 816,
  [SMALL_STATE(26)] = 836,
  [SMALL_STATE(27)] = 856,
  [SMALL_STATE(28)] = 876,
  [SMALL_STATE(29)] = 896,
  [SMALL_STATE(30)] = 916,
  [SMALL_STATE(31)] = 936,
  [SMALL_STATE(32)] = 956,
  [SMALL_STATE(33)] = 994,
  [SMALL_STATE(34)] = 1014,
  [SMALL_STATE(35)] = 1034,
  [SMALL_STATE(36)] = 1054,
  [SMALL_STATE(37)] = 1074,
  [SMALL_STATE(38)] = 1112,
  [SMALL_STATE(39)] = 1132,
  [SMALL_STATE(40)] = 1152,
  [SMALL_STATE(41)] = 1172,
  [SMALL_STATE(42)] = 1192,
  [SMALL_STATE(43)] = 1212,
  [SMALL_STATE(44)] = 1232,
  [SMALL_STATE(45)] = 1252,
  [SMALL_STATE(46)] = 1272,
  [SMALL_STATE(47)] = 1310,
  [SMALL_STATE(48)] = 1348,
  [SMALL_STATE(49)] = 1368,
  [SMALL_STATE(50)] = 1402,
  [SMALL_STATE(51)] = 1440,
  [SMALL_STATE(52)] = 1478,
  [SMALL_STATE(53)] = 1507,
  [SMALL_STATE(54)] = 1536,
  [SMALL_STATE(55)] = 1565,
  [SMALL_STATE(56)] = 1594,
  [SMALL_STATE(57)] = 1612,
  [SMALL_STATE(58)] = 1638,
  [SMALL_STATE(59)] = 1664,
  [SMALL_STATE(60)] = 1688,
  [SMALL_STATE(61)] = 1712,
  [SMALL_STATE(62)] = 1726,
  [SMALL_STATE(63)] = 1752,
  [SMALL_STATE(64)] = 1766,
  [SMALL_STATE(65)] = 1790,
  [SMALL_STATE(66)] = 1808,
  [SMALL_STATE(67)] = 1832,
  [SMALL_STATE(68)] = 1845,
  [SMALL_STATE(69)] = 1864,
  [SMALL_STATE(70)] = 1877,
  [SMALL_STATE(71)] = 1890,
  [SMALL_STATE(72)] = 1905,
  [SMALL_STATE(73)] = 1918,
  [SMALL_STATE(74)] = 1941,
  [SMALL_STATE(75)] = 1954,
  [SMALL_STATE(76)] = 1977,
  [SMALL_STATE(77)] = 1990,
  [SMALL_STATE(78)] = 2003,
  [SMALL_STATE(79)] = 2016,
  [SMALL_STATE(80)] = 2029,
  [SMALL_STATE(81)] = 2044,
  [SMALL_STATE(82)] = 2057,
  [SMALL_STATE(83)] = 2070,
  [SMALL_STATE(84)] = 2083,
  [SMALL_STATE(85)] = 2100,
  [SMALL_STATE(86)] = 2117,
  [SMALL_STATE(87)] = 2130,
  [SMALL_STATE(88)] = 2143,
  [SMALL_STATE(89)] = 2156,
  [SMALL_STATE(90)] = 2179,
  [SMALL_STATE(91)] = 2196,
  [SMALL_STATE(92)] = 2219,
  [SMALL_STATE(93)] = 2232,
  [SMALL_STATE(94)] = 2245,
  [SMALL_STATE(95)] = 2258,
  [SMALL_STATE(96)] = 2271,
  [SMALL_STATE(97)] = 2284,
  [SMALL_STATE(98)] = 2297,
  [SMALL_STATE(99)] = 2310,
  [SMALL_STATE(100)] = 2323,
  [SMALL_STATE(101)] = 2336,
  [SMALL_STATE(102)] = 2349,
  [SMALL_STATE(103)] = 2362,
  [SMALL_STATE(104)] = 2375,
  [SMALL_STATE(105)] = 2388,
  [SMALL_STATE(106)] = 2401,
  [SMALL_STATE(107)] = 2414,
  [SMALL_STATE(108)] = 2427,
  [SMALL_STATE(109)] = 2440,
  [SMALL_STATE(110)] = 2453,
  [SMALL_STATE(111)] = 2466,
  [SMALL_STATE(112)] = 2479,
  [SMALL_STATE(113)] = 2492,
  [SMALL_STATE(114)] = 2505,
  [SMALL_STATE(115)] = 2528,
  [SMALL_STATE(116)] = 2551,
  [SMALL_STATE(117)] = 2564,
  [SMALL_STATE(118)] = 2576,
  [SMALL_STATE(119)] = 2596,
  [SMALL_STATE(120)] = 2616,
  [SMALL_STATE(121)] = 2632,
  [SMALL_STATE(122)] = 2648,
  [SMALL_STATE(123)] = 2660,
  [SMALL_STATE(124)] = 2672,
  [SMALL_STATE(125)] = 2690,
  [SMALL_STATE(126)] = 2706,
  [SMALL_STATE(127)] = 2726,
  [SMALL_STATE(128)] = 2746,
  [SMALL_STATE(129)] = 2762,
  [SMALL_STATE(130)] = 2780,
  [SMALL_STATE(131)] = 2791,
  [SMALL_STATE(132)] = 2806,
  [SMALL_STATE(133)] = 2821,
  [SMALL_STATE(134)] = 2836,
  [SMALL_STATE(135)] = 2847,
  [SMALL_STATE(136)] = 2862,
  [SMALL_STATE(137)] = 2875,
  [SMALL_STATE(138)] = 2890,
  [SMALL_STATE(139)] = 2905,
  [SMALL_STATE(140)] = 2922,
  [SMALL_STATE(141)] = 2935,
  [SMALL_STATE(142)] = 2950,
  [SMALL_STATE(143)] = 2965,
  [SMALL_STATE(144)] = 2980,
  [SMALL_STATE(145)] = 2995,
  [SMALL_STATE(146)] = 3010,
  [SMALL_STATE(147)] = 3025,
  [SMALL_STATE(148)] = 3036,
  [SMALL_STATE(149)] = 3051,
  [SMALL_STATE(150)] = 3066,
  [SMALL_STATE(151)] = 3081,
  [SMALL_STATE(152)] = 3096,
  [SMALL_STATE(153)] = 3109,
  [SMALL_STATE(154)] = 3124,
  [SMALL_STATE(155)] = 3137,
  [SMALL_STATE(156)] = 3151,
  [SMALL_STATE(157)] = 3165,
  [SMALL_STATE(158)] = 3175,
  [SMALL_STATE(159)] = 3189,
  [SMALL_STATE(160)] = 3203,
  [SMALL_STATE(161)] = 3215,
  [SMALL_STATE(162)] = 3229,
  [SMALL_STATE(163)] = 3243,
  [SMALL_STATE(164)] = 3257,
  [SMALL_STATE(165)] = 3271,
  [SMALL_STATE(166)] = 3281,
  [SMALL_STATE(167)] = 3295,
  [SMALL_STATE(168)] = 3305,
  [SMALL_STATE(169)] = 3315,
  [SMALL_STATE(170)] = 3329,
  [SMALL_STATE(171)] = 3343,
  [SMALL_STATE(172)] = 3353,
  [SMALL_STATE(173)] = 3367,
  [SMALL_STATE(174)] = 3381,
  [SMALL_STATE(175)] = 3395,
  [SMALL_STATE(176)] = 3409,
  [SMALL_STATE(177)] = 3419,
  [SMALL_STATE(178)] = 3433,
  [SMALL_STATE(179)] = 3447,
  [SMALL_STATE(180)] = 3457,
  [SMALL_STATE(181)] = 3467,
  [SMALL_STATE(182)] = 3481,
  [SMALL_STATE(183)] = 3495,
  [SMALL_STATE(184)] = 3509,
  [SMALL_STATE(185)] = 3523,
  [SMALL_STATE(186)] = 3537,
  [SMALL_STATE(187)] = 3551,
  [SMALL_STATE(188)] = 3565,
  [SMALL_STATE(189)] = 3579,
  [SMALL_STATE(190)] = 3593,
  [SMALL_STATE(191)] = 3605,
  [SMALL_STATE(192)] = 3619,
  [SMALL_STATE(193)] = 3633,
  [SMALL_STATE(194)] = 3647,
  [SMALL_STATE(195)] = 3661,
  [SMALL_STATE(196)] = 3675,
  [SMALL_STATE(197)] = 3689,
  [SMALL_STATE(198)] = 3703,
  [SMALL_STATE(199)] = 3717,
  [SMALL_STATE(200)] = 3731,
  [SMALL_STATE(201)] = 3745,
  [SMALL_STATE(202)] = 3759,
  [SMALL_STATE(203)] = 3773,
  [SMALL_STATE(204)] = 3787,
  [SMALL_STATE(205)] = 3801,
  [SMALL_STATE(206)] = 3815,
  [SMALL_STATE(207)] = 3829,
  [SMALL_STATE(208)] = 3843,
  [SMALL_STATE(209)] = 3857,
  [SMALL_STATE(210)] = 3871,
  [SMALL_STATE(211)] = 3885,
  [SMALL_STATE(212)] = 3899,
  [SMALL_STATE(213)] = 3913,
  [SMALL_STATE(214)] = 3927,
  [SMALL_STATE(215)] = 3938,
  [SMALL_STATE(216)] = 3949,
  [SMALL_STATE(217)] = 3958,
  [SMALL_STATE(218)] = 3969,
  [SMALL_STATE(219)] = 3980,
  [SMALL_STATE(220)] = 3989,
  [SMALL_STATE(221)] = 3998,
  [SMALL_STATE(222)] = 4009,
  [SMALL_STATE(223)] = 4020,
  [SMALL_STATE(224)] = 4031,
  [SMALL_STATE(225)] = 4042,
  [SMALL_STATE(226)] = 4051,
  [SMALL_STATE(227)] = 4062,
  [SMALL_STATE(228)] = 4071,
  [SMALL_STATE(229)] = 4082,
  [SMALL_STATE(230)] = 4091,
  [SMALL_STATE(231)] = 4100,
  [SMALL_STATE(232)] = 4109,
  [SMALL_STATE(233)] = 4117,
  [SMALL_STATE(234)] = 4125,
  [SMALL_STATE(235)] = 4133,
  [SMALL_STATE(236)] = 4141,
  [SMALL_STATE(237)] = 4149,
  [SMALL_STATE(238)] = 4157,
  [SMALL_STATE(239)] = 4165,
  [SMALL_STATE(240)] = 4173,
  [SMALL_STATE(241)] = 4181,
  [SMALL_STATE(242)] = 4189,
  [SMALL_STATE(243)] = 4197,
  [SMALL_STATE(244)] = 4205,
  [SMALL_STATE(245)] = 4213,
  [SMALL_STATE(246)] = 4221,
  [SMALL_STATE(247)] = 4229,
  [SMALL_STATE(248)] = 4237,
  [SMALL_STATE(249)] = 4245,
  [SMALL_STATE(250)] = 4253,
  [SMALL_STATE(251)] = 4261,
  [SMALL_STATE(252)] = 4269,
  [SMALL_STATE(253)] = 4277,
  [SMALL_STATE(254)] = 4285,
  [SMALL_STATE(255)] = 4293,
  [SMALL_STATE(256)] = 4301,
  [SMALL_STATE(257)] = 4309,
  [SMALL_STATE(258)] = 4317,
  [SMALL_STATE(259)] = 4325,
  [SMALL_STATE(260)] = 4333,
  [SMALL_STATE(261)] = 4341,
  [SMALL_STATE(262)] = 4349,
  [SMALL_STATE(263)] = 4357,
  [SMALL_STATE(264)] = 4365,
  [SMALL_STATE(265)] = 4373,
  [SMALL_STATE(266)] = 4381,
  [SMALL_STATE(267)] = 4389,
  [SMALL_STATE(268)] = 4397,
  [SMALL_STATE(269)] = 4405,
  [SMALL_STATE(270)] = 4413,
  [SMALL_STATE(271)] = 4421,
  [SMALL_STATE(272)] = 4429,
  [SMALL_STATE(273)] = 4437,
  [SMALL_STATE(274)] = 4445,
  [SMALL_STATE(275)] = 4453,
  [SMALL_STATE(276)] = 4461,
  [SMALL_STATE(277)] = 4469,
  [SMALL_STATE(278)] = 4477,
  [SMALL_STATE(279)] = 4485,
  [SMALL_STATE(280)] = 4493,
  [SMALL_STATE(281)] = 4501,
  [SMALL_STATE(282)] = 4509,
  [SMALL_STATE(283)] = 4517,
  [SMALL_STATE(284)] = 4525,
  [SMALL_STATE(285)] = 4533,
  [SMALL_STATE(286)] = 4541,
  [SMALL_STATE(287)] = 4549,
  [SMALL_STATE(288)] = 4557,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(213),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(243),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(208),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(276),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(221),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_body_repeat1, 2, 0, 0), SHIFT_REPEAT(269),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_package_declaration, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_declaration, 1, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identification, 3, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identification, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_definition, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_element, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_occurrence_usage_element, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_annotating_element, 1, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regular_comment, 1, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_body, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_occurrence_usage_element, 2, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_definition, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_documentation, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_member, 2, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship_body, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_stmt, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_body, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition, 2, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_documentation, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship_body, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_usage, 3, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_completion, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_element, 1, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_body, 3, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_documentation, 4, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship_body, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_body, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_definition_body_repeat1, 2, 0, 0),
  [169] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_definition_body_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [172] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_definition_body_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [175] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_definition_body_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_member, 1, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identification, 1, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_declaration, 2, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dependency, 5, 0, 1),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dependency, 6, 0, 2),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dependency, 7, 0, 3),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dependency, 8, 0, 4),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identification, 4, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_body, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(237),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [216] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(124),
  [219] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [222] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(283),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(284),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_member_prefix, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_visibility, 1, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_library_package, 3, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_declaration, 1, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_body, 1, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package, 2, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_prefix, 2, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_body, 3, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_body, 2, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias_member, 1, 0, 0),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root_namespace, 1, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_prefix, 1, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_member, 2, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_name, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_name, 1, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qualified_name_repeat1, 2, 0, 0),
  [299] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qualified_name_repeat1, 2, 0, 0), SHIFT_REPEAT(271),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_library_package, 4, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(205),
  [308] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_prefix, 3, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [322] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qualified_name_repeat1, 2, 0, 0), SHIFT_REPEAT(255),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_name_list, 1, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_imported_membership, 1, 0, 0),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_qualified_name_list, 2, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_imported_membership, 2, 0, 0),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subclassification_part, 3, 0, 0),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subclassification_part, 2, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_qualified_name_list_repeat1, 2, 0, 0),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qualified_name_list_repeat1, 2, 0, 0), SHIFT_REPEAT(228),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_subclassification_part_repeat1, 2, 0, 0),
  [358] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_subclassification_part_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relationship_body_repeat1, 2, 0, 0),
  [365] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_relationship_body_repeat1, 2, 0, 0), SHIFT_REPEAT(166),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_imported_membership_repeat1, 2, 0, 0),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_imported_membership_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_membership_import, 2, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [397] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_specializes_keyword, 1, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_specializes_keyword, 1, 0, 0),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dependency_repeat1, 2, 0, 0),
  [403] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dependency_repeat1, 2, 0, 0), SHIFT_REPEAT(161),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_membership, 1, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_owned_subclassification, 1, 0, 0),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_usage_keyword, 1, 0, 0),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [438] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_qualified_name_list_repeat1, 2, 0, 0), SHIFT_REPEAT(224),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_imported_namespace, 3, 0, 0),
  [449] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_imported_membership_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [454] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_namespace_import, 2, 0, 0),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_declaration, 1, 0, 0),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_declaration, 2, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_owned_annotation, 3, 0, 0),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_imported_namespace, 4, 0, 0),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_basic_usage_prefix, 1, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_usage_prefix, 1, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_definition_prefix, 1, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [542] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [544] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_basic_definition_prefix, 1, 0, 0),
  [546] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [550] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [552] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [554] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [556] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__newline = 0,
  ts_external_token__backslash = 1,
  ts_external_token__nl_comma = 2,
  ts_external_token_float = 3,
  ts_external_token_block_comment = 4,
  ts_external_token_LBRACE = 5,
  ts_external_token_DQUOTE = 6,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__backslash] = sym__backslash,
  [ts_external_token__nl_comma] = sym__nl_comma,
  [ts_external_token_float] = sym_float,
  [ts_external_token_block_comment] = sym_block_comment,
  [ts_external_token_LBRACE] = anon_sym_LBRACE,
  [ts_external_token_DQUOTE] = anon_sym_DQUOTE,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__backslash] = true,
    [ts_external_token__nl_comma] = true,
    [ts_external_token_float] = true,
    [ts_external_token_block_comment] = true,
    [ts_external_token_LBRACE] = true,
    [ts_external_token_DQUOTE] = true,
  },
  [2] = {
    [ts_external_token_block_comment] = true,
  },
  [3] = {
    [ts_external_token_block_comment] = true,
    [ts_external_token_LBRACE] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_sysml_external_scanner_create(void);
void tree_sitter_sysml_external_scanner_destroy(void *);
bool tree_sitter_sysml_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_sysml_external_scanner_serialize(void *, char *);
void tree_sitter_sysml_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_sysml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_sysml_external_scanner_create,
      tree_sitter_sysml_external_scanner_destroy,
      tree_sitter_sysml_external_scanner_scan,
      tree_sitter_sysml_external_scanner_serialize,
      tree_sitter_sysml_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
