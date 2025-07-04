#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_anti_ice_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["left_side_window_heat"] = CommandInfo{
        KEY_COMMAND_ANTIICE_LEFT_SIDE_WINDOW_HEAT, "left_side_window_heat",
        "Left SIDE WINDOW HEAT Switch - Click", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["left_side_window_heat_set"] = CommandInfo{
        KEY_COMMAND_ANTIICE_LEFT_SIDE_WINDOW_HEAT_SET, "left_side_window_heat_set",
        "Left SIDE WINDOW HEAT Switch - Set", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["left_fwd_window_heat"] = CommandInfo{
        KEY_COMMAND_ANTIICE_LEFT_FWD_WINDOW_HEAT, "left_fwd_window_heat",
        "Left FWD WINDOW HEAT Switch - Click", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["left_fwd_window_heat_set"] = CommandInfo{
        KEY_COMMAND_ANTIICE_LEFT_FWD_WINDOW_HEAT_SET, "left_fwd_window_heat_set",
        "Left FWD WINDOW HEAT Switch - Set", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["right_fwd_window_heat"] = CommandInfo{
        KEY_COMMAND_ANTIICE_RIGHT_FWD_WINDOW_HEAT, "right_fwd_window_heat",
        "Right FWD WINDOW HEAT Switch - Click", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["right_fwd_window_heat_set"] = CommandInfo{
        KEY_COMMAND_ANTIICE_RIGHT_FWD_WINDOW_HEAT_SET, "right_fwd_window_heat_set",
        "Right FWD WINDOW HEAT Switch - Set", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["right_side_window_heat"] = CommandInfo{
        KEY_COMMAND_ANTIICE_RIGHT_SIDE_WINDOW_HEAT, "right_side_window_heat",
        "Right SIDE WINDOW HEAT Switch - Click", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["right_side_window_heat_set"] = CommandInfo{
        KEY_COMMAND_ANTIICE_RIGHT_SIDE_WINDOW_HEAT_SET, "right_side_window_heat_set",
        "Right SIDE WINDOW HEAT Switch - Set", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["window_heat_test_dec"] = CommandInfo{
        KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_DEC, "window_heat_test_dec",
        "WINDOW HEAT Test Switch - Move Up", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["window_heat_test_inc"] = CommandInfo{
        KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_INC, "window_heat_test_inc",
        "WINDOW HEAT Test Switch - Move Down", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["window_heat_test_set"] = CommandInfo{
        KEY_COMMAND_ANTIICE_WINDOW_HEAT_TEST_SET, "window_heat_test_set",
        "WINDOW HEAT Test Switch - Set", "anti_ice",
        {"ovht", "neutral", "pwr_test"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OVHT; 1:switch Neutral; 2:switch PWR TEST"
    };

    (*command_map)["wing_anti_ice"] = CommandInfo{
        KEY_COMMAND_ANTIICE_WING_SET, "wing_anti_ice",
        "Wing Anti-Ice Switch", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["engine_1_anti_ice"] = CommandInfo{
        KEY_COMMAND_ANTIICE_ENG_1_SET, "engine_1_anti_ice",
        "Engine 1 Anti-Ice Switch", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };

    (*command_map)["engine_2_anti_ice"] = CommandInfo{
        KEY_COMMAND_ANTIICE_ENG_2_SET, "engine_2_anti_ice",
        "Engine 2 Anti-Ice Switch", "anti_ice",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
}
