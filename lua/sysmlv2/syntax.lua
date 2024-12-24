local M = {}

function M.setup()
  -- Create a highlight group for sysml keywords
  vim.api.nvim_set_hl(0, 'SysmlKeyword', { fg = '#FF8800', bold = true })
  vim.api.nvim_set_hl(0, 'SysmlComment', { fg = '#808080', italic = true })
  vim.api.nvim_set_hl(0, 'SysmlBlockComment', { fg = '#808080', italic = true })

  -- Syntax for keywords
  local sysml_keywords = [[about abstract accept action actor after alias all allocate allocation analysis and as assert assign assume at attribute bind binding by calc case comment concern connect connection constraint decide def default defined dependency derived do doc else end entry enum event exhibit exit expose false filter first flow for fork frame from hastype if implies import in include individual inout interface istype item join language library locale loop merge message meta metadata nonunique not null objective occurrence of or ordered out package parallel part perform port private protected public readonly redefines ref references render rendering rep require requirement return satisfy send snapshot specializes stakeholder standard state subject subsets succession then timeslice to transition true until use variant variation verification verify via view viewpoint when while xor]]

  local keyword_pattern = "\\<\\(" .. sysml_keywords:gsub("%s+", "\\|") .. "\\)\\>"
  vim.api.nvim_command('syntax match SysmlKeyword /' .. keyword_pattern .. '/ containedin=ALL')

  -- Syntax for comments
  vim.api.nvim_command('syntax region SysmlBlockComment start=\"//\\*\" end=\"\\*/\" contains=ALL keepend')
  vim.api.nvim_command('syntax match SysmlComment /\\/\\/.*$/ containedin=ALL')

  -- Attach highlight groups
  vim.api.nvim_command('highlight link SysmlKeyword Keyword')
  vim.api.nvim_command('highlight link SysmlComment Comment')
  vim.api.nvim_command('highlight link SysmlBlockComment Comment')
end

return M

