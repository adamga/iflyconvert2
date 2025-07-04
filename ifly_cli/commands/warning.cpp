#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_warning_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["master_fire_warn_light_l"] = CommandInfo{
        KEY_COMMAND_WARNING_MASTER_FIRE_WARN_LIGHT_L, "master_fire_warn_light_l",
        "Captain Side Master Fire Warning (FIRE WARN) Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["master_caution_l"] = CommandInfo{
        KEY_COMMAND_WARNING_MASTER_CAUTION_L, "master_caution_l",
        "Captain Side MASTER CAUTION Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["system_annunciator_l"] = CommandInfo{
        KEY_COMMAND_WARNING_SYSTEM_ANNUNCIATOR_L, "system_annunciator_l",
        "Captain Side System Annunciator Panel - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["master_fire_warn_light_r"] = CommandInfo{
        KEY_COMMAND_WARNING_MASTER_FIRE_WARN_LIGHT_R, "master_fire_warn_light_r",
        "FO Side Master Fire Warning (FIRE WARN) Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["master_caution_r"] = CommandInfo{
        KEY_COMMAND_WARNING_MASTER_CAUTION_R, "master_caution_r",
        "FO Side MASTER CAUTION Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["system_annunciator_r"] = CommandInfo{
        KEY_COMMAND_WARNING_SYSTEM_ANNUNCIATOR_R, "system_annunciator_r",
        "FO Side System Annunciator Panel - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["airspeed_test1"] = CommandInfo{
        KEY_COMMAND_WARNING_AIRSPEED_TEST1, "airspeed_test1",
        "MACH AIRSPEED WARNING TEST 1 Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["airspeed_test2"] = CommandInfo{
        KEY_COMMAND_WARNING_AIRSPEED_TEST2, "airspeed_test2",
        "MACH AIRSPEED WARNING TEST 2 Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_fdr_off"] = CommandInfo{
        KEY_COMMAND_WARNING_LIGHT_FDR_OFF, "light_fdr_off",
        "Flight Recorder OFF Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_below_gs_l"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_BELOW_GS_L, "gpws_below_gs_l",
        "Captain Side BELOW Glideslope (G/S) light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_below_gs_r"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_BELOW_GS_R, "gpws_below_gs_r",
        "FO Side BELOW Glideslope (G/S) light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_takeoff_config_l"] = CommandInfo{
        KEY_COMMAND_WARNING_LIGHT_TAKEOFF_CONFIG_L, "light_takeoff_config_l",
        "Captain Side Takeoff Configuration Warning Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_takeoff_config_r"] = CommandInfo{
        KEY_COMMAND_WARNING_LIGHT_TAKEOFF_CONFIG_R, "light_takeoff_config_r",
        "FO Side Takeoff Configuration Warning Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_cabin_altitude_l"] = CommandInfo{
        KEY_COMMAND_WARNING_LIGHT_CABIN_ALTITUDE_L, "light_cabin_altitude_l",
        "Captain Side Cabin Altitude Warning Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_cabin_altitude_r"] = CommandInfo{
        KEY_COMMAND_WARNING_LIGHT_CABIN_ALTITUDE_R, "light_cabin_altitude_r",
        "FO Side Cabin Altitude Warning Light - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_flap_inhibit"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_FLAP_INHIBIT, "gpws_flap_inhibit",
        "Ground Proximity FLAP INHIBIT Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_flap_inhibit_set"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_FLAP_INHIBIT_SET, "gpws_flap_inhibit_set",
        "Ground Proximity FLAP INHIBIT Switch - Set", "warning",
        {"inhibit", "normal"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch INHIBIT; 1:switch NORMAL"
    };
    (*command_map)["gpws_gear_inhibit"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_GEAR_INHIBIT, "gpws_gear_inhibit",
        "Ground Proximity GEAR INHIBIT Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_gear_inhibit_set"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_GEAR_INHIBIT_SET, "gpws_gear_inhibit_set",
        "Ground Proximity GEAR INHIBIT Switch - Set", "warning",
        {"inhibit", "normal"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch INHIBIT; 1:switch NORMAL"
    };
    (*command_map)["gpws_terr_inhibit"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_TERR_INHIBIT, "gpws_terr_inhibit",
        "Ground Proximity Terrain Inhibit (TERR INHIBIT) Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_terr_inhibit_set"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_TERR_INHIBIT_SET, "gpws_terr_inhibit_set",
        "Ground Proximity Terrain Inhibit (TERR INHIBIT) Switch - Set", "warning",
        {"inhibit", "normal"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch INHIBIT; 1:switch NORMAL"
    };
    (*command_map)["gpws_runway_inhibit"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_RUNWAY_INHIBIT, "gpws_runway_inhibit",
        "Ground Proximity Runway Inhibit (RUNWAY INHIBIT) Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_runway_inhibit_set"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_RUNWAY_INHIBIT_SET, "gpws_runway_inhibit_set",
        "Ground Proximity Runway Inhibit (RUNWAY INHIBIT) Switch - Set", "warning",
        {"inhibit", "normal"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch INHIBIT; 1:switch NORMAL"
    };
    (*command_map)["gpws_sys_test"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_SYS_TEST, "gpws_sys_test",
        "Ground Proximity System Test (SYS TEST) Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_gpws_inop"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_GPWS_INOP, "gpws_gpws_inop",
        "GPWS Inoperative (INOP) light - Press", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["gpws_runway_inop"] = CommandInfo{
        KEY_COMMAND_WARNING_GPWS_RUNWAY_INOP, "gpws_runway_inop",
        "Runway Inoperative (INOP) Light - Press", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["stall_1_test"] = CommandInfo{
        KEY_COMMAND_WARNING_STALL_1_TEST, "stall_1_test",
        "STALL WARNING TEST 1 Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["stall_2_test"] = CommandInfo{
        KEY_COMMAND_WARNING_STALL_2_TEST, "stall_2_test",
        "STALL WARNING TEST 2 Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ldg_gear_warning_cutout"] = CommandInfo{
        KEY_COMMAND_WARNING_LDG_GEAR_WARNING_CUTOUT, "ldg_gear_warning_cutout",
        "Landing Gear Warning Cutout Switch - Click", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["maint_light"] = CommandInfo{
        KEY_COMMAND_WARNING_MAINT_LIGHT, "maint_light",
        "Maintenance (MAINT) light - Press", "warning",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
