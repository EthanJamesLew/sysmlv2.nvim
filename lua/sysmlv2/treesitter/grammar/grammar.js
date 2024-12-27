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
