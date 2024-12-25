-- ftplugin/sysml.lua
vim.bo.commentstring = '//%s'
vim.bo.expandtab = true
vim.bo.shiftwidth = 2
vim.bo.softtabstop = 2
vim.bo.tabstop = 2

-- Safely enable tree-sitter features
if vim.fn.exists(':TSBufEnable') == 2 then
    pcall(vim.cmd, 'TSBufEnable highlight')
end
