" Vim syntax file for sysml

if exists("b:current_syntax")
  finish
endif

syn case match 

" Keywords
syn keyword sysmlKeyword about abstract accept action actor after alias all allocate allocation
syn keyword sysmlKeyword analysis and as assert assign assume at attribute bind binding by calc
syn keyword sysmlKeyword case comment concern connect connection constraint decide def default
syn keyword sysmlKeyword defined dependency derived do doc else end entry enum event exhibit
syn keyword sysmlKeyword exit expose false filter first flow for fork frame from hastype if
syn keyword sysmlKeyword implies import in include individual inout interface istype item join
syn keyword sysmlKeyword language library locale loop merge message meta metadata nonunique not
syn keyword sysmlKeyword null objective occurrence of or ordered out package parallel part
syn keyword sysmlKeyword perform port private protected public readonly redefines ref references
syn keyword sysmlKeyword render rendering rep require requirement return satisfy send snapshot
syn keyword sysmlKeyword specializes stakeholder standard state subject subsets succession then
syn keyword sysmlKeyword timeslice to transition true until use variant variation verification
syn keyword sysmlKeyword verify via view viewpoint when while xor

" Comments
syn region sysmlBlockComment start=/\/\*/ end=/\*\// contains=@Spell
syn match sysmlLineComment "//.*" contains=@Spell

" Strings
syn region sysmlString start='"' skip='\\' end='"'

" Numbers (integers and floats)
syn match sysmlNumber "\<\d\+\.\d\+\>" " Float"
syn match sysmlNumber "\<\d\+\>" " Integer"

" Booleans
syn keyword sysmlBoolean true false

" Special Operators
syn match sysmlOperator ":>>\|:>\|::\|:\|=>\|=\|==\|!=\|<>\|<\|<=\|>\|>=\|&&\|\.\."

" Highlighting Groups
hi def link sysmlKeyword Keyword
hi def link sysmlBlockComment Comment
hi def link sysmlLineComment Comment
hi def link sysmlString String
hi def link sysmlNumber Number
hi def link sysmlBoolean Boolean
hi def link sysmlOperator Operator

let b:current_syntax = "sysml"

