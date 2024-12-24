-- lua/sysmlv2/lsp.lua
local M = {}

function M.setup(opts)
  -- 1) Load nvim-lspconfig safely
  local ok, lspconfig = pcall(require, "lspconfig")
  if not ok then
    vim.notify("[sysmlv2] nvim-lspconfig not found! Please install it.", vim.log.levels.ERROR)
    return
  end

  -- 2) Path to syside-languageserver.js (expand ~)
  local syside_path = vim.fn.expand(
    (opts and opts.syside_server_path) or "~/dev/syside-languageserver/dist/syside-languageserver.js"
  )

  -- 3) Build the command
  local cmd = { "node", syside_path, "--stdio" }

  -- 4) (Optional) nvim-cmp capabilities
  local capabilities = vim.lsp.protocol.make_client_capabilities()
  pcall(function()
    local cmp_lsp = require("cmp_nvim_lsp")
    capabilities = cmp_lsp.default_capabilities(capabilities)
  end)

  -- 5) Define on_attach with your keymaps, etc.
  local function on_attach(client, bufnr)
    local opts = { noremap = true, silent = true, buffer = bufnr }
    vim.keymap.set("n", "K",         vim.lsp.buf.hover,         opts)
    vim.keymap.set("n", "gd",        vim.lsp.buf.definition,     opts)
    vim.keymap.set("n", "gi",        vim.lsp.buf.implementation, opts)
    vim.keymap.set("n", "gr",        vim.lsp.buf.references,     opts)
    vim.keymap.set("n", "<leader>rn", vim.lsp.buf.rename,        opts)
    vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action,   opts)

    -- Optional: Auto-format if server supports it
    if client.server_capabilities.documentFormattingProvider then
      vim.api.nvim_create_autocmd("BufWritePre", {
        group = vim.api.nvim_create_augroup("Sysmlv2FormatOnSave", { clear = true }),
        buffer = bufnr,
        callback = function()
          vim.lsp.buf.format({ async = false })
        end,
      })
    end
  end

  -- 6) **Define** the custom server under `configs.syside` if it’s not already there
  if not lspconfig.configs.syside then
    lspconfig.configs.syside = {
      default_config = {
        cmd = cmd,
        filetypes = { "sysml" },   -- or "syside", etc.
        root_dir = function(fname)
          return lspconfig.util.root_pattern("syside.config", ".git")(fname)
            or lspconfig.util.path.dirname(fname)
        end,
        on_attach = on_attach,
        capabilities = capabilities,
        settings = {
          -- if syside-languageserver supports extra settings:
          -- syside = { diagnostics = { enabled = true }, ... }
        },
      },
    }
  end

  -- 7) Now you can safely call `.setup()` on `lspconfig.syside`
  lspconfig.syside.setup({})
end

return M

