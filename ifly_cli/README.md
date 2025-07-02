# iFly 737 MAX 8 Command Line Interface

A comprehensive command-line interface for controlling the iFly 737 MAX 8 aircraft using the iFly SDK. This tool allows you to send commands to the aircraft, query current states, and provides intelligent help with valid value ranges.

## Features

- **Command Control**: Send commands to over 1400+ aircraft systems
- **State Querying**: Read current aircraft state via shared memory
- **Intelligent Help**: Get detailed help for each command with valid values
- **Command Categories**: Commands organized by system (lights, air systems, anti-ice, etc.)
- **Value Validation**: Automatic validation of command values
- **Easy to Use**: Simple command-line interface with examples

## Requirements

- Windows operating system
- Microsoft Flight Simulator 2020 or 2024
- iFly 737 MAX 8 aircraft addon
- Visual Studio Build Tools or MinGW-w64 (for compilation)

## Building

### Option 1: Visual Studio Build Tools

1. Install Visual Studio Build Tools or Visual Studio
2. Open a Developer Command Prompt
3. Navigate to the `ifly_cli` directory
4. Run: `build.bat`

### Option 2: Manual Compilation

```cmd
cl /std:c++17 /EHsc /W3 /DWIN32_LEAN_AND_MEAN /DNOMINMAX /I"." /I"../737MAX_SDK" /I"../737MAX_SDK/sdk" main.cpp /Feifly_cli.exe /link user32.lib kernel32.lib
```

### Option 3: MinGW-w64 (Alternative)

```cmd
g++ -std=c++17 -Wall -I. -I../737MAX_SDK -I../737MAX_SDK/sdk -DWIN32_LEAN_AND_MEAN -DNOMINMAX main.cpp -o ifly_cli.exe -luser32 -lkernel32
```

## Usage

### Basic Commands

```cmd
# Show help
ifly_cli.exe help

# List all available commands
ifly_cli.exe list

# Test connection to iFly 737 MAX
ifly_cli.exe connect

# Set a command to a specific value
ifly_cli.exe set <command> <value>

# Get current value of a command
ifly_cli.exe get <command>

# Get help for a specific command
ifly_cli.exe help <command>
```

### Examples

```cmd
# Control landing lights
ifly_cli.exe set landing_light_1 on
ifly_cli.exe set landing_light_2 flash
ifly_cli.exe get landing_light_1

# Control taxi light
ifly_cli.exe set taxi_light on
ifly_cli.exe get taxi_light

# Control anti-collision lights
ifly_cli.exe set anti_collision_light on

# Control air systems
ifly_cli.exe set engine_1_bleed on
ifly_cli.exe set pack_1 auto
ifly_cli.exe set apu_bleed off

# Control anti-ice systems
ifly_cli.exe set wing_anti_ice on
ifly_cli.exe set engine_1_anti_ice on

# Get help for specific commands
ifly_cli.exe help landing_light_1
ifly_cli.exe help pack_1
```

## Command Categories

### Lights
- `landing_light_1`, `landing_light_2` - Landing lights (off, flash, on)
- `taxi_light` - Taxi light (off, on)
- `logo_light` - Logo light (off, on)
- `anti_collision_light` - Anti-collision light (off, on)
- `wing_light` - Wing illumination (off, on)
- `wheel_well_light` - Wheel well light (off, on)
- `position_light` - Position lights (strobe_steady, off, steady)
- `dome_light` - Dome light (dim, off, bright)

### Air Systems
- `engine_1_bleed`, `engine_2_bleed` - Engine bleed air (off, on)
- `apu_bleed` - APU bleed air (off, on)
- `pack_1`, `pack_2` - Air conditioning packs (off, auto, high)

### Anti-Ice
- `wing_anti_ice` - Wing anti-ice (off, on)
- `engine_1_anti_ice`, `engine_2_anti_ice` - Engine anti-ice (off, on)

## Command Structure

Each command follows this pattern:
- **Command Name**: Descriptive name for the control
- **Valid Values**: List of acceptable values (e.g., "off", "on", "auto")
- **Description**: What the command controls
- **Category**: System category (lights, air_systems, anti_ice, etc.)

## Architecture

The CLI tool consists of:

1. **iFlyCommander Class**: Main command processing and SDK integration
2. **CommandInfo Structure**: Stores command metadata and validation rules
3. **SDK Integration**: Uses iFly SDK functions for command sending and state reading
4. **Command Parser**: Handles command-line argument parsing and validation
5. **Help System**: Provides detailed help for commands and categories

## SDK Integration

The tool uses the iFly SDK to:
- Send commands via `iFly737MAX_SendMessage()`
- Read aircraft state via shared memory mapping
- Initialize SDK connection for MSFS 2020/2024

## Error Handling

The tool provides comprehensive error handling:
- Connection validation to iFly 737 MAX
- Command validation against known commands
- Value validation against allowed ranges
- Clear error messages with suggestions

## Extending the Tool

To add new commands:

1. Add the command to `initialize_command_map()` in main.cpp
2. Use the `add_command()` function with:
   - SDK command ID from `key_command.h`
   - Command name (user-friendly)
   - Description
   - Category
   - Valid values array
   - Value descriptions (optional)

Example:
```cpp
add_command(KEY_COMMAND_GENERAL_NEW_SWITCH_SET, "new_switch", 
            "New Switch Description", "category", 
            {"off", "on"}, 
            "0: OFF the click sound; 1: ON the click sound",
            "0:switch OFF; 1:switch ON");
```

## Troubleshooting

### Connection Issues
- Ensure Microsoft Flight Simulator is running
- Verify iFly 737 MAX 8 aircraft is loaded
- Check that the iFly plugin is active

### Command Issues
- Use `list` command to see available commands
- Use `help <command>` to check valid values
- Ensure values are spelled correctly (case-insensitive)

### Build Issues
- Ensure Visual Studio Build Tools are installed
- Try running from Developer Command Prompt
- Check that all SDK files are present

## License

This tool is provided for educational and personal use with the iFly 737 MAX 8 aircraft addon.
