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

    owned_expression: $ => $.conditional_expression,

    conditional_expression: $ => choice(
      $.null_coalescing_expression,
      seq(
        $.conditional_operator,
        $.null_coalescing_expression,
        '?',
        $.owned_expression_reference,
        'else',
        $.owned_expression_reference
      )
    ),

    conditional_operator: $ => 'if',

    null_coalescing_expression: $ => seq(
      $.implies_expression,
      repeat(
        seq(
          $.null_coalescing_operator,
          $.implies_expression_reference
        )
      ),
    ),

    owned_expression_reference: $ => $.owned_expression_member,

    null_coalescing_operator: $ => '??',

    implies_expression_reference: $ => $.implies_expression_member,

    implies_expression_member: $ => $.implies_expression,

    owned_expression_member: $ => $.owned_expression,

    implies_expression: $ => seq(
      $.or_expression,
      repeat(
        seq(
          $.implies_operator,
          $.or_expression_reference
        )
      ),
    ),

    implies_operator: $ => 'implies',

    or_expression_reference: $ => $.or_expression_member,

    or_expression_member: $ => $.or_expression,

    or_expression: $ => seq(
      $.xor_expression,
      repeat(
        seq(
          choice(
            seq(
              $.or_operator,
              $.xor_expression
            ),
            seq(
              $.conditional_or_operator,
              $.xor_expression_reference
            )
          )
        )
      ),
    ),

    or_operator: $ => '|',

    conditional_or_operator: $ => 'or',

    xor_expression_reference: $ => $.xor_expression_member,

    xor_expression_member: $ => $.xor_expression,

    xor_expression: $ => seq(
      $.and_expression,
      repeat(
        seq(
          $.xor_operator,
          $.and_expression
        )
      ),
    ),

    xor_operator: $ => 'xor',

    and_expression: $ => seq(
      $.equality_expression,
      repeat(
        seq(
          $.and_operator,
          $.equality_expression_reference
        )
      ),
    ),

    and_operator: $ => '&',

    conditional_and_operator: $ => 'and',

    equality_expression_reference: $ => $.equality_expression_member,

    equality_expression_member: $ => $.equality_expression,

    equality_expression: $ => seq(
      $.classification_expression,
      repeat(
        seq(
          $.equality_operator,
          $.classification_expression
        )
      ),
    ),

    equality_operator: $ => choice(
      '==',
      '!=',
      '===',
      '!==',
    ),

    classification_expression: $ => seq(
      $.relational_expression,
      repeat(
        seq(
          $.classification_operator,
          $.relational_expression_reference
        )
      ),
    ),

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
      $.usage_prefix,
      $.attribute_usage_keyword,
      $.usage
    ),

    attribute_keyword: $ => 'attribute',

    attribute_usage_keyword: $ => $.attribute_keyword,

    usage_prefix: $ => seq(
      $.basic_usage_prefix,
      repeat($.usage_extension_keyword)
    ),

    basic_usage_prefix: $ => seq(
      $.ref_prefix,
      optional('ref'),
    ),

    usage: $ => seq(
      optional($.usage_declaration),
      $.usage_completion,
    ),

    usage_declaration: $ => $.feature_declaration,

    usage_completion: $ => seq(
      optional($.value_part),
      $.usage_body
    ),

    value_part: $ => $.feature_value,

    feature_value: $ => choice(
      $.argument_expression_value,
      $.feature_binding,
      $.target_binding,
      $.satisfaction_feature_value,
      $.feature_value_stmt,
    ),

    feature_value_stmt: $ => seq(
      choice(
        '=',
        ':=',
      ),
      $.owned_expression
    ),

    argument_expression_value: $ => $.owned_expression_reference,

    feature_binding: $ => $.owned_expression,

    target_binding: $ => $.target_expression,

    satisfaction_feature_value: $ => $.satisfaction_reference_expression,

    usage_extension_keyword: $ => choice(
      $.prefix_metadata_member,
    ),

    feature_declaration: $ => seq(
      choice(
        seq(
          $.identification,
          optional($.feature_specialization_part),
        ),
        $.feature_specialization_part
    )),

    feature_specialization_part: $ => seq(
      choice(
        seq(
          $.feature_specialization,
          repeat($.feature_specialization),
          optional($.multiplicity_part),
          repeat($.feature_specialization)
        ),
        seq(
          $.multiplicity_part,
          repeat($.feature_specialization)
        )
    )),

    ref_prefix: $ => seq(
      optional($.feature_direction),
      optional(choice(
        'abstract',
        'variation'
      )),
      optional('readonly'),
      optional('derived'),
      optional('end'),
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
      seq('{', '...TODO...', '}')
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
