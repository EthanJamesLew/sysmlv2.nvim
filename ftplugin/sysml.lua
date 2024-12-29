-- ftplugin/sysml.lua
vim.bo.commentstring = '//%s'
vim.bo.expandtab = true
vim.bo.shiftwidth = 2
vim.bo.softtabstop = 2
vim.bo.tabstop = 2

-- We will not use treesitter for now
-- Safely enable tree-sitter features
-- if vim.fn.exists(':TSBufEnable') == 2 then
--     pcall(vim.cmd, 'TSBufEnable highlight')
-- end

-- Use the vim syntax highlighting
vim.cmd('syntax on')
vim.cmd('set syntax=sysml')

-- Turn on the lsp
require('sysmlv2.lsp').start_syside()
