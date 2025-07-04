#include "command_info.h"
#include <map>
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_automatic_flight_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["course_1_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_DEC, "course_1_dec",
        "Left Course Selector - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["course_1_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_INC, "course_1_inc",
        "Left Course Selector - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["course_1_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_1_SET, "course_1_set",
        "Left Course Selector - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0~359"
    };
    (*command_map)["course_2_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_DEC, "course_2_dec",
        "Right Course Selector - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["course_2_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_INC, "course_2_inc",
        "Right Course Selector - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["course_2_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_COURSE_2_SET, "course_2_set",
        "Right Course Selector - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0~359"
    };
    (*command_map)["ias_mach_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_DEC, "ias_mach_dec",
        "IAS/MACH Selector - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ias_mach_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_INC, "ias_mach_inc",
        "IAS/MACH Selector - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["ias_mach_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_IAS_MACH_SET, "ias_mach_set",
        "IAS/MACH Selector - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0=MACH; 1=IAS; Value3: If Value2==0, then 0.60~0.82, If Value2==1, then 100~340"
    };
    (*command_map)["changeover"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_CHANGEOVER, "changeover",
        "Changeover (C/O) Switch - Click", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["changeover_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_CHANGEOVER_SET, "changeover_set",
        "Changeover (C/O) Switch - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0=MACH; 1=IAS"
    };
    (*command_map)["bank_angle_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_DEC, "bank_angle_dec",
        "Bank Angle Selector - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["bank_angle_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_INC, "bank_angle_inc",
        "Bank Angle Selector - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["bank_angle_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_BANK_ANGLE_SET, "bank_angle_set",
        "Bank Angle Selector - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0=10degree, 1=15degree, 2=20degree, 3=25degree, 4=30degree"
    };
    (*command_map)["hdg_sel_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_DEC, "hdg_sel_dec",
        "Heading Selector - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["hdg_sel_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_INC, "hdg_sel_inc",
        "Heading Selector - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["hdg_sel_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_HDG_SEL_SET, "hdg_sel_set",
        "Heading Selector - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0~359"
    };
    (*command_map)["alt_sel_dec"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_DEC, "alt_sel_dec",
        "Altitude Selector (SEL) - Rotate Left", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alt_sel_inc"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_INC, "alt_sel_inc",
        "Altitude Selector (SEL) - Rotate Right", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["alt_sel_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_ALT_SEL_SET, "alt_sel_set",
        "Altitude Selector (SEL) - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: 0~50000, 100ft increments"
    };
    (*command_map)["vs_down"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_VS_DOWN, "vs_down",
        "Vertical Speed Thumbwheel - Rotate Down", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["vs_up"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_VS_UP, "vs_up",
        "Vertical Speed Thumbwheel - Rotate Up", "automatic_flight",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["vs_set"] = CommandInfo{
        KEY_COMMAND_AUTOMATICFLIGHT_VS_SET, "vs_set",
        "Vertical Speed Thumbwheel - Set", "automatic_flight",
        {},
        "0: OFF the click sound; 1: ON the click sound",
        "Value2: -7900~6000. 50fpm increments if V/S is less than 1000 fpm, 100 fpm if V/S is 1000 fpm or greater"
    };
    // ...continue for all KEY_COMMAND_AUTOMATICFLIGHT_* commands as in key_command.h...
}
