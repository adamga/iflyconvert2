#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_fuel_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["crossfeed"] = CommandInfo{
        KEY_COMMAND_FUEL_CROSSFEED, "crossfeed",
        "CROSSFEED Selector - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["crossfeed_set"] = CommandInfo{
        KEY_COMMAND_FUEL_CROSSFEED_SET, "crossfeed_set",
        "CROSSFEED Selector - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["ctr_l_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_CTR_L_PUMP, "ctr_l_pump",
        "FUEL PUMP Switch (CTR L) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ctr_l_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_CTR_L_PUMP_SET, "ctr_l_pump_set",
        "FUEL PUMP Switch (CTR L) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["ctr_r_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_CTR_R_PUMP, "ctr_r_pump",
        "FUEL PUMP Switch (CTR R) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ctr_r_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_CTR_R_PUMP_SET, "ctr_r_pump_set",
        "FUEL PUMP Switch (CTR R) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["aft_1_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_AFT_1_PUMP, "aft_1_pump",
        "FUEL PUMP Switch (L AFT) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["aft_1_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_AFT_1_PUMP_SET, "aft_1_pump_set",
        "FUEL PUMP Switch (L AFT) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["fwd_1_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_FWD_1_PUMP, "fwd_1_pump",
        "FUEL PUMP Switch (L FWD) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fwd_1_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_FWD_1_PUMP_SET, "fwd_1_pump_set",
        "FUEL PUMP Switch (L FWD) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["aft_2_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_AFT_2_PUMP, "aft_2_pump",
        "FUEL PUMP Switch (R AFT) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["aft_2_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_AFT_2_PUMP_SET, "aft_2_pump_set",
        "FUEL PUMP Switch (R AFT) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["fwd_2_pump"] = CommandInfo{
        KEY_COMMAND_FUEL_FWD_2_PUMP, "fwd_2_pump",
        "FUEL PUMP Switch (R FWD) - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fwd_2_pump_set"] = CommandInfo{
        KEY_COMMAND_FUEL_FWD_2_PUMP_SET, "fwd_2_pump_set",
        "FUEL PUMP Switch (R FWD) - Set", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["light_ctr_l_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_CTR_L_LOW_PRESSURE, "light_ctr_l_low_pressure",
        "Fuel Pump LOW PRESSURE Light (CTR L) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_ctr_r_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_CTR_R_LOW_PRESSURE, "light_ctr_r_low_pressure",
        "Fuel Pump LOW PRESSURE Light (CTR R) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_aft_1_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_AFT_1_LOW_PRESSURE, "light_aft_1_low_pressure",
        "Fuel Pump LOW PRESSURE Light (L AFT) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fwd_1_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_FWD_1_LOW_PRESSURE, "light_fwd_1_low_pressure",
        "Fuel Pump LOW PRESSURE Light (L FWD) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_aft_2_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_AFT_2_LOW_PRESSURE, "light_aft_2_low_pressure",
        "Fuel Pump LOW PRESSURE Light (R AFT) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fwd_2_low_pressure"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_FWD_2_LOW_PRESSURE, "light_fwd_2_low_pressure",
        "Fuel Pump LOW PRESSURE Light (R FWD) - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_valve_open"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_VALVE_OPEN, "light_valve_open",
        "Crossfeed VALVE OPEN Light - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_filter_bypass_1"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_FILTER_BYPASS_1, "light_filter_bypass_1",
        "Engine 1 FILTER BYPASS Lights - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_filter_bypass_2"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_FILTER_BYPASS_2, "light_filter_bypass_2",
        "Engine 2 FILTER BYPASS Lights - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_eng_valve_closed_1"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_ENG_VALVE_CLOSED_1, "light_eng_valve_closed_1",
        "Engine 1 Valve Closed (ENG VALVE CLOSED) Light - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_eng_valve_closed_2"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_ENG_VALVE_CLOSED_2, "light_eng_valve_closed_2",
        "Engine 2 Valve Closed (ENG VALVE CLOSED) Light - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_spar_valve_closed_1"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_SPAR_VALVE_CLOSED_1, "light_spar_valve_closed_1",
        "Engine 1 Valve Closed (SPAR VALVE CLOSED) Light - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_spar_valve_closed_2"] = CommandInfo{
        KEY_COMMAND_FUEL_LIGHT_SPAR_VALVE_CLOSED_2, "light_spar_valve_closed_2",
        "Engine 2 Valve Closed (SPAR VALVE CLOSED) Light - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    // Fueling panel commands
    (*command_map)["fueling_valve_1"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_1, "fueling_valve_1",
        "Fueling Valve 1 - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_1_open"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_1_OPEN, "fueling_valve_1_open",
        "Fueling Valve 1 - Open", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_1_close"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_1_CLOSE, "fueling_valve_1_close",
        "Fueling Valve 1 - Close", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_c"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_C, "fueling_valve_c",
        "Fueling Valve C - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_c_open"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_C_OPEN, "fueling_valve_c_open",
        "Fueling Valve C - Open", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_c_close"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_C_CLOSE, "fueling_valve_c_close",
        "Fueling Valve C - Close", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_2"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_2, "fueling_valve_2",
        "Fueling Valve 2 - Click", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_2_open"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_2_OPEN, "fueling_valve_2_open",
        "Fueling Valve 2 - Open", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_2_close"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_2_CLOSE, "fueling_valve_2_close",
        "Fueling Valve 2 - Close", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_indication_test_up"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_UP, "fueling_indication_test_up",
        "Fueling Indication Test - Up", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_indication_test_down"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_DOWN, "fueling_indication_test_down",
        "Fueling Indication Test - Down", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_indication_test_test"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_TEST, "fueling_indication_test_test",
        "Fueling Indication Test - Test", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_indication_test_off"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_OFF, "fueling_indication_test_off",
        "Fueling Indication Test - Off", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_indication_test_bypass"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_INDICATION_TEST_BYPASS, "fueling_indication_test_bypass",
        "Fueling Indication Test - Bypass", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_1_light"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_1_LIGHT, "fueling_valve_1_light",
        "Fueling Valve Position Light 1 - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_c_light"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_C_LIGHT, "fueling_valve_c_light",
        "Fueling Valve Position Light C - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fueling_valve_2_light"] = CommandInfo{
        KEY_COMMAND_FUEL_FUELING_VALVE_2_LIGHT, "fueling_valve_2_light",
        "Fueling Valve Position Light 2 - Press", "fuel",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
