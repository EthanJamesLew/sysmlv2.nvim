-- ftplugin/sysml.lua
vim.bo.commentstring = '//%s'
vim.bo.expandtab = true
vim.bo.shiftwidth = 2
vim.bo.softtabstop = 2
vim.bo.tabstop = 2

-- Use the vim syntax highlighting
vim.cmd('syntax on')
vim.cmd('set syntax=sysml')

-- Turn on the lsp
require('sysmlv2.lsp').start_syside()
