-- iflycli_sample.lua
-- Example FSUIPC Lua script using LuaJIT FFI to call the iflycli_dll DLL

local ffi = require("ffi")

ffi.cdef[[
    int ifly_set_command(const char* command, const char* value);
    int ifly_get_command(const char* command, char* out_value, int out_value_len);
    int ifly_list_commands(char* out_buf, int buf_len);
]]

-- Load the DLL (must be in the Modules folder or same directory as this script)
local dll = ffi.load("iflycli_dll")

-- Set a command (e.g., turn on landing light 1)
local set_result = dll.ifly_set_command("landing_light_1", "on")
print("Set landing_light_1 result:", set_result)

-- Get a command value
local buf = ffi.new("char[64]")
dll.ifly_get_command("landing_light_1", buf, 64)
print("landing_light_1 value:", ffi.string(buf))

-- List all available commands
local list_buf = ffi.new("char[4096]")
dll.ifly_list_commands(list_buf, 4096)
print("Available commands:\n" .. ffi.string(list_buf))
