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
    source_file: $ => repeat($._definition),

    _definition: $ => choice(
      $.comment,
      $.block_comment,
      $._statement,
    ),

    _statement: $ => choice(
      $.keyword,
      $.identifier,
    ),

    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,

    comment: _ => token(seq('//', /[^\r\n]*/)),

    keyword: $ => prec(1, choice(
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
      'package',
      'parallel',
      'part',
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
    )),
  }
});
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
