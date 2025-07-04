#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_apu_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["apu_start"] = CommandInfo{
        KEY_COMMAND_ENGAPU_APU_SET, "apu_start",
        "APU Start Switch", "apu",
        {"off", "on", "start"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON; 2:switch START"
    };
    (*command_map)["apu_up"] = CommandInfo{
        KEY_COMMAND_ENGAPU_APU_UP, "apu_up",
        "APU Switch - Move Up", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_down"] = CommandInfo{
        KEY_COMMAND_ENGAPU_APU_DOWN, "apu_down",
        "APU Switch - Move Down", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_door_light"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_APU_DOOR, "apu_door_light",
        "APU Door Light - Press", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_low_oil_pressure_light"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_APU_LOW_OIL_PRESSURE, "apu_low_oil_pressure_light",
        "APU LOW OIL PRESSURE Light - Press", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_fault_light"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_APU_FAULT, "apu_fault_light",
        "APU FAULT Light - Press", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_overspeed_light"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_APU_OVER_SPEED, "apu_overspeed_light",
        "APU OVERSPEED Light - Press", "apu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
