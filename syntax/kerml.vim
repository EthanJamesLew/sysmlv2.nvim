" Vim syntax file for kerml

if exists("b:current_syntax")
  finish
endif

syn case match

" Keywords
syn keyword kermlKeyword about abstract alias all and as assoc behavior binding bool by chains
syn keyword kermlKeyword class classifier comment composite conjugate conjugates conjugation
syn keyword kermlKeyword connector datatype default dependency derived differences disjoining
syn keyword kermlKeyword disjoint doc else end expr false feature featured featuring filter first
syn keyword kermlKeyword flow for from function hastype if implies import in inout interaction
syn keyword kermlKeyword intersects inv inverse inverting istype language library locale member
syn keyword kermlKeyword meta metaclass metadata multiplicity namespace nonunique not null of or
syn keyword kermlKeyword ordered out package portion predicate private protected public readonly
syn keyword kermlKeyword redefines redefinition references rep return specialization specializes
syn keyword kermlKeyword standard step struct subclassifier subset subsets subtype succession
syn keyword kermlKeyword then to true type typed typing unions xor

" Comments
syn region kermlBlockComment start=/\/\*/ end=/\*\// contains=@Spell
syn match kermlLineComment "//.*" contains=@Spell

" Strings
syn region kermlString start='"' skip='\\' end='"'

" Numbers (integers and floats)
syn match kermlNumber "\<\d\+\.\d\+\>" " Float"
syn match kermlNumber "\<\d\+\>" " Integer"

" Booleans
syn keyword kermlBoolean true false

" Special Operators
syn match kermlOperator ":>>\|:>\|::\|:\|=>\|=\|==\|!=\|<>\|<\|<=\|>\|>=\|&&\|\.\."

" Highlighting Groups
hi def link kermlKeyword Keyword
hi def link kermlBlockComment Comment
hi def link kermlLineComment Comment
hi def link kermlString String
hi def link kermlNumber Number
hi def link kermlBoolean Boolean
hi def link kermlOperator Operator

let b:current_syntax = "kerml"

