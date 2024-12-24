local M = {}

function M.setup()
  -- Add filetype detection
  vim.filetype.add({
    extension = {
      sysml = "sysml",
    },
  })

  -- Load the syntax highlighter
  require("sysmlv2.syntax").setup()
end

return M

