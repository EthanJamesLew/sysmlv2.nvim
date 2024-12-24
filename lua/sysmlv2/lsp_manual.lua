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

  -- Configure handler for go to definition
  local function definition_handler(err, method, result, client_id, bufnr, config)
    if err or not result then return end
    
    if vim.tbl_islist(result) and #result > 0 then
      vim.lsp.util.jump_to_location(result[1], "utf-8")
    elseif result.uri then
      vim.lsp.util.jump_to_location(result, "utf-8")
    end
  end

local function underline_and_show_diagnostics(bufnr)
    bufnr = bufnr or vim.api.nvim_get_current_buf()
    local diagnostics = vim.diagnostic.get(bufnr)

    if not diagnostics or vim.tbl_isempty(diagnostics) then
        print("No diagnostics found.")
        return
    end

    -- Namespace for diagnostics
    local ns_id = vim.api.nvim_create_namespace("lsp_diagnostics")
    vim.api.nvim_buf_clear_namespace(bufnr, ns_id, 0, -1)

    for _, diagnostic in ipairs(diagnostics) do
        -- Determine highlight group based on severity
        local hl_group = "DiagnosticUnderlineError"
        if diagnostic.severity == vim.diagnostic.severity.WARN then
            hl_group = "DiagnosticUnderlineWarn"
        elseif diagnostic.severity == vim.diagnostic.severity.INFO then
            hl_group = "DiagnosticUnderlineInfo"
        elseif diagnostic.severity == vim.diagnostic.severity.HINT then
            hl_group = "DiagnosticUnderlineHint"
        end

        -- Highlight the range
        vim.api.nvim_buf_add_highlight(
            bufnr,
            ns_id,
            hl_group,
            diagnostic.lnum,
            diagnostic.col,
            diagnostic.end_col or -1
        )

        -- Add virtual text for diagnostic messages
        local virt_text = string.format("[%s] %s", diagnostic.source or "LSP", diagnostic.message)
        vim.api.nvim_buf_set_extmark(
            bufnr,
            ns_id,
            diagnostic.lnum,
            0,
            {
                virt_text = {{virt_text, "DiagnosticVirtualTextError"}},
                virt_text_pos = "eol",
            }
        )
    end
end

local function diagnostic_handler(err, result, ctx, config)
    if err then
        vim.notify("LSP Error: " .. tostring(err), vim.log.levels.ERROR)
        return
    end

    if not result or not result.diagnostics then
        vim.notify("No diagnostics found", vim.log.levels.INFO)
        return
    end

    local bufnr = ctx.bufnr or vim.api.nvim_get_current_buf()

    -- Create namespace for diagnostics
    local ns_id = vim.api.nvim_create_namespace("lsp_diagnostics")
    vim.api.nvim_buf_clear_namespace(bufnr, ns_id, 0, -1) -- Clear existing diagnostics

    -- Process diagnostics
    for _, diagnostic in ipairs(result.diagnostics) do
        if diagnostic.range then
            -- Highlight the affected range
            local severity = diagnostic.severity or vim.diagnostic.severity.ERROR
            local hl_group = ({
                [vim.diagnostic.severity.ERROR] = "DiagnosticUnderlineError",
                [vim.diagnostic.severity.WARN] = "DiagnosticUnderlineWarn",
                [vim.diagnostic.severity.INFO] = "DiagnosticUnderlineInfo",
                [vim.diagnostic.severity.HINT] = "DiagnosticUnderlineHint",
            })[severity] or "DiagnosticUnderlineError"

            vim.api.nvim_buf_add_highlight(bufnr, ns_id, hl_group,
                diagnostic.range.start.line,
                diagnostic.range.start.character,
                diagnostic.range["end"].character)

            -- Add virtual text for the diagnostic message
            local virt_text = string.format("[%s] %s", diagnostic.source or "LSP", diagnostic.message)
            vim.api.nvim_buf_set_extmark(bufnr, ns_id, diagnostic.range.start.line, 0, {
                virt_text = {{virt_text, hl_group}},
                virt_text_pos = "eol",
            })
        end
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
