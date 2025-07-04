#include "../737MAX_SDK/sdk/key_command.h"
#include "command_info.h"

void initialize_air_systems_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["eng_1_bleed"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_ENG_1_BLEED, "eng_1_bleed",
        "Engine 1 BLEED Air Switch - Click", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_bleed_set"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_ENG_1_BLEED_SET, "eng_1_bleed_set",
        "Engine 1 BLEED Air Switch - Set", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["eng_2_bleed"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_ENG_2_BLEED, "eng_2_bleed",
        "Engine 2 BLEED Air Switch - Click", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_2_bleed_set"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_ENG_2_BLEED_SET, "eng_2_bleed_set",
        "Engine 2 BLEED Air Switch - Set", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["apu_bleed"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_APU_BLEED, "apu_bleed",
        "APU BLEED Air Switch - Click", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_bleed_set"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_APU_BLEED_SET, "apu_bleed_set",
        "APU BLEED Air Switch - Set", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["pack_1_up"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_1_UP, "pack_1_up",
        "Left Air Conditioning PACK Switch - Move Up", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["pack_1_down"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_1_DOWN, "pack_1_down",
        "Left Air Conditioning PACK Switch - Move Down", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["pack_1_set"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_1_SET, "pack_1_set",
        "Left Air Conditioning PACK Switch - Set", "air_systems",
        {"off", "auto", "high"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch AUTO; 2:switch HIGH"
    };
    (*command_map)["pack_2_up"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_2_UP, "pack_2_up",
        "Right Air Conditioning PACK Switch - Move Up", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["pack_2_down"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_2_DOWN, "pack_2_down",
        "Right Air Conditioning PACK Switch - Move Down", "air_systems",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["pack_2_set"] = CommandInfo{
        KEY_COMMAND_AIRSYSTEM_PACK_2_SET, "pack_2_set",
        "Right Air Conditioning PACK Switch - Set", "air_systems",
        {"off", "auto", "high"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch AUTO; 2:switch HIGH"
    };
    // ...continue for all KEY_COMMAND_AIRSYSTEM_* commands as in key_command.h...
}
