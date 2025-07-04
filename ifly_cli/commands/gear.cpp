#include "command_info.h"
#include "../737MAX_SDK/sdk/key_command.h"

void initialize_gear_commands(std::map<std::string, CommandInfo>* command_map) {
    (*command_map)["lever"] = CommandInfo{
        KEY_COMMAND_GEAR_LEVER, "lever",
        "LANDING GEAR Lever - Click", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["lever_set"] = CommandInfo{
        KEY_COMMAND_GEAR_LEVER_SET, "lever_set",
        "LANDING GEAR Lever - Set", "gear",
        {"up", "dn"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch UP; 1:switch DN"
    };
    (*command_map)["steering_switch"] = CommandInfo{
        KEY_COMMAND_GEAR_STEERING_SWITCH, "steering_switch",
        "NOSE WHEEL STEER Switch - Click", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["steering_switch_set"] = CommandInfo{
        KEY_COMMAND_GEAR_STEERING_SWITCH_SET, "steering_switch_set",
        "NOSE WHEEL STEER Switch - Set", "gear",
        {"alt", "norm"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch ALT; 1:switch NORM"
    };
    (*command_map)["lever_lock_switch"] = CommandInfo{
        KEY_COMMAND_GEAR_LEVER_LOCK_SWITCH, "lever_lock_switch",
        "Landing Gear Lever Lock Override (LOCK OVRD) Switch - Click", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["parking_brake"] = CommandInfo{
        KEY_COMMAND_GEAR_PARKING_BRAKE, "parking_brake",
        "PARKING BRAKE Lever - Click", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: use real logic(need brake pedals to set the brake); 1: ignore the brake pedals position, set the parking brake directly"
    };
    (*command_map)["parking_brake_set"] = CommandInfo{
        KEY_COMMAND_GEAR_PARKING_BRAKE_SET, "parking_brake_set",
        "PARKING BRAKE Lever - Set", "gear",
        {"release", "set"},
        "0: OFF the click sound; 1: ON the click sound",
        "0: switch RELEASE; 1:switch SET",
        "0: use real logic(need brake pedals to set the brake); 1: ignore the brake pedals position, set the parking brake directly"
    };
    (*command_map)["steer"] = CommandInfo{
        KEY_COMMAND_GEAR_STEER, "steer",
        "Rotate the Nose Wheel Steering Wheel at the captain side panel", "gear",
        {},
        "Value1: -78~+78 degree"
    };
    (*command_map)["autobrake_dec"] = CommandInfo{
        KEY_COMMAND_GEAR_AUTOBRAKE_DEC, "autobrake_dec",
        "AUTO BRAKE Select Switch - Rotate Left", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["autobrake_inc"] = CommandInfo{
        KEY_COMMAND_GEAR_AUTOBRAKE_INC, "autobrake_inc",
        "AUTO BRAKE Select Switch - Rotate Right", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["autobrake_set"] = CommandInfo{
        KEY_COMMAND_GEAR_AUTOBRAKE_SET, "autobrake_set",
        "AUTO BRAKE Select Switch - Set", "gear",
        {"rto", "off", "1", "2", "3", "max"},
        "0: OFF the click sound; 1: ON the click sound",
        "0:switch RTO; 1:switch OFF; 2:switch 1; 3:switch 2; 4:switch 3; 5:switch MAX"
    };
    (*command_map)["light_nose_gear_red"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_NOSE_GEAR_RED, "light_nose_gear_red",
        "Nose Landing Gear Indicator Light (Top) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_nose_gear_green"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_NOSE_GEAR_GREEN, "light_nose_gear_green",
        "Nose Landing Gear Indicator Light (Bottom) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_left_gear_red"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_LEFT_GEAR_RED, "light_left_gear_red",
        "Left Landing Gear Indicator Light (Top) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_left_gear_green"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_LEFT_GEAR_GREEN, "light_left_gear_green",
        "Left Landing Gear Indicator Light (Bottom) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_right_gear_red"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_RIGHT_GEAR_RED, "light_right_gear_red",
        "Right Landing Gear Indicator Light (Top) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_right_gear_green"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_RIGHT_GEAR_GREEN, "light_right_gear_green",
        "Right Landing Gear Indicator Light (Bottom) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_sys2_left_gear"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_SYS2_LEFT_GEAR, "light_sys2_left_gear",
        "Left Landing Gear Indicator Light (Aft Overhead Panel) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_sys2_nose_gear"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_SYS2_NOSE_GEAR, "light_sys2_nose_gear",
        "Nose Landing Gear Indicator Light (Aft Overhead Panel) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_sys2_right_gear"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_SYS2_RIGHT_GEAR, "light_sys2_right_gear",
        "Right Landing Gear Indicator Light (Aft Overhead Panel) - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
    (*command_map)["light_auto_brake_disarm"] = CommandInfo{
        KEY_COMMAND_GEAR_LIGHT_AUTO_BRAKE_DISARM, "light_auto_brake_disarm",
        "AUTO BRAKE DISARM Light - Press", "gear",
        {"off", "on"},
        "0: OFF the click sound; 1: ON the click sound"
    };
}
