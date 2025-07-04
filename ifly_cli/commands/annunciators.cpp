#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_annunciators_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["emer_light_dec"] = CommandInfo{
        KEY_COMMAND_GENERAL_EMER_LIGHT_DEC, "emer_light_dec",
        "Emergency EXIT LIGHTS Switch - Move Up", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["emer_light_inc"] = CommandInfo{
        KEY_COMMAND_GENERAL_EMER_LIGHT_INC, "emer_light_inc",
        "Emergency EXIT LIGHTS Switch - Move Down", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["emer_light_set"] = CommandInfo{
        KEY_COMMAND_GENERAL_EMER_LIGHT_SET, "emer_light_set",
        "Emergency EXIT LIGHTS Switch - Set", "annunciators",
        {"off", "armed", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ARMED; 2:switch ON"
    };
    (*command_map)["light_not_armed"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_NOT_ARMED, "light_not_armed",
        "EXIT LIGHTS NOT ARMED Light - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_lock_fail"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_LOCK_FAIL, "light_lock_fail",
        "LOCK FAIL Light - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_auto_unlk"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AUTO_UNLK, "light_auto_unlk",
        "AUTO Unlock (UNLK) Light - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fwd_entry"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_FWD_ENTRY, "light_fwd_entry",
        "Exterior Door (FWD ENTRY) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_left_fwd_overwing"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_LEFT_FWD_OVERWING, "light_left_fwd_overwing",
        "Exterior Door (LEFT FWD OVERWING) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_left_aft_overwing"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_LEFT_AFT_OVERWING, "light_left_aft_overwing",
        "Exterior Door (LEFT AFT OVERWING) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_aft_entry"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AFT_ENTRY, "light_aft_entry",
        "Exterior Door (AFT ENTRY) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fwd_service"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_FWD_SERVICE, "light_fwd_service",
        "Exterior Door (FWD SERVICE) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_right_fwd_overwing"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_RIGHT_FWD_OVERWING, "light_right_fwd_overwing",
        "Exterior Door (RIGHT FWD OVERWING) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_right_aft_overwing"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_RIGHT_AFT_OVERWING, "light_right_aft_overwing",
        "Exterior Door (RIGHT AFT OVERWING) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_aft_service"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AFT_SERVICE, "light_aft_service",
        "Exterior Door (AFT SERVICE) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_equip"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_EQUIP, "light_equip",
        "Exterior Door (EQUIP) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_left_mid_exit"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_LEFT_MID_EXIT, "light_left_mid_exit",
        "Exterior Door (LEFT MID EXIT) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_right_mid_exit"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_RIGHT_MID_EXIT, "light_right_mid_exit",
        "Exterior Door (RIGHT MID EXIT) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fwd_cargo"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_FWD_CARGO, "light_fwd_cargo",
        "Exterior Door (FWD CARGO) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_aft_cargo"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AFT_CARGO, "light_aft_cargo",
        "Exterior Door (AFT CARGO) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_airstair"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AIRSTAIR, "light_airstair",
        "Exterior Door (AIRSTAIR) Annunciations - Press", "annunciators",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
