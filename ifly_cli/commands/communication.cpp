#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_communication_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["attendant_call"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_ATTENDANT_CALL, "attendant_call",
        "Attendant Call (ATTEND) Switch - Press", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ground_call"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_GROUND_CALL, "ground_call",
        "Ground Call (GRD CALL) Switch - Press", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_off"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_OFF, "rtp_1_off",
        "RTP 1, Radio Tuning Panel OFF Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_vhf1"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_VHF1, "rtp_1_vhf1",
        "RTP 1, Radio (VHF1) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_vhf2"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_VHF2, "rtp_1_vhf2",
        "RTP 1, Radio (VHF2) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_vhf3"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_VHF3, "rtp_1_vhf3",
        "RTP 1, Radio (VHF3) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_hf1"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_HF1, "rtp_1_hf1",
        "RTP 1, Radio (HF1) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_am"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_AM, "rtp_1_am",
        "RTP 1, AM Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_hf2"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_HF2, "rtp_1_hf2",
        "RTP 1, Radio (HF2) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_hf_sens_dec"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_HF_SENS_DEC, "rtp_1_hf_sens_dec",
        "RTP 1, HF Sensitivity Control - Rotate Left", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_hf_sens_inc"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_HF_SENS_INC, "rtp_1_hf_sens_inc",
        "RTP 1, HF Sensitivity Control - Rotate Right", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_transfer"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_TRANSFER, "rtp_1_transfer",
        "RTP 1, Frequency Transfer Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_fract_dec"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_FRACT_DEC, "rtp_1_fract_dec",
        "RTP 1, Frequency Selector (Inner) - Rotate Left", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_fract_inc"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_FRACT_INC, "rtp_1_fract_inc",
        "RTP 1, Frequency Selector (Inner) - Rotate Right", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_whole_dec"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_WHOLE_DEC, "rtp_1_whole_dec",
        "RTP 1, Frequency Selector (Outer) - Rotate Left", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_whole_inc"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_WHOLE_INC, "rtp_1_whole_inc",
        "RTP 1, Frequency Selector (Outer) - Rotate Right", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_1_test"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_1_TEST, "rtp_1_test",
        "RTP 1, VHF TEST Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_2_off"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_2_OFF, "rtp_2_off",
        "RTP 2, Radio Tuning Panel OFF Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_2_vhf1"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_2_VHF1, "rtp_2_vhf1",
        "RTP 2, Radio (VHF1) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_2_vhf2"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_2_VHF2, "rtp_2_vhf2",
        "RTP 2, Radio (VHF2) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["rtp_2_vhf3"] = CommandInfo{
        KEY_COMMAND_COMMUNICATION_RTP_2_VHF3, "rtp_2_vhf3",
        "RTP 2, Radio (VHF3) Tuning Switch - Click", "communication",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
