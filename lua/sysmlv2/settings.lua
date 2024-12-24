-- lua/sysmlv2/settings.lua
local M = {}

local default_settings = {
  -- Path to your Syside language server, e.g. built from syside-languageserver.js
  syside_server_path = "~/dev/syside-languageserver/dist/syside-languageserver.js",
}

function M.setup(user_opts)
  local opts = user_opts or {}
  for k, v in pairs(opts) do
    default_settings[k] = v
  end
  return default_settings
end

return M

