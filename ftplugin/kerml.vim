if exists('b:did_ftplugin_sysmlv2')
    finish
endif
let b:did_ftplugin_sysmlv2 = 1

" KerML specific settings
setlocal omnifunc=v:lua.vim.lsp.omnifunc

" File-specific keymaps
nnoremap <buffer> <LocalLeader>f :lua require('sysmlv2').format()<CR>
nnoremap <buffer> <LocalLeader>r :lua require('sysmlv2').rename()<CR>