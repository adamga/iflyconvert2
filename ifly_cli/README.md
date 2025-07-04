# iFly 737 MAX 8 Command Line Interface (CLI)

A robust, cross-platform command-line tool for controlling the iFly 737 MAX 8 aircraft via the iFly SDK. This CLI allows you to set and query aircraft state, list and get help for all available commands, and test connectivity to the simulator. All major KEY_COMMAND_* enums are mapped to CLI commands, and the codebase is clean, maintainable, and easy to extend.

## Features

- **Set and Get Aircraft State:**
  - Set any mapped command to a specific value (e.g., turn lights on/off, control systems, etc.)
  - Query the current value of supported commands
- **List All Commands:**
  - List all available commands, or filter by category
- **Detailed Help:**
  - Get help for any command, including valid values and usage examples
- **Category Support:**
  - Commands are organized by system (lights, hydraulics, fuel, air systems, etc.)
- **Connection Test:**
  - Test connection to the iFly 737 MAX 8 simulator
- **Clean Command-Line Only Interface:**
  - No interactive or autocomplete mode; all actions are via command-line arguments
- **Extensible Codebase:**
  - Easy to add new commands or categories by editing the appropriate `commands/*.cpp` files
- **Windows Support:**
  - Designed for Windows, compatible with MSFS 2020 and the iFly 737 MAX 8 SDK

## Usage

```
ifly_cli.exe list                           # List all available commands
ifly_cli.exe list <category>                # List commands in a specific category
ifly_cli.exe set <command> <value>          # Set a command to a specific value
ifly_cli.exe get <command>                  # Get current value of a command
ifly_cli.exe help [command]                 # Get help for all commands or a specific command
ifly_cli.exe connect                        # Test connection to iFly 737 MAX
```

### Examples

```
ifly_cli.exe set landing_light_1 on
ifly_cli.exe get landing_light_1
ifly_cli.exe help landing_light_1
ifly_cli.exe list lights


## Categories
- lights
- air_systems
- anti_ice
- hydraulics
- fuel
- annunciators
- apu
- automatic_flight
- communication
- electrical
- engapu
- fire
- fltctrl
- fms
- gear
- instrument
- warning

## Requirements
- Windows
- Microsoft Flight Simulator 2020
- iFly 737 MAX 8 aircraft and SDK

## Building
Use the provided `build_direct.bat` script or your preferred C++ build system. All dependencies are included or referenced in the repo.

## Notes
- `.gitignore` is configured to exclude all build artifacts, SDK binaries, and large files.
- If you encounter git errors about large files, see the repo history cleaning instructions.

## Extending the Tool
To add new commands or categories, edit the appropriate `commands/*.cpp` file and update the command map in `main.cpp`. Follow the `CommandInfo` pattern for consistency.

## Contributing
Pull requests are welcome! Please ensure new commands are added in the appropriate `commands/*.cpp` file and update this README if you add new categories or features.

## License
See LICENSE file for details.
