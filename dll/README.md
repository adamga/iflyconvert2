# iflycli_dll

A C++ DLL that exposes a C API for setting, getting, and listing iFly 737 MAX 8 commands. This DLL is designed for integration with Lua scripts via FFI, FSUIPC, or any other environment that can load standard C DLLs.

## Building

You can build the DLL using the provided batch file:

```bat
build_dll.bat
```

Or use Visual Studio to open the folder and build the DLL target. The DLL will be output as `iflycli_dll.dll`.

## API

See `iflycli_dll.h` for the exported functions:

- `int ifly_set_command(const char* command, const char* value);`
- `int ifly_get_command(const char* command, char* out_value, int out_value_len);`
- `int ifly_list_commands(char* out_buf, int buf_len);`

All functions return 0 on success, nonzero on error.

## Using the DLL with FSUIPC Lua

You can call the DLL directly from FSUIPC Lua scripts using LuaJIT FFI. Place `iflycli_dll.dll` in your FSUIPC `Modules` folder or the same directory as your Lua script.

Example Lua script for FSUIPC:

```lua
local ffi = require("ffi")

ffi.cdef[[
    int ifly_set_command(const char* command, const char* value);
    int ifly_get_command(const char* command, char* out_value, int out_value_len);
    int ifly_list_commands(char* out_buf, int buf_len);
]]

local dll = ffi.load("iflycli_dll")

-- Set a command
assert(dll.ifly_set_command("landing_light_1", "on") == 0)

-- Get a command value
local buf = ffi.new("char[64]")
dll.ifly_get_command("landing_light_1", buf, 64)
print(ffi.string(buf))

-- List all commands
local list_buf = ffi.new("char[4096]")
dll.ifly_list_commands(list_buf, 4096)
print(ffi.string(list_buf))
```

**Note:**
- The DLL must be accessible to FSUIPC/Lua (usually in the Modules folder).
- Function names are exported as C symbols (no C++ name mangling).
- You can use these functions from any language that supports loading C DLLs.

## Troubleshooting

- If you get errors about missing DLL or functions, ensure the DLL is in the correct folder and the exports are visible (use `dumpbin /exports iflycli_dll.dll` from a Visual Studio Developer Command Prompt to check).
- Make sure your Lua environment supports FFI (FSUIPC7 Lua does).

## License

See main project for license details.
