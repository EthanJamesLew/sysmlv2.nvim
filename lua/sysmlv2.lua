local M = {}

function M.setup()
    local lspconfig = require('lspconfig')
    local configs = require('lspconfig.configs')

    -- Create capabilities
    local capabilities = vim.lsp.protocol.make_client_capabilities()
    capabilities.textDocument.semanticTokens = {
        dynamicRegistration = true,
        requests = {
            full = true
        }
    }

    -- Set up highlight groups
    local function setup_highlights()
        local highlights = {
            ["@lsp.type.keyword"] = { link = "Keyword" },
            ["@lsp.type.type"] = { link = "Type" },
            ["@lsp.type.string"] = { link = "String" },
            ["@lsp.type.comment"] = { link = "Comment" },
            ["@lsp.type.function"] = { link = "Function" },
            ["@lsp.type.variable"] = { link = "Identifier" },
            ["@lsp.type.operator"] = { link = "Operator" }
        }

        for group_name, group_settings in pairs(highlights) do
            vim.api.nvim_set_hl(0, group_name, group_settings)
        end
    end

    -- Register custom server configuration
    if not configs.sysmlv2 then
        configs.sysmlv2 = {
            default_config = {
                cmd = { 
                    'node',
                    '/Users/ethanlew/sysmlv2.vim/lsp/syside-languageserver.js',
                    '--stdio'
                },
                filetypes = { 'sysml', 'kerml' },
                root_dir = function(fname)
                    return lspconfig.util.find_git_ancestor(fname) or
                           vim.loop.os_homedir()
                end,
                capabilities = capabilities,
                handlers = {
                    ["sysml/registerTextEditorCommands"] = function(err, result, ctx)
                        return { registered = true }
                    end,
                    ["sysml/findStdlib"] = function(err, result, ctx)
                        return { stdlib = "/Users/ethanlew/.sysml-2ls/sysml.library" }
                    end
                },
                flags = {
                    debounce_text_changes = 150,
                }
            }
        }
    end

    -- Setup the language server
    lspconfig.sysmlv2.setup({
        on_attach = function(client, bufnr)
            setup_highlights()
            
            if client.server_capabilities.semanticTokensProvider then
                -- Enable semantic tokens
                vim.lsp.semantic_tokens.start(bufnr, client.id)
                print("Semantic tokens enabled for buffer " .. bufnr)
                
                -- Print capabilities for debugging
                print("Server semantic tokens capabilities:")
                print(vim.inspect(client.server_capabilities.semanticTokensProvider))
            else
                print("Server does not support semantic tokens")
            end
        end,
        capabilities = capabilities,
    })
end

return M