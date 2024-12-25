-- ftdetect/sysml.lua
vim.filetype.add({
    extension = {
        sysml = 'sysml',
    },
    filename = {
        ['.sysml'] = 'sysml',
    },
})

-- Force reload filetype detection
vim.cmd([[
    augroup filetypedetect
        au! BufRead,BufNewFile *.sysml setfiletype sysml
    augroup END
]])
