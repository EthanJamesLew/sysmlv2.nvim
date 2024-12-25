local M = {}

function M.setup(opts)
    -- Debug info about nvim-treesitter
    local has_ts, ts = pcall(require, 'nvim-treesitter.configs')
    print("Has treesitter:", has_ts)
    if not has_ts then
        vim.notify('nvim-treesitter not found', vim.log.levels.ERROR)
        return
    end

    -- Get and verify paths
    local plugin_path = debug.getinfo(1).source:match("@?(.*/)")
    local grammar_path = plugin_path .. "grammar"
    local plugin_root = vim.fn.fnamemodify(plugin_path, ':h:h:h')
    
    -- Print paths for debugging
    print("Plugin path:", plugin_path)
    print("Grammar path:", grammar_path)
    print("Plugin root:", plugin_root)

    -- Verify queries directory exists
    local queries_path = plugin_root .. '/queries/sysml'
    local queries_exists = vim.fn.isdirectory(queries_path) == 1
    print("Queries path exists:", queries_exists)
    if queries_exists then
        local files = vim.fn.readdir(queries_path)
        print("Files in queries directory:", vim.inspect(files))
    end

    -- Try to ensure the queries directory is created
    vim.fn.mkdir(queries_path, 'p')

    -- Create the highlights query file
    local query_content = [[
;; Package definitions
(package_definition) @definition
(package_kw) @keyword

;; Part definitions
(part_definition) @definition
(part_kw) @keyword

;; Special keywords
(def_kw) @keyword.function

;; Regular keywords
(keyword) @keyword

;; Identifiers
(identifier) @variable
(package_definition 
  name: (identifier) @namespace)
(part_definition
  name: (identifier) @type)

;; Comments
(comment) @comment

;; Delimiters
(left_brace) @punctuation.bracket
(right_brace) @punctuation.bracket
(semicolon) @punctuation.delimiter
    ]]

    local query_file = queries_path .. '/highlights.scm'
    local f = io.open(query_file, 'w')
    if f then
        f:write(query_content)
        f:close()
        print("Created query file at:", query_file)
    else
        print("Failed to create query file")
    end

    -- Add query path to runtimepath
    vim.opt.runtimepath:prepend(plugin_root)

    -- Register the parser
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
            additional_vim_regex_highlighting = false,
        },
    })

    -- Add debug command
    vim.api.nvim_create_user_command('DebugSysMLTS', function()
        print("Current filetype:", vim.bo.filetype)
        
        -- Check parser
        local parser = vim.treesitter.get_parser(0)
        print("Parser exists:", parser ~= nil)
        if parser then
            print("Parser language:", parser:lang())
            local tree = parser:parse()[1]
            local root = tree:root()
            print("Root node type:", root:type())
        end
        
        -- Check runtime paths
        local runtime_paths = vim.api.nvim_get_runtime_file("queries/sysml/*.scm", true)
        print("Query files found:", vim.inspect(runtime_paths))
        
        -- Try to load query directly
        pcall(function()
            local query = vim.treesitter.query.get_query('sysml', 'highlights')
            print("Query loaded:", query ~= nil)
        end)
        
        -- Check nvim-treesitter status
        local configs = require('nvim-treesitter.configs')
        print("Highlight enabled:", configs.is_enabled("highlight", "sysml"))
    end, {})

    -- Create autocommand for SysML files
    vim.api.nvim_create_autocmd("FileType", {
        pattern = "sysml",
        callback = function(args)
            vim.notify("SysML file detected, attempting to enable highlighting")
            pcall(vim.cmd, "TSBufEnable highlight")
            -- Try to force highlighting refresh
            vim.cmd([[syntax enable]])
            vim.cmd([[syntax sync fromstart]])
        end
    })
end

return M
