#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_fms_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["vhf_nav_dec"] = CommandInfo{
        KEY_COMMAND_FMS_VHF_NAV_DEC, "vhf_nav_dec",
        "VHF NAV Transfer Switch - Move Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["vhf_nav_inc"] = CommandInfo{
        KEY_COMMAND_FMS_VHF_NAV_INC, "vhf_nav_inc",
        "VHF NAV Transfer Switch - Move Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["vhf_nav_set"] = CommandInfo{
        KEY_COMMAND_FMS_VHF_NAV_SET, "vhf_nav_set",
        "VHF NAV Transfer Switch - Click", "fms",
        {"both_on_1", "normal", "both_on_2"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch BOTH ON 1; 1:switch NORMAL; 2:switch BOTH ON 2"
    };
    (*command_map)["irs_tfr_dec"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_TFR_DEC, "irs_tfr_dec",
        "IRS Transfer Switch - Move Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_tfr_inc"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_TFR_INC, "irs_tfr_inc",
        "IRS Transfer Switch - Move Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_tfr_set"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_TFR_SET, "irs_tfr_set",
        "IRS Transfer Switch - Click", "fms",
        {"both_on_l", "normal", "both_on_r"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch BOTH ON L; 1:switch NORMAL; 2:switch BOTH ON R"
    };
    (*command_map)["fmc_source_select_dec"] = CommandInfo{
        KEY_COMMAND_FMS_FMC_SOURCE_SELECT_DEC, "fmc_source_select_dec",
        "FMC Source Select Switch - Move Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fmc_source_select_inc"] = CommandInfo{
        KEY_COMMAND_FMS_FMC_SOURCE_SELECT_INC, "fmc_source_select_inc",
        "FMC Source Select Switch - Move Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["fmc_source_select_set"] = CommandInfo{
        KEY_COMMAND_FMS_FMC_SOURCE_SELECT_SET, "fmc_source_select_set",
        "FMC Source Select Switch - Click", "fms",
        {"both_on_l", "normal", "both_on_r"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch BOTH ON L; 1:switch NORMAL; 2:switch BOTH ON R"
    };
    (*command_map)["irs_dspl_brt_dec"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_DSPL_BRT_DEC, "irs_dspl_brt_dec",
        "Brightness (BRT) Control - Rotate Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_dspl_brt_inc"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_DSPL_BRT_INC, "irs_dspl_brt_inc",
        "Brightness (BRT) Control - Rotate Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_dspl_sel_dec"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_DSPL_SEL_DEC, "irs_dspl_sel_dec",
        "Display Selector (DSPL SEL) - Move Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_dspl_sel_inc"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_DSPL_SEL_INC, "irs_dspl_sel_inc",
        "Display Selector (DSPL SEL) - Move Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_dspl_sel_set"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_DSPL_SEL_SET, "irs_dspl_sel_set",
        "Display Selector (DSPL SEL) - Click", "fms",
        {"test", "tk_gs", "ppos", "wind", "hdg_sts"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch TEST; 1:switch TK/GS; 2:switch PPOS; 3:switch WIND; 4:switch HDG/STS"
    };
    (*command_map)["irs_sys_dspl"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_SYS_DSPL, "irs_sys_dspl",
        "System Display (SYS DSPL) Selector - Click", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_sys_dspl_set"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_SYS_DSPL_SET, "irs_sys_dspl_set",
        "System Display (SYS DSPL) Selector - Set", "fms",
        {"l", "r"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch L; 1:switch R"
    };
    (*command_map)["irs_l_mode_dec"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_L_MODE_DEC, "irs_l_mode_dec",
        "Left Inertial Reference System (IRS) Mode Selector - Rotate Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_l_mode_inc"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_L_MODE_INC, "irs_l_mode_inc",
        "Left Inertial Reference System (IRS) Mode Selector - Rotate Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_l_mode_set"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_L_MODE_SET, "irs_l_mode_set",
        "Left Inertial Reference System (IRS) Mode Selector - Set", "fms",
        {"off", "align", "nav", "att"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch OFF; 1:switch ALIGN; 2:switch NAV; 3:switch ATT"
    };
    (*command_map)["irs_r_mode_dec"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_R_MODE_DEC, "irs_r_mode_dec",
        "Right Inertial Reference System (IRS) Mode Selector - Rotate Left", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["irs_r_mode_inc"] = CommandInfo{
        KEY_COMMAND_FMS_IRS_R_MODE_INC, "irs_r_mode_inc",
        "Right Inertial Reference System (IRS) Mode Selector - Rotate Right", "fms",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
