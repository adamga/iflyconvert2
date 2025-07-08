# iflycli_dll

A C++ DLL that exposes a C API for setting, getting, and listing iFly 737 MAX 8 commands. Intended for integration with Lua scripts via FFI or other scripting environments.

## Building

This project uses CMake for cross-platform builds:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

Or use Visual Studio to open the folder and build the DLL target.

## API

See `iflycli_dll.h` for the exported functions:
- `int ifly_set_command(const char* command, const char* value);`
- `int ifly_get_command(const char* command, char* out_value, int out_value_len);`
- `int ifly_list_commands(char* out_buf, int buf_len);`

## Integration

You can call these functions from Lua using LuaJIT FFI, or from any language that supports loading C DLLs.

## Next Steps
- Integrate the logic from the CLI project into the DLL implementation.
- Expand the stub functions to use the real command map and SDK logic.
- Provide Lua examples for calling the DLL.
