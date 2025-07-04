#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_engapu_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["ignition_select_dec"] = CommandInfo{
        KEY_COMMAND_ENGAPU_IGNITION_SELECT_DEC, "ignition_select_dec",
        "Ignition Select Switch - Move Left", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ignition_select_inc"] = CommandInfo{
        KEY_COMMAND_ENGAPU_IGNITION_SELECT_INC, "ignition_select_inc",
        "Ignition Select Switch - Move Right", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ignition_select_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_IGNITION_SELECT_SET, "ignition_select_set",
        "Ignition Select Switch - Set", "engapu",
        {"1", "both", "2"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch 1; 1:switch BOTH; 2:switch 2"
    };
    (*command_map)["eng_1_start_dec"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_1_START_DEC, "eng_1_start_dec",
        "Engine 1 START Switch - Rotate Left", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_start_inc"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_1_START_INC, "eng_1_start_inc",
        "Engine 1 START Switch - Rotate Right", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_start_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_1_START_SET, "eng_1_start_set",
        "Engine 1 START Switch - Set", "engapu",
        {"grd", "off", "cont", "flt"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch GRD; 1:switch OFF; 2:switch CONT; 3:switch FLT"
    };
    (*command_map)["eng_2_start_dec"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_2_START_DEC, "eng_2_start_dec",
        "Engine 2 START Switch - Rotate Left", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_2_start_inc"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_2_START_INC, "eng_2_start_inc",
        "Engine 2 START Switch - Rotate Right", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_2_start_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_2_START_SET, "eng_2_start_set",
        "Engine 2 START Switch - Set", "engapu",
        {"grd", "off", "cont", "flt"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch GRD; 1:switch OFF; 2:switch CONT; 3:switch FLT"
    };
    (*command_map)["eng_1_start_lever"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_1_START_LEVER, "eng_1_start_lever",
        "Engine 1 Start Lever - Click", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_start_lever_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_1_START_LEVER_SET, "eng_1_start_lever_set",
        "Engine 1 Start Lever - Set", "engapu",
        {"idle", "cutoff"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch IDLE; 1:switch CUTOFF"
    };
    (*command_map)["eng_2_start_lever"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_2_START_LEVER, "eng_2_start_lever",
        "Engine 2 Start Lever - Click", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_2_start_lever_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_ENG_2_START_LEVER_SET, "eng_2_start_lever_set",
        "Engine 2 Start Lever - Set", "engapu",
        {"idle", "cutoff"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch IDLE; 1:switch CUTOFF"
    };
    (*command_map)["eec_1"] = CommandInfo{
        KEY_COMMAND_ENGAPU_EEC_1, "eec_1",
        "Engine 1 Electronic Engine Control (EEC) Switch - Click", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eec_1_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_EEC_1_SET, "eec_1_set",
        "Engine 1 Electronic Engine Control (EEC) Switch - Set", "engapu",
        {"altn", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch ALTN; 1:switch ON"
    };
    (*command_map)["eec_2"] = CommandInfo{
        KEY_COMMAND_ENGAPU_EEC_2, "eec_2",
        "Engine 2 Electronic Engine Control (EEC) Switch - Click", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eec_2_set"] = CommandInfo{
        KEY_COMMAND_ENGAPU_EEC_2_SET, "eec_2_set",
        "Engine 2 Electronic Engine Control (EEC) Switch - Set", "engapu",
        {"altn", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch ALTN; 1:switch ON"
    };
    (*command_map)["light_engine_control_1"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_ENGINE_CONTROL_1, "light_engine_control_1",
        "Engine 1 CONTROL Light - Press", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_engine_control_2"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_ENGINE_CONTROL_2, "light_engine_control_2",
        "Engine 2 CONTROL Light - Press", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_reverser_limited_1"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_REVERSER_LIMITED_1, "light_reverser_limited_1",
        "Engine 1 REVERSER LIMITED Light - Press", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_reverser_limited_2"] = CommandInfo{
        KEY_COMMAND_ENGAPU_LIGHT_REVERSER_LIMITED_2, "light_reverser_limited_2",
        "Engine 2 REVERSER LIMITED Light - Press", "engapu",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
