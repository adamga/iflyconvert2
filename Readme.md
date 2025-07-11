This repo takes the Air Manager Overhead instruments for the PMDG 737 700 created originally by Detlef von Reusner, and has the converted lua code to work with the iFly 737 Max 8.

**UPDATES**
- Some controls do not "trigger" the appropriate actions, particularly things like apu start, etc. It seems there are "double-click" like activities or some other trigger happening in the plane itself. These will need further investigation. However, the conversion is still useful for things like lights.
- In the iFly 737, there are a number of action commands, defined as KEY_COMMANDS, that control various behaviours in the aircraft and trigger the proper activities. **They currently do not work in MSFS 2024, so they're not implemented in the current controls yet.** I will update them when they are working.

***********

I've included all of the code that was used, including:

- `iflymax8lvars-vcs.txt`: this is a list of the lvars from the MAX8 gathered using FSUIPC 7 (Addons->WASM->List LVars)

All of the original lua script remains intact as comments in each file.

All of the conversion work was done using GitHub Copilot in Agent Mode. I've included my complete chat history as an export (see `chat.json`) if you're interested in seeing how things went step by step. Otherwise, I kicked off the agent interaction with the following prompt:

> "In this workspace, there's a file called iflymax8lvars-vcs.txt... this contains a list of all the simulation variables for the iflymax8... In the resources folder, there are a number of instruments, each in its own folder. the logic is in a file called logic.lua...these intruments are for a different vendor's airplane, and I need to convert them to the ifly737max... to call events against a particular control in the ifly, we use a fs2020 _variable_write, or msfs_variable_write command, instead of using an event command... in general, the ifly uses variable values from 0 and up, in increments of 10, so 0,10,20, etc... while the instruments will generally use 0 and 1 for simply 2 position switches, and 1,2,3 for three position switches.
> Let's go through each instrument one at a time, together, and interactively upgrade them. guide me through the process... we'll look at each control in sequence... always verify with me your decisions (for example, what sim variable) and ask me if you don't know. never change existing code, always create a commented out copy of the existing code block before you change anything."

You can see the `ifly_conversion_process.md` in the repo that Copilot Agent used to track its work as it went.

The entire process for all of the overhead instruments took just under an hour. While it made a couple of mistakes along the way, it fixed them when I pointed out the issues.

I've also included an export of all of the instruments in a `ifly737max8oh.siff` file in this repo.

**Subproject: iFly CLI**

There is a subproject in this solution, used for testing, that implements an iFly CLI. This CLI can be used for getting and setting the KEY_COMMANDS (when supported by the sim/SDK). See the `ifly_cli` folder for details, usage, and build instructions. The CLI is robust, command-line only, and supports listing, setting, and querying all mapped KEY_COMMANDS.

**Subproject: iFly CLI DLL**

A C++ DLL (`iflycli_dll`) is included that exposes a C API for setting, getting, and listing iFly 737 MAX 8 commands. This DLL is designed for integration with Lua scripts via FFI, FSUIPC, or any other environment that can load standard C DLLs.

- See the `dll` folder for source and build instructions.
- The DLL exports three main functions:
  - `int ifly_set_command(const char* command, const char* value);`
  - `int ifly_get_command(const char* command, char* out_value, int out_value_len);`
  - `int ifly_list_commands(char* out_buf, int buf_len);`
- All functions return 0 on success, nonzero on error.

**Using the DLL with FSUIPC Lua**

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

dll.ifly_set_command("landing_light_1", "on")

local buf = ffi.new("char[64]")
dll.ifly_get_command("landing_light_1", buf, 64)
print(ffi.string(buf))

local list_buf = ffi.new("char[4096]")
dll.ifly_list_commands(list_buf, 4096)
print(ffi.string(list_buf))
```

A sample Lua script for FSUIPC integration is provided in `FSUIPC/iflycli_sample.lua`. This script demonstrates how to load and call the DLL from FSUIPC Lua using LuaJIT FFI, including setting, getting, and listing commands. See that file for a ready-to-use example.

- The DLL must be accessible to FSUIPC/Lua (usually in the Modules folder).
- Function names are exported as C symbols (no C++ name mangling).
- You can use these functions from any language that supports loading C DLLs.

None of this is absolutely perfect, but feel free to take this further if you'd like. I did this as an experiment for my own use, and thought I'd share.
