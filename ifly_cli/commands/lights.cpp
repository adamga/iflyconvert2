#include "../737MAX_SDK/sdk/key_command.h"
#include "command_info.h"

void initialize_lights_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["landing_light_1"] = CommandInfo{
        KEY_COMMAND_GENERAL_LANDING_LIGHT_1_SET, "landing_light_1",
        "Left Landing Light Switch", "lights",
        {"off", "flash", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch FLASH; 2:switch ON"
    };

    (*command_map)["landing_light_2"] = CommandInfo{
        KEY_COMMAND_GENERAL_LANDING_LIGHT_2_SET, "landing_light_2",
        "Right Landing Light Switch", "lights",
        {"off", "flash", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch FLASH; 2:switch ON"
    };

    (*command_map)["taxi_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_TAXI_LIGHT_SET, "taxi_light",
        "Taxi Light Switch", "lights",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["logo_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_LOGO_LIGHT_SET, "logo_light",
        "Logo Light Switch", "lights",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["anti_collision_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_ANTI_COLLISION_LIGHT_SET, "anti_collision_light",
        "Anti-Collision Light Switch", "lights",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["wing_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_WING_LIGHT_SET, "wing_light",
        "Wing Illumination Switch", "lights",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["wheel_well_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_WHEEL_WELL_LIGHT_SET, "wheel_well_light",
        "Wheel Well Light Switch", "lights",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["position_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_POSITION_LIGHT_SET, "position_light",
        "Position Light Switch", "lights",
        {"strobe_steady", "off", "steady"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch STROBE&STEADY; 1:switch OFF; 2:switch STEADY"
    };

    (*command_map)["dome_light"] = CommandInfo{
        KEY_COMMAND_GENERAL_DOME_LIGHT_SET, "dome_light",
        "Dome Light Switch", "lights",
        {"dim", "off", "bright"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch DIM; 1:switch OFF; 2:switch BRIGHT",
        "1: ignore the guard, press the button directly"
    };
}
