module.exports = grammar({
  name: 'sysml',

  externals: $ => [
    $._newline,
    $._backslash,
    $._nl_comma,
    $.float,
    $.block_comment,
    '{',
    '"',
  ],

  extras: $ => [
    $.comment,
    $.block_comment,
    /\s/,
  ],

  rules: {
    source_file: $ => repeat(
      choice(
        $.root_namespace,
        $.dependency,
      )
    ),
    
    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    string_literal: $ => token(seq(
      '"',
      /[^"]*/,
      '"'
    )),

    root_namespace: $ => seq(
      choice(
        $.package,
        $.library_package
      ),
    ),

    package: $ => seq(
      $.package_declaration,
      $.package_body
    ),

    library_package: $ => seq(
      optional('standard'),
      'library',
      $.package_declaration,
      $.package_body
    ),

    package_declaration: $ => seq(
      'package',
      optional($.identification),
    ), 

    package_body: $ => choice(
      seq(';'),
      seq(
        '{',
        repeat(
          choice(
            $.package_member,
            $.import_stmt
          )
        ),
        '}'
      )
    ),

    package_member: $ => seq(
      optional($.member_prefix),
      choice(
        $.definition_element,
        $.usage_element
      )
    ),

    member_prefix: $ => prec(-1, choice(
      'public',
      'private',
      'protected'
    )),

    definition_element: $ => choice(
      $.package_declaration,
      $.annotating_element,
      $.dependency,
      $.attribute_definition,
    ),

    dependency: $ => seq(
      // optional repeated prefix metadata
      repeat($.prefix_metadata_annotation),
      'dependency',
      optional(seq(
        optional($.identification),
        'from'
      )),
      // a simplified list of clients
      field('clients', $.qualified_name_list),
      'to',
      // a simplified list of suppliers
      field('suppliers', $.qualified_name_list),
      // relationship body => for example, either ';' or '{ ... }'
      $.relationship_body
    ),


    import_stmt: $ => seq(
      choice(
        $.membership_import,
        $.namespace_import,
      ),
      $.relationship_body
    ),

    membership_import: $ => seq(
      $.import_prefix,
      $.imported_membership,
    ),

    imported_membership: $ => prec.left(seq(
      choice(
        $.membership,
        $.qualified_name
      ),
      repeat(seq('::', choice($.membership, $.qualified_name))),
    )),

    imported_namespace: $ => prec(1, seq(
      choice(
        $.imported_membership,
        $.qualified_name
      ),
      repeat(seq('::', choice($.membership, $.qualified_name))),
      '::',
      '*'
    )),

    membership: $ => choice(
      $.member_prefix,
      $.alias_member,
      $.initial_node_member,
      $.transition_source_member,
    ),

    alias_member: $ => prec(-1, seq(
      'TODO'
    )),

    initial_node_member: $ => prec(-2, seq(
      'TODO'
    )),

    transition_source_member: $ => prec(-3, seq(
      'TODO'
    )),

    namespace_import: $ => seq(
      $.import_prefix,
      $.imported_namespace,
    ),

    import_prefix: $ => seq(
      optional($.visibility),
      'import',
      optional('all')
    ),

    visibility: $ => choice(
      'public',
      'private',
      'protected'
    ),

    usage_element: $ => choice(
      $.non_occurrence_usage_element,
      $.occurrence_usage_element
    ),

    non_occurrence_usage_element: $ => choice(
      $.attribute_usage
    ),

    occurrence_usage_element: $ => choice(
      // e.g. occurrence usage, item usage, part usage, etc.
      // For now, just a placeholder
      seq('occurrence', $.usage_body)
    ),

    attribute_usage: $ => seq(
      optional($.usage_prefix),
      $.attribute_usage_keyword,
      $.usage
    ),

    attribute_keyword: $ => 'attribute',

    attribute_usage_keyword: $ => $.attribute_keyword,

    usage_prefix: $ => seq(
      $.basic_usage_prefix,
    ),

    basic_usage_prefix: $ => seq(
      'ref',
    ),

    usage: $ => seq(
      optional($.usage_declaration),
      $.usage_completion,
    ),

    usage_declaration: $ => "TODO",

    usage_completion: $ => seq(
      $.usage_body
    ),

    identification: $ => choice(
      seq('<', $.identifier, '>', optional($.identifier)),
      $.identifier
    ),

    prefix_metadata_annotation: $ => token('#'),

    qualified_name_list: $ => seq(
      $.qualified_name,
      repeat(seq(',', $.qualified_name))
    ),

    relationship_body: $ => choice(
      seq(';'),
      seq('{', repeat($.owned_annotation), '}')
    ),

    qualified_name: $ => seq(
      $.identifier,
      repeat(seq('.', $.identifier))
    ),

    qualified_name_list: $ => seq(
      $.qualified_name,
      repeat(seq(',', $.qualified_name))
    ),

    usage_body: $ => choice(
      ';',
      seq('{', repeat($.any), '}')
    ),

    annotating_element: $ => prec(1, choice(
      $.regular_comment,
      $.documentation
    )),

    attribute_definition: $ => seq(
      optional($.definition_prefix),
      $.attribute_def_keyword,
      $.definition
    ),

    basic_definition_prefix: $ => choice(
      'abstract',
      'variation'
    ),

    definition_prefix: $ => seq(
      $.basic_definition_prefix,
      //repeat($.definition_extension_keyword)
    ),

    //definition_extension_keyword: $ => $.prefix_metadata_keyword,

    definition: $ => seq(
      $.definition_declaration,
      $.definition_body
    ),

    definition_declaration: $ => seq(
      $.identification,
      optional($.subclassification_part),
    ),
    
    definition_body: $ => choice(
      seq(';'),
      seq(
        '{',
        repeat(
          choice(
            $.definition_member,
            $.alias_member,
            $.import_stmt
          )
        ),
        '}'
      )
    ),

    definition_member: $ => seq(
      $.member_prefix,
      $.definition_element,
    ),

    subclassification_part: $ => prec.left(seq(
      $.specializes_keyword,
      $.owned_subclassification,
      repeat( seq(
        ',',
        $.owned_subclassification
      ))
    )),

    specializes_keyword: $ => choice(
      'specializes',
      ':>'
    ),

    owned_subclassification: $ => choice(
      $.qualified_name,
      $.subclassification_part
    ),

    attribute_def_keyword: $ => 'def',

    owned_annotation: $ => seq(
      // e.g. could be a reference to the annotated element
      'comment', $.identification, $.regular_comment
      // this is obviously incomplete — just to show structure
    ),

    comment: $ => token(seq('//', /[^\r\n]*/)),

    regular_comment: $ => prec(-2, choice(
      $.comment,
      $.block_comment
    )),

    documentation: $ => prec(-1, seq(
      optional('doc'),
      optional(seq(
        'locale', 
        $.string_literal
      )),
      $.regular_comment
    )),
  }
});
