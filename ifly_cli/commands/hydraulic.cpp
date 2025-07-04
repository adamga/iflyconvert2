#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_hydraulic_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["electric_pump_1"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_1, "electric_pump_1",
        "HYD B, ELECTRIC HYDRAULIC PUMP Switch - Click", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["electric_pump_1_set"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_1_SET, "electric_pump_1_set",
        "HYD B, ELECTRIC HYDRAULIC PUMP Switch - Set", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["electric_pump_2"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_2, "electric_pump_2",
        "HYD A, ELECTRIC HYDRAULIC PUMP Switch - Click", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["electric_pump_2_set"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ELECTRIC_PUMP_2_SET, "electric_pump_2_set",
        "HYD A, ELECTRIC HYDRAULIC PUMP Switch - Set", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["eng_pump_1"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ENG_PUMP_1, "eng_pump_1",
        "HYD A, ENGINE HYDRAULIC PUMP Switch - Click", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_pump_1_set"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ENG_PUMP_1_SET, "eng_pump_1_set",
        "HYD A, ENGINE HYDRAULIC PUMP Switch - Set", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["eng_pump_2"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ENG_PUMP_2, "eng_pump_2",
        "HYD B, ENGINE HYDRAULIC PUMP Switch - Click", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["eng_pump_2_set"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_ENG_PUMP_2_SET, "eng_pump_2_set",
        "HYD B, ENGINE HYDRAULIC PUMP Switch - Set", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["light_eng_1_low_pressure"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ENG_1_LOW_PRESSURE, "light_eng_1_low_pressure",
        "HYD A, Engine Hydraulic Pump LOW PRESSURE Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_eng_2_low_pressure"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ENG_2_LOW_PRESSURE, "light_eng_2_low_pressure",
        "HYD B, Engine Hydraulic Pump LOW PRESSURE Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_elec_1_low_pressure"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_1_LOW_PRESSURE, "light_elec_1_low_pressure",
        "HYD B, Electric Hydraulic Pump LOW PRESSURE Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_elec_2_low_pressure"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_2_LOW_PRESSURE, "light_elec_2_low_pressure",
        "HYD A, Electric Hydraulic Pump LOW PRESSURE Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_elec_1_overheat"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_1_OVERHEAT, "light_elec_1_overheat",
        "HYD B, Electric Hydraulic Pump OVERHEAT Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_elec_2_overheat"] = CommandInfo{
        KEY_COMMAND_HYDRAULIC_LIGHT_ELEC_2_OVERHEAT, "light_elec_2_overheat",
        "HYD A, Electric Hydraulic Pump OVERHEAT Light - Press", "hydraulic",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
