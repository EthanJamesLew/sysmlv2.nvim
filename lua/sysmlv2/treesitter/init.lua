local M = {}

function M.setup(opts)
    -- Check for nvim-treesitter
    local has_ts, ts = pcall(require, 'nvim-treesitter.configs')
    if not has_ts then
        vim.notify('nvim-treesitter not found', vim.log.levels.WARN)
        return
    end

    -- Get the actual path to our grammar directory
    local plugin_path = debug.getinfo(1).source:match("@?(.*/)")
    local grammar_path = plugin_path .. "grammar"

    -- Add our queries path to runtimepath
    local queries_path = vim.fn.fnamemodify(plugin_path .. "grammar/queries", ":p")
    vim.opt.runtimepath:append(vim.fn.fnamemodify(queries_path, ":h"))

    -- Register the SysML parser
    local parser_configs = require('nvim-treesitter.parsers').get_parser_configs()
    parser_configs.sysml = {
        install_info = {
            url = grammar_path,
            files = { 'src/parser.c' },
            generate_requires_npm = false,
            requires_generate_from_grammar = false,
        },
        filetype = 'sysml',
    }

    -- Configure nvim-treesitter
    ts.setup({
        highlight = {
            enable = true,
            disable = {},
            additional_vim_regex_highlighting = false,
        },
        indent = {
            enable = true,
        },
    })

    -- Create an autocommand to ensure highlighting is enabled
    vim.api.nvim_create_autocmd({ "FileType" }, {
        pattern = "sysml",
        callback = function(args)
            local buf = args.buf
            
            -- Ensure parser is created
            if not vim.treesitter.get_parser(buf) then
                vim.treesitter.get_parser(buf, 'sysml')
            end
            
            -- Force enable highlighting
            pcall(vim.cmd, 'TSBufEnable highlight')
        end,
    })
end

return M
