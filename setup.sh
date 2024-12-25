#!/bin/bash

# Ensure we're in the plugin root directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$SCRIPT_DIR"

# Create the grammar directory structure
mkdir -p lua/sysmlv2/treesitter/grammar/src
mkdir -p lua/sysmlv2/treesitter/grammar/queries/sysml

# Create package.json
cat > lua/sysmlv2/treesitter/grammar/package.json << 'EOF'
{
  "name": "tree-sitter-sysml",
  "version": "1.0.0",
  "description": "SysML grammar for tree-sitter",
  "main": "bindings/node",
  "scripts": {
    "test": "tree-sitter test",
    "build": "tree-sitter generate && node-gyp rebuild",
    "generate": "tree-sitter generate"
  },
  "keywords": ["parser", "sysml"],
  "author": "",
  "license": "MIT",
  "dependencies": {
    "nan": "^2.17.0"
  },
  "devDependencies": {
    "tree-sitter-cli": "^0.20.8"
  }
}
EOF

# Copy the grammar file
cat > lua/sysmlv2/treesitter/grammar/grammar.js << 'EOF'
// grammar.js
module.exports = grammar({
  name: 'sysml',

  conflicts: $ => [
    [$._name_reference, $.type_reference],
    [$.identifier, $.qualified_name]
  ],

  precedences: $ => [
    [
      'qualified_name',
      'type_reference',
      'name_reference'
    ]
  ],

  extras: $ => [
    /\s|\r?\n/,
    $.comment
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.package_def,
      $.part_def,
      $.comment,
      $.import_statement
    ),

    package_def: $ => seq(
      'package',
      field('name', $.identifier),
      '{',
      repeat($._definition),
      '}'
    ),

    part_def: $ => seq(
      'part',
      field('name', $.identifier),
      optional(seq(':', $.type_reference)),
      optional($.block)
    ),

    block: $ => seq(
      '{',
      repeat($._statement),
      '}'
    ),

    _statement: $ => choice(
      $.attribute_def,
      $.value_def,
      $.port_def,
      $.comment
    ),

    attribute_def: $ => seq(
      'attribute',
      field('name', $.identifier),
      ':',
      $.type_reference,
      ';'
    ),

    value_def: $ => seq(
      'value',
      field('name', $.identifier),
      ':',
      $.type_reference,
      optional('='),
      optional($._expression),
      ';'
    ),

    port_def: $ => seq(
      'port',
      field('name', $.identifier),
      optional(seq(':', $.type_reference)),
      ';'
    ),

    type_reference: $ => prec('type_reference', choice(
      $.identifier,
      $.qualified_name
    )),

    _name_reference: $ => prec('name_reference', choice(
      $.identifier,
      $.qualified_name
    )),

    qualified_name: $ => prec.left('qualified_name',
      sep1($.identifier, '.')
    ),

    import_statement: $ => seq(
      'import',
      $.qualified_name,
      ';'
    ),

    _expression: $ => choice(
      $.number,
      $.string,
      $.boolean,
      $._name_reference
    ),

    comment: $ => token(choice(
      seq('//', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    )),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
    number: $ => /\d+(\.\d+)?/,
    string: $ => /"[^"]*"/,
    boolean: $ => choice('true', 'false')
  }
});

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}
EOF

# Create highlights.scm
cat > lua/sysmlv2/treesitter/grammar/queries/sysml/highlights.scm << 'EOF'
;; highlights.scm

; Keywords
[
  "package"
  "part"
  "attribute"
  "value"
  "port"
  "import"
] @keyword

; Identifiers and Names
(identifier) @variable

; Types
(type_reference) @type

; Definitions
(package_def
  name: (identifier) @namespace)

(part_def
  name: (identifier) @function)

(attribute_def
  name: (identifier) @property)

(value_def
  name: (identifier) @variable)

(port_def
  name: (identifier) @variable)

; References
(qualified_name) @variable

; Literals
(number) @number
(string) @string
(boolean) @boolean

; Comments
(comment) @comment

; Operators and Punctuation
[":" "." "=" ";"] @operator

["{" "}" "(" ")"] @punctuation.bracket
EOF

# Navigate to grammar directory
cd lua/sysmlv2/treesitter/grammar

# Clean any existing files
rm -rf src/parser.c src/tree_sitter node_modules

# Install dependencies and generate parser
npm install
npx tree-sitter generate

# Verify parser.c was generated
if [ -f "src/parser.c" ]; then
    echo "Parser generated successfully!"
else
    echo "Error: parser.c was not generated!"
    exit 1
fi

echo "Parser setup complete!"
