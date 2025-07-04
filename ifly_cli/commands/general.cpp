#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_general_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["lights_test_dec"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHTS_TEST_DEC, "lights_test_dec",
        "Master LIGHTS TEST and DIM Switch - Move Up", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };

    (*command_map)["lights_test_inc"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHTS_TEST_INC, "lights_test_inc",
        "Master LIGHTS TEST and DIM Switch - Move Down", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };

    (*command_map)["lights_test_test"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHTS_TEST_TEST, "lights_test_test",
        "Master LIGHTS TEST and DIM Switch - Move to TEST", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };

    (*command_map)["lights_test_brt"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHTS_TEST_BRT, "lights_test_brt",
        "Master LIGHTS TEST and DIM Switch - Move to BRT", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };

    (*command_map)["lights_test_dim"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHTS_TEST_DIM, "lights_test_dim",
        "Master LIGHTS TEST and DIM Switch - Move to DIM", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };

    (*command_map)["door_lock_dec"] = CommandInfo{
        KEY_COMMAND_GENERAL_DOOR_LOCK_DEC, "door_lock_dec",
        "Flight Deck Door Lock Selector - Rotate Left", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["door_lock_inc"] = CommandInfo{
        KEY_COMMAND_GENERAL_DOOR_LOCK_INC, "door_lock_inc",
        "Flight Deck Door Lock Selector - Rotate Right", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["door_lock_set"] = CommandInfo{
        KEY_COMMAND_GENERAL_DOOR_LOCK_SET, "door_lock_set",
        "Flight Deck Door Lock Selector - Set", "general",
        {"unlkd", "auto", "deny"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch UNLKD; 1:switch AUTO; 2:switch DENY"
    };
    (*command_map)["light_lock_fail"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_LOCK_FAIL, "light_lock_fail",
        "LOCK FAIL Light - Press", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_auto_unlk"] = CommandInfo{
        KEY_COMMAND_GENERAL_LIGHT_AUTO_UNLK, "light_auto_unlk",
        "AUTO Unlock (UNLK) Light - Press", "general",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
