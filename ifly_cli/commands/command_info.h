#ifndef COMMAND_INFO_H
#define COMMAND_INFO_H

#include <string>
#include <vector>
#include "../737MAX_SDK/sdk/key_command.h"

#include <map>

struct CommandInfo {
    KEY_COMMAND_IFLY737MAX command_id;
    std::string name;
    std::string description;
    std::string category;
    std::vector<std::string> valid_values;
    std::string value1_desc;
    std::string value2_desc;
    std::string value3_desc;
    std::string get_variable_name; // For reading current state from shared memory
};

void initialize_lights_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_air_systems_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_anti_ice_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_apu_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_general_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_annunciators_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_automatic_flight_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_communication_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_electrical_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_engapu_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_fire_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_fltctrl_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_fms_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_fuel_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_gear_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_hydraulic_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_instrument_commands(std::map<std::string, CommandInfo>* command_map);
void initialize_warning_commands(std::map<std::string, CommandInfo>* command_map);

#endif // COMMAND_INFO_H
