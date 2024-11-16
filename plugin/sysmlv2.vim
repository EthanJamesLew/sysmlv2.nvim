if exists('g:loaded_sysmlv2')
    finish
endif
let g:loaded_sysmlv2 = 1

" Global plugin settings
let g:sysmlv2_enable = get(g:, 'sysmlv2_enable', 1)
let g:sysmlv2_debug = get(g:, 'sysmlv2_debug', 0)

" Register filetypes if not already registered
au BufNewFile,BufRead *.sysml setfiletype sysml
au BufNewFile,BufRead *.kerml setfiletype kerml

" Configure the language server
if has('nvim')
    lua require('sysmlv2').setup()
endif

" Define any global commands
command! SysMLEnable lua require('sysmlv2').enable()
command! SysMLDisable lua require('sysmlv2').disable()
command! SysMLStatus lua require('sysmlv2').status()