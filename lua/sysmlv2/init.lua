local M = {}

-- Default configuration
M.config = {
  lsp = {
    enabled = true,
    -- Your existing LSP config options
  },
}

-- Setup function
function M.setup(opts)
  -- Merge user config with defaults
  M.config = vim.tbl_deep_extend('force', M.config, opts or {})

  -- Setup LSP if enabled
  if M.config.lsp.enabled then
    require('sysmlv2.lsp').start_syside()
  end
end

return M
