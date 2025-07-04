#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_fltctrl_commands(std::map<std::string, CommandInfo>* command_map) {
    // Flight Control A
    (*command_map)["flight_control_a_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_DEC, "flight_control_a_dec",
        "FLIGHT CONTROL A Switch - Move Up", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["flight_control_a_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_INC, "flight_control_a_inc",
        "FLIGHT CONTROL A Switch - Move Down", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["flight_control_a_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_A_SET, "flight_control_a_set",
        "FLIGHT CONTROL A Switch - Set", "fltctrl",
        {"stby_rud", "off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch STBY RUD; 1:switch OFF; 2:switch ON",
        "1: ignore the guard, press the button directly"
    };
    // Flight Control B
    (*command_map)["flight_control_b_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_DEC, "flight_control_b_dec",
        "FLIGHT CONTROL B Switch - Move Up", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["flight_control_b_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_INC, "flight_control_b_inc",
        "FLIGHT CONTROL B Switch - Move Down", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["flight_control_b_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_FLIGHT_CONTROL_B_SET, "flight_control_b_set",
        "FLIGHT CONTROL B Switch - Set", "fltctrl",
        {"stby_rud", "off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch STBY RUD; 1:switch OFF; 2:switch ON",
        "1: ignore the guard, press the button directly"
    };
    // Spoiler A
    (*command_map)["spoiler_a_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_A_DEC, "spoiler_a_dec",
        "Flight SPOILER A Switch - Move Up", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["spoiler_a_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_A_INC, "spoiler_a_inc",
        "Flight SPOILER A Switch - Move Down", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["spoiler_a_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_A_SET, "spoiler_a_set",
        "Flight SPOILER A Switch - Set", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    // Spoiler B
    (*command_map)["spoiler_b_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_B_DEC, "spoiler_b_dec",
        "Flight SPOILER B Switch - Move Up", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["spoiler_b_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_B_INC, "spoiler_b_inc",
        "Flight SPOILER B Switch - Move Down", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["spoiler_b_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_SPOILER_B_SET, "spoiler_b_set",
        "Flight SPOILER B Switch - Set", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    // Alternate Flaps Master
    (*command_map)["alternate_flaps_master_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_DEC, "alternate_flaps_master_dec",
        "ALTERNATE FLAPS Master Switch - Move Up", "fltctrl",
        {"off", "arm"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alternate_flaps_master_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_INC, "alternate_flaps_master_inc",
        "ALTERNATE FLAPS Master Switch - Move Down", "fltctrl",
        {"off", "arm"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alternate_flaps_master_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_MASTER_SET, "alternate_flaps_master_set",
        "ALTERNATE FLAPS Master Switch - Set", "fltctrl",
        {"off", "arm"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ARM",
        "1: ignore the guard, press the button directly"
    };
    // Alternate Flaps
    (*command_map)["alternate_flaps_dec"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_DEC, "alternate_flaps_dec",
        "ALTERNATE FLAPS Position Switch - Move Up", "fltctrl",
        {"up", "off", "down"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alternate_flaps_inc"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_INC, "alternate_flaps_inc",
        "ALTERNATE FLAPS Position Switch - Move Down", "fltctrl",
        {"up", "off", "down"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alternate_flaps_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_ALTERNATE_FLAPS_SET, "alternate_flaps_set",
        "ALTERNATE FLAPS Position Switch - Set", "fltctrl",
        {"up", "off", "down"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch UP; 1:switch OFF; 2:switch DOWN"
    };
    // Yaw Damper
    (*command_map)["yaw_damper"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_YAW_DAMPER, "yaw_damper",
        "YAW DAMPER Switch - Click", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["yaw_damper_set"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_YAW_DAMPER_SET, "yaw_damper_set",
        "YAW DAMPER Switch - Set", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    // Yaw Damper Light
    (*command_map)["light_yaw_damper"] = CommandInfo{
        KEY_COMMAND_FLTCTRL_LIGHT_YAW_DAMPER, "light_yaw_damper",
        "YAW DAMPER Light - Press", "fltctrl",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
