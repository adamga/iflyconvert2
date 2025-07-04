#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_instrument_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["efis_l_left_voradf_dec"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_DEC, "efis_l_left_voradf_dec",
        "Captain Side EFIS, Left VOR/ADF Switch - Move Up", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_left_voradf_inc"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_INC, "efis_l_left_voradf_inc",
        "Captain Side EFIS, Left VOR/ADF Switch - Move Down", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_left_voradf_set"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_LEFT_VORADF_SET, "efis_l_left_voradf_set",
        "Captain Side EFIS, Left VOR/ADF Switch - Set", "instrument",
        {"vor", "off", "adf"},
        "0: OFF the click sound; 1: ON the click sound",
        "0=VOR; 1=OFF; 2=ADF"
    };
    (*command_map)["efis_l_right_voradf_dec"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_DEC, "efis_l_right_voradf_dec",
        "Captain Side EFIS, Right VOR/ADF Switch - Move Up", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_right_voradf_inc"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_INC, "efis_l_right_voradf_inc",
        "Captain Side EFIS, Right VOR/ADF Switch - Move Down", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_right_voradf_set"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_RIGHT_VORADF_SET, "efis_l_right_voradf_set",
        "Captain Side EFIS, Right VOR/ADF Switch - Set", "instrument",
        {"vor", "off", "adf"},
        "0: OFF the click sound; 1: ON the click sound",
        "0=VOR; 1=OFF; 2=ADF"
    };
    (*command_map)["efis_l_mins_ref_radio"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_REF_RADIO, "efis_l_mins_ref_radio",
        "Captain Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select RADIO", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_mins_ref_baro"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_REF_BARO, "efis_l_mins_ref_baro",
        "Captain Side EFIS, Minimums (MINS) Reference Selector (Outer) - Select BARO", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_mins_dec"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_DEC, "efis_l_mins_dec",
        "Captain Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Left", "instrument",
        {"auto", "slow", "fast"},
        "0: OFF the click sound; 1: ON the click sound",
        "0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode"
    };
    (*command_map)["efis_l_mins_inc"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_INC, "efis_l_mins_inc",
        "Captain Side EFIS, Minimums (MINS) Selector (Middle) - Rotate Right", "instrument",
        {"auto", "slow", "fast"},
        "0: OFF the click sound; 1: ON the click sound",
        "0=Auto; 1=Selector rotate in slow mode; 2=Selector rotate in fast mode"
    };
    (*command_map)["efis_l_mins_set"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_SET, "efis_l_mins_set",
        "Captain Side EFIS, Minimums (MINS) Selector (Middle) - Set", "instrument",
        {"altitude"},
        "0: OFF the click sound; 1: ON the click sound",
        "altitude"
    };
    (*command_map)["efis_l_mins_rst"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MINS_RST, "efis_l_mins_rst",
        "Captain Side EFIS, Radio Minimums (MINS) Reset (RST) Switch (Inner) - Click", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_mtrs"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MTRS, "efis_l_mtrs",
        "Captain Side EFIS, Meters (MTRS) Switch - Click", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_fpv"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_FPV, "efis_l_fpv",
        "Captain Side EFIS, Flight Path Vector (FPV) Switch - Click", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_baro_ref_hpa"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_REF_HPA, "efis_l_baro_ref_hpa",
        "Captain Side EFIS, Barometric (BARO) Reference Selector (Outer) - Select HPA", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_baro_ref_in"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_REF_IN, "efis_l_baro_ref_in",
        "Captain Side EFIS, Barometric (BARO) Reference Selector (Outer) - Select IN", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_baro_dec"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_DEC, "efis_l_baro_dec",
        "Captain Side EFIS, Barometric (BARO) Selector (Middle) - Rotate Left", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_baro_inc"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_INC, "efis_l_baro_inc",
        "Captain Side EFIS, Barometric (BARO) Selector (Middle) - Rotate Right", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_baro_std"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_BARO_STD, "efis_l_baro_std",
        "Captain Side EFIS, Barometric (BARO) Standard (STD) Switch (Inner) - Click", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_ctr"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_CTR, "efis_l_ctr",
        "Captain Side EFIS, Center (CTR) Switch - Click", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["efis_l_mode_dec"] = CommandInfo{
        KEY_COMMAND_INSTRUMENT_EFIS_L_MODE_DEC, "efis_l_mode_dec",
        "Captain Side EFIS, Mode Selector (Outer) - Rotate Left", "instrument",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
