#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_fire_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["left_ovht_det_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_LEFT_OVHT_DET_DEC, "left_ovht_det_dec",
        "Engine 1 Overheat Detector (OVHT DET) Switch - Move Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["left_ovht_det_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_LEFT_OVHT_DET_INC, "left_ovht_det_inc",
        "Engine 1 Overheat Detector (OVHT DET) Switch - Move Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["left_ovht_det_set"] = CommandInfo{
        KEY_COMMAND_FIRE_LEFT_OVHT_DET_SET, "left_ovht_det_set",
        "Engine 1 Overheat Detector (OVHT DET) Switch - Set", "fire",
        {"a", "normal", "b"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch A; 1:switch NORMAL; 2:switch B"
    };
    (*command_map)["right_ovht_det_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_RIGHT_OVHT_DET_DEC, "right_ovht_det_dec",
        "Engine 2 Overheat Detector (OVHT DET) Switch - Move Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["right_ovht_det_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_RIGHT_OVHT_DET_INC, "right_ovht_det_inc",
        "Engine 2 Overheat Detector (OVHT DET) Switch - Move Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["right_ovht_det_set"] = CommandInfo{
        KEY_COMMAND_FIRE_RIGHT_OVHT_DET_SET, "right_ovht_det_set",
        "Engine 2 Overheat Detector (OVHT DET) Switch - Set", "fire",
        {"a", "normal", "b"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch A; 1:switch NORMAL; 2:switch B"
    };
    (*command_map)["ext_test_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_EXT_TEST_DEC, "ext_test_dec",
        "Extinguisher (EXT) TEST Switch - Move Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ext_test_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_EXT_TEST_INC, "ext_test_inc",
        "Extinguisher (EXT) TEST Switch - Move Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ext_test_set"] = CommandInfo{
        KEY_COMMAND_FIRE_EXT_TEST_SET, "ext_test_set",
        "Extinguisher (EXT) TEST Switch - Set", "fire",
        {"1", "neutral", "2"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch 1; 1:switch Neutral; 2:switch 2"
    };
    (*command_map)["test_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_TEST_DEC, "test_dec",
        "FAULT/INOP and OVHT/FIRE TEST Switch - Move Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["test_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_TEST_INC, "test_inc",
        "FAULT/INOP and OVHT/FIRE TEST Switch - Move Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["test_set"] = CommandInfo{
        KEY_COMMAND_FIRE_TEST_SET, "test_set",
        "FAULT/INOP and OVHT/FIRE TEST Switch - Set", "fire",
        {"fault_inop", "neutral", "ovht_fire"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch FAULT/INOP; 1:switch Neutral; 2:switch OVHT/FIRE"
    };
    (*command_map)["apu_fire_switch_pull"] = CommandInfo{
        KEY_COMMAND_FIRE_APU_FIRE_SWITCH_PULL, "apu_fire_switch_pull",
        "APU Fire Switch - Click", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: Fire switch not override; 1: Fire switch override"
    };
    (*command_map)["apu_fire_switch_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_APU_FIRE_SWITCH_DEC, "apu_fire_switch_dec",
        "APU Fire Switch - Rotate Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_fire_switch_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_APU_FIRE_SWITCH_INC, "apu_fire_switch_inc",
        "APU Fire Switch - Rotate Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_fire_switch_set"] = CommandInfo{
        KEY_COMMAND_FIRE_APU_FIRE_SWITCH_SET, "apu_fire_switch_set",
        "APU Fire Switch - Set", "fire",
        {"normal", "up", "rotate_left", "rotate_right"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: Fire switch NORMAL; 1: Fire switch UP; 2: Fire switch rotate LEFT; 3: Fire switch rotate RIGHT",
        "0: Fire switch not override; 1: Fire switch override"
    };
    (*command_map)["eng_1_fire_switch_pull"] = CommandInfo{
        KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_PULL, "eng_1_fire_switch_pull",
        "Engine 1 Fire Switch - Click", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: Fire switch not override; 1: Fire switch override"
    };
    (*command_map)["eng_1_fire_switch_dec"] = CommandInfo{
        KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_DEC, "eng_1_fire_switch_dec",
        "Engine 1 Fire Switch - Rotate Left", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_fire_switch_inc"] = CommandInfo{
        KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_INC, "eng_1_fire_switch_inc",
        "Engine 1 Fire Switch - Rotate Right", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_1_fire_switch_set"] = CommandInfo{
        KEY_COMMAND_FIRE_ENG_1_FIRE_SWITCH_SET, "eng_1_fire_switch_set",
        "Engine 1 Fire Switch - Set", "fire",
        {"normal", "up", "rotate_left", "rotate_right"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: Fire switch NORMAL; 1: Fire switch UP; 2: Fire switch rotate LEFT; 3: Fire switch rotate RIGHT",
        "0: Fire switch not override; 1: Fire switch override"
    };
    (*command_map)["eng_2_fire_switch_pull"] = CommandInfo{
        KEY_COMMAND_FIRE_ENG_2_FIRE_SWITCH_PULL, "eng_2_fire_switch_pull",
        "Engine 2 Fire Switch - Click", "fire",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: Fire switch not override; 1: Fire switch override"
    };
}
