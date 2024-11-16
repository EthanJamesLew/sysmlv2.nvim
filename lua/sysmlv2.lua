local M = {}
local util = require('lspconfig.util')

-- Create the server configuration first
local configs = require('lspconfig.configs')
if not configs.sysmlv2 then
    configs.sysmlv2 = {
        default_config = {
            cmd = { 
                '/Users/ethanlew/sysmlv2.vim/server-wrapper.js'
            },
            filetypes = { 'sysml', 'kerml' },
            root_dir = function(fname)
                return util.root_pattern('.git', 'syside.json')(fname) or vim.fn.getcwd()
            end,
            capabilities = vim.lsp.protocol.make_client_capabilities(),
            handlers = {
                ["workspace/executeCommand"] = function(err, result, ctx, config)
                    if err then
                        vim.notify("Command error: " .. vim.inspect(err), vim.log.levels.ERROR)
                        return
                    end
                    return result
                end,
                ["sysml/registerTextEditorCommands"] = function(err, result, ctx, config)
                    -- Just acknowledge the registration
                    return { registered = true }
                end
            }
        }
    }
end

local lspconfig = require('lspconfig')

function M.setup()
    vim.notify('Setting up SysMLv2 language server...', vim.log.levels.INFO)
    
    lspconfig.sysmlv2.setup({
        on_attach = function(client, bufnr)
            vim.notify('SysMLv2 LSP attached to buffer ' .. bufnr, vim.log.levels.INFO)
            
            -- Set up buffer-local keymaps
            local opts = { noremap=true, silent=true, buffer=bufnr }
            
            -- Core LSP features
            vim.keymap.set('n', 'gd', vim.lsp.buf.definition, opts)
            vim.keymap.set('n', 'K', vim.lsp.buf.hover, opts)
            vim.keymap.set('n', 'gr', vim.lsp.buf.references, opts)
            vim.keymap.set('n', '<leader>rn', vim.lsp.buf.rename, opts)
            vim.keymap.set('n', '<leader>f', function()
                vim.lsp.buf.format({ async = true })
            end, opts)
            
            -- Set up completion
            vim.bo[bufnr].omnifunc = 'v:lua.vim.lsp.omnifunc'
            
            -- Register commands
            if client.server_capabilities.executeCommandProvider then
                local commands = {
                    ["syside.editorCommands"] = "EditorCommands",
                    ["syside.editorCommands.console"] = "EditorCommandsConsole",
                    ["syside.simpleCommands"] = "SimpleCommands",
                    ["syside.simpleCommands.console"] = "SimpleCommandsConsole",
                    ["syside.allCommands"] = "AllCommands",
                    ["syside.allCommands.console"] = "AllCommandsConsole",
                    ["syside.updateDocument"] = "UpdateDocument",
                    ["syside.updateDocument.console"] = "UpdateDocumentConsole"
                }
                
                for lsp_cmd, cmd_suffix in pairs(commands) do
                    local cmd_name = "Syside" .. cmd_suffix
                    vim.api.nvim_create_user_command(cmd_name, function(args)
                        vim.notify("Executing command: " .. lsp_cmd, vim.log.levels.INFO)
                        client.request('workspace/executeCommand', {
                            command = lsp_cmd,
                            arguments = args.fargs
                        }, function(err, result)
                            if err then
                                vim.notify("Command error: " .. vim.inspect(err), vim.log.levels.ERROR)
                            else
                                vim.notify("Command completed: " .. vim.inspect(result), vim.log.levels.INFO)
                            end
                        end, bufnr)
                    end, {
                        nargs = '*',
                        desc = 'Execute ' .. lsp_cmd
                    })
                end
            end
            
            -- Print capabilities for debugging
            vim.notify("Server capabilities: " .. vim.inspect(client.server_capabilities), vim.log.levels.DEBUG)
        end,
        flags = {
            debounce_text_changes = 150,
            allow_incremental_sync = true,
        }
    })
end

return M