-- lua/sysmlv2/lsp_manual.lua
local M = {}

-- Manually start a Syside LSP client and attach it to the current buffer
function M.start_syside(opts)
  opts = opts or {}
  
  -- Path to the proxy script
  local proxy_path = vim.fn.expand("~/sysmlv2.vim/lsp-proxy.js")
  
  -- Configure diagnostic signs
  local signs = {
    Error = "",
    Warn = "",
    Info = "",
    Hint = "",
  }
  
  for type, icon in pairs(signs) do
    local hl = "DiagnosticSign" .. type
    vim.fn.sign_define(hl, { text = icon, texthl = hl, numhl = hl })
  end

  -- Define the diagnostic handler
  local function diagnostic_handler(err, method, params, client_id, bufnr, config)
    -- Safety checks
    if not params then return end
    if not params.uri then return end
    if not params.diagnostics then params.diagnostics = {} end
    
    -- Get buffer number
    local curr_bufnr = bufnr
    if not curr_bufnr then
      curr_bufnr = vim.uri_to_bufnr(params.uri)
    end

    -- Ensure buffer is valid
    if not vim.api.nvim_buf_is_valid(curr_bufnr) then
      return
    end

    -- Ensure the buffer is loaded
    if not vim.api.nvim_buf_is_loaded(curr_bufnr) then
      vim.fn.bufload(curr_bufnr)
    end

    local diagnostics = {}
    for _, d in ipairs(params.diagnostics) do
      if d.range and d.range.start then
        local severity = d.severity or 1
        local diagnostic = {
          lnum = d.range.start.line,
          col = d.range.start.character,
          end_lnum = d.range["end"] and d.range["end"].line or d.range.start.line,
          end_col = d.range["end"] and d.range["end"].character or d.range.start.character,
          severity = severity,
          message = d.message or "",
          source = d.source,
          code = d.code,
        }
        table.insert(diagnostics, diagnostic)
      end
    end

    -- Set diagnostics with protective pcall
    pcall(vim.diagnostic.set, nil, curr_bufnr, diagnostics, {
      underline = true,
      virtual_text = {
        spacing = 4,
        prefix = "●",
      },
      signs = true,
      update_in_insert = false,
    })
  end

  -- Configure handler for go to definition
  local function definition_handler(err, method, result, client_id, bufnr, config)
    if err or not result then return end
    
    if vim.tbl_islist(result) and #result > 0 then
      vim.lsp.util.jump_to_location(result[1], "utf-8")
    elseif result.uri then
      vim.lsp.util.jump_to_location(result, "utf-8")
    end
  end

  -- Define on_attach function
  local function on_attach(client, bufnr)
    vim.keymap.set("n", "gd", function()
      vim.lsp.buf.definition()
    end, { noremap = true, silent = true, buffer = bufnr })
  end

  -- Start with minimal client configuration and required handlers
  local client_id = vim.lsp.start_client({
    name = "syside",
    cmd = {
      "node",
      proxy_path,
      vim.fn.expand(opts.syside_server_path or "~/syside-languageserver.js"),
    },
    on_attach = on_attach,
    handlers = {
      ["textDocument/publishDiagnostics"] = diagnostic_handler,
      ["textDocument/definition"] = definition_handler,
      ["sysml/registerTextEditorCommands"] = function(err, result, ctx, config)
        return vim.NIL
      end,
      ["sysml/findStdlib"] = function(err, result, ctx, config)
        return {
          uri = "file://" .. vim.fn.expand("~/.sysml-2ls")
        }
      end
    },
    capabilities = {
      workspace = {
        configuration = {
          dynamicRegistration = false
        }
      }
    }
  })

  -- Simple attach with error handling
  if client_id then
    local success, err = pcall(vim.lsp.buf_attach_client, 0, client_id)
    if not success then
      vim.notify("[sysmlv2] Failed to attach client: " .. tostring(err), vim.log.levels.ERROR)
      return
    end
    vim.notify("[sysmlv2] LSP client started and attached successfully", vim.log.levels.INFO)
  else
    vim.notify("[sysmlv2] Could not start syside client", vim.log.levels.ERROR)
  end
end

return M
