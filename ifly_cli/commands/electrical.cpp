#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_electrical_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["idg_1_disconnect"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IDG_1_DISCONNECT, "idg_1_disconnect",
        "Left Generator Drive Disconnect (DISCONNECT) Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["idg_1_disconnect_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IDG_1_DISCONNECT_SET, "idg_1_disconnect_set",
        "Left Generator Drive Disconnect (DISCONNECT) Switch - Set", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: switch Connect; 1: switch Disconnect",
        "1: ignore the guard, press the button directly"
    };
    (*command_map)["idg_2_disconnect"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IDG_2_DISCONNECT, "idg_2_disconnect",
        "Right Generator Drive Disconnect (DISCONNECT) Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["idg_2_disconnect_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IDG_2_DISCONNECT_SET, "idg_2_disconnect_set",
        "Right Generator Drive Disconnect (DISCONNECT) Switch - Set", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: switch Connect; 1: switch Disconnect",
        "1: ignore the guard, press the button directly"
    };
    (*command_map)["generator_1_up"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_1_UP, "generator_1_up",
        "Generator (GEN) 1 Switch - Move Up", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["generator_1_down"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_1_DOWN, "generator_1_down",
        "Generator (GEN) 1 Switch - Move Down", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["generator_1_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_1_SET, "generator_1_set",
        "Generator (GEN) 1 Switch - Set", "electrical",
        {"off", "neutral", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch Neutral; 2:switch ON"
    };
    (*command_map)["generator_2_up"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_2_UP, "generator_2_up",
        "Generator (GEN) 2 Switch - Move Up", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["generator_2_down"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_2_DOWN, "generator_2_down",
        "Generator (GEN) 2 Switch - Move Down", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["generator_2_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GENERATOR_2_SET, "generator_2_set",
        "Generator (GEN) 2 Switch - Set", "electrical",
        {"off", "neutral", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch Neutral; 2:switch ON"
    };
    (*command_map)["apu_generator_1_up"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_UP, "apu_generator_1_up",
        "APU Generator (GEN) 1 Switch - Move Up", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_generator_1_down"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_DOWN, "apu_generator_1_down",
        "APU Generator (GEN) 1 Switch - Move Down", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_generator_1_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_1_SET, "apu_generator_1_set",
        "APU Generator (GEN) 1 Switch - Set", "electrical",
        {"off", "neutral", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch Neutral; 2:switch ON"
    };
    (*command_map)["apu_generator_2_up"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_UP, "apu_generator_2_up",
        "APU Generator (GEN) 2 Switch - Move Up", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_generator_2_down"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_DOWN, "apu_generator_2_down",
        "APU Generator (GEN) 2 Switch - Move Down", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["apu_generator_2_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_APU_GENERATOR_2_SET, "apu_generator_2_set",
        "APU Generator (GEN) 2 Switch - Set", "electrical",
        {"off", "neutral", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch Neutral; 2:switch ON"
    };
    (*command_map)["grd_pwr_up"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GRD_PWR_UP, "grd_pwr_up",
        "Ground Power (GRD PWR) Switch - Move Up", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["grd_pwr_down"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GRD_PWR_DOWN, "grd_pwr_down",
        "Ground Power (GRD PWR) Switch - Move Down", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["grd_pwr_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_GRD_PWR_SET, "grd_pwr_set",
        "Ground Power (GRD PWR) Switch - Set", "electrical",
        {"off", "neutral", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch Neutral; 2:switch ON"
    };
    (*command_map)["bat"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_BAT, "bat",
        "Battery (BAT) Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["bat_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_BAT_SET, "bat_set",
        "Battery (BAT) Switch - Set", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON",
        "1: ignore the guard, press the button directly"
    };
    (*command_map)["bus_transfer"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_BUS_TRANSFER, "bus_transfer",
        "BUS TRANSFER Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["bus_transfer_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_BUS_TRANSFER_SET, "bus_transfer_set",
        "BUS TRANSFER Switch - Set", "electrical",
        {"off", "auto"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch AUTO",
        "1: ignore the guard, press the button directly"
    };
    (*command_map)["standby_power_dec"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_STANDBY_POWER_DEC, "standby_power_dec",
        "STANDBY POWER Switch - Move Left", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["standby_power_inc"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_STANDBY_POWER_INC, "standby_power_inc",
        "STANDBY POWER Switch - Move Right", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["standby_power_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_STANDBY_POWER_SET, "standby_power_set",
        "STANDBY POWER Switch - Set", "electrical",
        {"bat", "off", "auto"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch BAT; 1:switch OFF; 2:switch AUTO",
        "1: ignore the guard, press the button directly"
    };
    (*command_map)["cab_util"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_CAB_UTIL, "cab_util",
        "CAB/UTIL Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["cab_util_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_CAB_UTIL_SET, "cab_util_set",
        "CAB/UTIL Switch - Set", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["ife_pass_seat"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IFE_PASS_SEAT, "ife_pass_seat",
        "IFE/PASS SEAT Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ife_pass_seat_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_IFE_PASS_SEAT_SET, "ife_pass_seat_set",
        "IFE/PASS SEAT Switch - Set", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ON"
    };
    (*command_map)["dc_meter_dec"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_DC_METER_DEC, "dc_meter_dec",
        "DC Meters Selector - Rotate Left", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["dc_meter_inc"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_DC_METER_INC, "dc_meter_inc",
        "DC Meters Selector - Rotate Right", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["dc_meter_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_DC_METER_SET, "dc_meter_set",
        "DC Meters Selector - Set", "electrical",
        {"stby_pwr", "bat_bus", "bat", "aux_bat", "tr1", "tr2", "tr3", "test"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch STBY PWR; 1:switch BAT BUS; 2:switch BAT; 3:switch AUX BAT; 4:switch TR1; 5:switch TR2; 6:switch TR3; 7:switch TEST"
    };
    (*command_map)["ac_meter_dec"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_AC_METER_DEC, "ac_meter_dec",
        "AC Meters Selector - Rotate Left", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ac_meter_inc"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_AC_METER_INC, "ac_meter_inc",
        "AC Meters Selector - Rotate Right", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ac_meter_set"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_AC_METER_SET, "ac_meter_set",
        "AC Meters Selector - Set", "electrical",
        {"stby_pwr", "grd_pwr", "gen1", "apu_gen", "gen2", "inv", "test"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch STBY PWR; 1:switch GRD PWR; 2:switch GEN1; 3:switch APU GEN; 4:switch GEN2; 5:switch INV; 6:switch TEST"
    };
    (*command_map)["maint"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_MAINT, "maint",
        "Maintenance Test (MAINT) Switch - Click", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_grd_power_available"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_GRD_POWER_AVAILABLE, "light_grd_power_available",
        "Ground Power Available (GRD POWER AVAILABLE) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_drive_1"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_DRIVE_1, "light_drive_1",
        "Left Generator Drive (DRIVE) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_drive_2"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_DRIVE_2, "light_drive_2",
        "Right Generator Drive (DRIVE) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_standby_pwr_off"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_STANDBY_PWR_OFF, "light_standby_pwr_off",
        "STANDBY Power Off (PWR OFF) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_gen_off_bus_1"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_GEN_OFF_BUS_1, "light_gen_off_bus_1",
        "Left Generator Off Bus (GEN OFF BUS) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_gen_off_bus_2"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_GEN_OFF_BUS_2, "light_gen_off_bus_2",
        "Right Generator Off Bus (GEN OFF BUS) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_transfer_bus_off_1"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_1, "light_transfer_bus_off_1",
        "Left TRANSFER BUS OFF Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_transfer_bus_off_2"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_TRANSFER_BUS_OFF_2, "light_transfer_bus_off_2",
        "Right TRANSFER BUS OFF Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_source_off_1"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_SOURCE_OFF_1, "light_source_off_1",
        "Left SOURCE OFF Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_source_off_2"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_SOURCE_OFF_2, "light_source_off_2",
        "Right SOURCE OFF Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_apu_gen_off_bus"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_APU_GEN_OFF_BUS, "light_apu_gen_off_bus",
        "APU Generator Off Bus (GEN OFF BUS) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_bat_discharge"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_BAT_DISCHARGE, "light_bat_discharge",
        "Battery Discharge (BAT DISCHARGE) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_tr_unit"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_TR_UNIT, "light_tr_unit",
        "TR UNIT Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_elec"] = CommandInfo{
        KEY_COMMAND_ELECTRICAL_LIGHT_ELEC, "light_elec",
        "Electrical (ELEC) Light - Press", "electrical",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
