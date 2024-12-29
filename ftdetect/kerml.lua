-- Force reload filetype detection
vim.cmd([[
    augroup filetypedetect
        au! BufRead,BufNewFile *.kerml setfiletype kerml
    augroup END
]])
