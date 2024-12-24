" Vim syntax file
" Language: SysML
" Maintainer: Syntax Highlighter Generator
" Latest Revision: 2024

if exists("b:current_syntax")
  finish
endif

" Keywords
syntax keyword sysmlKeyword about abstract accept action actor after alias all
syntax keyword sysmlKeyword allocate allocation analysis and as assert assign assume
syntax keyword sysmlKeyword at attribute bind binding by calc case comment concern
syntax keyword sysmlKeyword connect connection constraint decide def default defined
syntax keyword sysmlKeyword dependency derived do doc else end entry enum event
syntax keyword sysmlKeyword exhibit exit expose false filter first flow for fork
syntax keyword sysmlKeyword frame from hastype if implies import in include
syntax keyword sysmlKeyword individual inout interface istype item join language
syntax keyword sysmlKeyword library locale loop merge message meta metadata
syntax keyword sysmlKeyword nonunique not null objective occurrence of or ordered
syntax keyword sysmlKeyword out package parallel part perform port private
syntax keyword sysmlKeyword protected public readonly redefines ref references
syntax keyword sysmlKeyword render rendering rep require requirement return satisfy
syntax keyword sysmlKeyword send snapshot specializes stakeholder standard state
syntax keyword sysmlKeyword subject subsets succession then timeslice to transition
syntax keyword sysmlKeyword true until use variant variation verification verify
syntax keyword sysmlKeyword via view viewpoint when while xor

" Comments
syntax region sysmlComment start="/\*" end="\*/" contains=@Spell
syntax match sysmlLineComment "//.*$" contains=@Spell

" Define highlighting
highlight default link sysmlKeyword Keyword
highlight default link sysmlComment Comment
highlight default link sysmlLineComment Comment

let b:current_syntax = "sysml"
