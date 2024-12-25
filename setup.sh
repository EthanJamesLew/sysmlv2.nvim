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
module.exports = grammar({
  name: 'sysml',

  conflicts: $ => [
    [$._package_keyword, $.keyword]
  ],

  precedences: $ => [
    [
      'package_definition',
      'part_definition',
      'statement'
    ]
  ],

  rules: {
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.comment,
      $.package_definition,
      $.part_definition,
      $.statement
    ),

    _package_keyword: $ => 'package',
    _part_keyword: $ => 'part',

    statement: $ => seq(
      choice(
        $.keyword,
        $.identifier
      ),
      optional(';')
    ),

    package_definition: $ => prec('package_definition', seq(
      $._package_keyword,
      field('name', $.identifier),
      '{',
      repeat($._definition),
      '}'
    )),

    part_definition: $ => prec('part_definition', seq(
      $._part_keyword,
      optional('def'),
      field('name', $.identifier),
      optional(';')
    )),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    comment: $ => choice(
      seq('//', /[^\n]*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    ),

    keyword: $ => choice(
      'about',
      'abstract',
      'accept',
      'action',
      'actor',
      'after',
      'alias',
      'all',
      'allocate',
      'allocation',
      'analysis',
      'and',
      'as',
      'assert',
      'assign',
      'assume',
      'at',
      'attribute',
      'bind',
      'binding',
      'by',
      'calc',
      'case',
      'comment',
      'concern',
      'connect',
      'connection',
      'constraint',
      'decide',
      'def',
      'default',
      'defined',
      'dependency',
      'derived',
      'do',
      'doc',
      'else',
      'end',
      'entry',
      'enum',
      'event',
      'exhibit',
      'exit',
      'expose',
      'false',
      'filter',
      'first',
      'flow',
      'for',
      'fork',
      'frame',
      'from',
      'hastype',
      'if',
      'implies',
      'import',
      'in',
      'include',
      'individual',
      'inout',
      'interface',
      'istype',
      'item',
      'join',
      'language',
      'library',
      'locale',
      'loop',
      'merge',
      'message',
      'meta',
      'metadata',
      'nonunique',
      'not',
      'null',
      'objective',
      'occurrence',
      'of',
      'or',
      'ordered',
      'out',
      'parallel',
      'perform',
      'port',
      'private',
      'protected',
      'public',
      'readonly',
      'redefines',
      'ref',
      'references',
      'render',
      'rendering',
      'rep',
      'require',
      'requirement',
      'return',
      'satisfy',
      'send',
      'snapshot',
      'specializes',
      'stakeholder',
      'standard',
      'state',
      'subject',
      'subsets',
      'succession',
      'then',
      'timeslice',
      'to',
      'transition',
      'true',
      'until',
      'use',
      'variant',
      'variation',
      'verification',
      'verify',
      'via',
      'view',
      'viewpoint',
      'when',
      'while',
      'xor'
    )
  }
});
EOF

# Create highlights.scm
cat > lua/sysmlv2/treesitter/grammar/queries/sysml/highlights.scm << 'EOF'
;; Keywords
(keyword) @keyword

;; Identifiers
(identifier) @variable

;; Comments
(comment) @comment

;; Operators and delimiters
["{" "}"] @punctuation.bracket
";" @punctuation.delimiter

;; Special keywords
((keyword) @keyword.function
  (#match? @keyword.function "^(def|part|action|function)$"))

((keyword) @keyword.control
  (#match? @keyword.control "^(package|if|then|else|while|for|loop|return)$"))
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
