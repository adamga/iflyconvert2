/*
 * iFly 737 MAX 8 Command Line Interface
 * 
 * A comprehensive CLI tool for controlling the iFly 737 MAX 8 aircraft
 * using the iFly SDK. Supports setting values, querying current states,
 * and provides intelligent help with valid value ranges.
 * 
 * Usage:
 *   ifly_cli.exe list                           # List all available commands
 *   ifly_cli.exe set <command> <value>          # Set a command to a specific value
 *   ifly_cli.exe get <command>                  # Get current value of a command
 *   ifly_cli.exe help [command]                 # Get help for all commands or specific command
 *   ifly_cli.exe connect                        # Test connection to iFly 737 MAX
 * 
 * Examples:
 *   ifly_cli.exe set landing_light_1 on
 *   ifly_cli.exe get landing_light_1
 *   ifly_cli.exe help landing_light_1
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <windows.h>

// Include iFly SDK headers
#include "../737MAX_SDK/sdk/SDK.h"
#include "../737MAX_SDK/sdk/key_command.h"
#include "../737MAX_SDK/sdk/SDK_Defines.h"

#include "commands/general.cpp"
#include "commands/lights.cpp"
#include "commands/air_systems.cpp"
#include "commands/anti_ice.cpp"
#include "commands/apu.cpp"
#include "commands/annunciators.cpp"
#include "commands/command_info.h"
#include "commands/automatic_flight.cpp" // Include automatic flight commands
#include "commands/electrical.cpp"
#include "commands/engapu.cpp"
#include "commands/fuel.cpp"
#include "commands/hydraulic.cpp"
#include "commands/fltctrl.cpp"
#include "commands/warning.cpp"
#include "commands/communication.cpp"
#include "commands/fire.cpp"
#include "commands/fms.cpp"
#include "commands/gear.cpp"
#include "commands/instrument.cpp"


// Forward declarations
class iFlyCommander;

// Global variables (avoid conflicts with SDK static variables)
ShareMemory737MAXSDK* g_pShareMem737MAXSDK = new ShareMemory737MAXSDK;
HANDLE g_hMapFile737MAXSDK = nullptr;
LPCTSTR g_pBuf737MAXSDK = nullptr;

// Remove any redefinition of szName737MAXSDK here

class iFlyCommander {
public:
    iFlyCommander();
    ~iFlyCommander();
    bool initialize();
    bool connect_to_ifly();
    void disconnect();
    bool send_command(const std::string& command_name, const std::string& value);
    std::string get_command_value(const std::string& command_name);
    void list_commands();
    void list_commands_by_category(const std::string& category);
    void show_help(const std::string& command_name = "");
    bool parse_and_execute(int argc, char* argv[]);
    std::vector<std::string> split_string(const std::string& str, char delimiter);
    void print_usage();

private:
    std::map<std::string, CommandInfo> command_map;
    bool is_connected = false;
    void initialize_command_map();
    void add_command(KEY_COMMAND_IFLY737MAX cmd_id, const std::string& name, 
                    const std::string& description, const std::string& category,
                    const std::vector<std::string>& valid_values,
                    const std::string& value1_desc = "", const std::string& value2_desc = "",
                    const std::string& value3_desc = "", const std::string& get_var = "");
    std::string to_lower(const std::string& str);
    int parse_value_to_int(const std::string& value, const std::vector<std::string>& valid_values);
};

iFlyCommander::iFlyCommander() {
    initialize_command_map();
}

iFlyCommander::~iFlyCommander() {
    disconnect();
}

bool iFlyCommander::initialize() {
    // Initialize the SDK for MSFS 2020
    iFly737MAX_Init_SendMessage(VER_MSFS2020);
    return true;
}

bool iFlyCommander::connect_to_ifly() {
    // Open the shared memory file mapping
    // Convert wide string szName737MAXSDK to narrow string for ANSI API
    char narrow_szName737MAXSDK[256];
    WideCharToMultiByte(CP_ACP, 0, szName737MAXSDK, -1, narrow_szName737MAXSDK, 256, NULL, NULL);
    g_hMapFile737MAXSDK = OpenFileMapping(FILE_MAP_READ, FALSE, narrow_szName737MAXSDK);
    
    if (g_hMapFile737MAXSDK != nullptr) {
        g_pBuf737MAXSDK = (LPTSTR)MapViewOfFile(g_hMapFile737MAXSDK, FILE_MAP_READ, 0, 0, BUF_SIZE_737MAXSDK);
        
        if (g_pBuf737MAXSDK) {
            CopyMemory((PVOID)g_pShareMem737MAXSDK, g_pBuf737MAXSDK, sizeof(struct ShareMemory737MAXSDK));
            
            if (g_pShareMem737MAXSDK->iFly737MAX_STATE == iFly737MAX_RUNNING) {
                is_connected = true;
                return true;
            }
        }
    }
    
    return false;
}

void iFlyCommander::disconnect() {
    if (g_pBuf737MAXSDK) {
        UnmapViewOfFile(g_pBuf737MAXSDK);
        g_pBuf737MAXSDK = nullptr;
    }
    
    if (g_hMapFile737MAXSDK) {
        CloseHandle(g_hMapFile737MAXSDK);
        g_hMapFile737MAXSDK = nullptr;
    }
    
    is_connected = false;
}

bool iFlyCommander::send_command(const std::string& command_name, const std::string& value) {
    // Ensure SDK is initialized for sending commands
    iFly737MAX_Init_SendMessage(VER_MSFS2020);
    
    // Test connection to make sure iFly is running
    std::cout << "Testing connection to iFly 737 MAX..." << std::endl;
    if (!connect_to_ifly()) {
        std::cout << "Warning: Cannot connect to iFly 737 MAX. Command may not take effect." << std::endl;
        std::cout << "Please ensure:" << std::endl;
        std::cout << "  1. Microsoft Flight Simulator is running" << std::endl;
        std::cout << "  2. iFly 737 MAX aircraft is loaded" << std::endl;
        std::cout << "  3. iFly plugin is active" << std::endl;
        std::cout << "Proceeding to send command anyway..." << std::endl;
    } else {
        std::cout << "Connected to iFly 737 MAX successfully." << std::endl;
    }
    
    auto it = command_map.find(to_lower(command_name));
    if (it == command_map.end()) {
        std::cout << "Error: Unknown command '" << command_name << "'" << std::endl;
        return false;
    }
    
    const CommandInfo& cmd = it->second;
    
    // Parse the value
    int int_value = parse_value_to_int(value, cmd.valid_values);
    if (int_value == -1) {
        std::cout << "Error: Invalid value '" << value << "' for command '" << command_name << "'" << std::endl;
        std::cout << "Valid values: ";
        for (size_t i = 0; i < cmd.valid_values.size(); ++i) {
            std::cout << cmd.valid_values[i];
            if (i < cmd.valid_values.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
        return false;
    }
    
    // Send the command with proper parameters
    // Value1 = 1 (enable click sound), Value2 = the actual command value, Value3 = 0
    std::cout << "Sending SDK command ID: " << cmd.command_id << " with values (1, " << int_value << ", 0)" << std::endl;
    iFly737MAX_SendMessage(cmd.command_id, 1, int_value, 0);
    
    std::cout << "Command sent: " << command_name << " = " << value << " (SDK value: " << int_value << ")" << std::endl;
    std::cout << "Note: Command will take effect if iFly 737 MAX is running and aircraft is loaded." << std::endl;
    return true;
}

std::string iFlyCommander::get_command_value(const std::string& command_name) {
    if (!is_connected) {
        return "Not connected to iFly 737 MAX";
    }
    
    // Refresh shared memory data
    if (g_pBuf737MAXSDK) {
        CopyMemory((PVOID)g_pShareMem737MAXSDK, g_pBuf737MAXSDK, sizeof(struct ShareMemory737MAXSDK));
    }
    
    auto it = command_map.find(to_lower(command_name));
    if (it == command_map.end()) {
        return "Unknown command";
    }
    
    const CommandInfo& cmd = it->second;
    
    // Map some common commands to their shared memory variables
    // This is a simplified mapping - in a full implementation, you'd map all commands
    if (command_name == "landing_light_1") {
        int value = g_pShareMem737MAXSDK->Landing_Light_1_Switch_Status;
        return (value == 0) ? "OFF" : "ON";
    }
    else if (command_name == "landing_light_2") {
        int value = g_pShareMem737MAXSDK->Landing_Light_2_Switch_Status;
        return (value == 0) ? "OFF" : "ON";
    }
    else if (command_name == "taxi_light") {
        int value = g_pShareMem737MAXSDK->Taxi_Light_Switch_Status;
        return (value == 0) ? "OFF" : "ON";
    }
    // Add more mappings as needed...
    
    return "Current value not available";
}

void iFlyCommander::list_commands() {
    std::cout << "\n=== iFly 737 MAX 8 Available Commands ===" << std::endl;
    std::cout << std::setw(25) << std::left << "Command" << std::setw(15) << "Category" << "Description" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    
    for (const auto& pair : command_map) {
        const CommandInfo& cmd = pair.second;
        std::cout << std::setw(25) << std::left << pair.first 
                  << std::setw(15) << cmd.category 
                  << cmd.description << std::endl;
    }
    
    std::cout << "\nUse 'help <command>' for detailed information about a specific command." << std::endl;
}

void iFlyCommander::list_commands_by_category(const std::string& category) {
    std::cout << "\n=== " << category << " Commands ===" << std::endl;
    std::cout << std::setw(25) << std::left << "Command" << "Description" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    
    for (const auto& pair : command_map) {
        const CommandInfo& cmd = pair.second;
        if (to_lower(cmd.category) == to_lower(category)) {
            std::cout << std::setw(25) << std::left << pair.first << cmd.description << std::endl;
        }
    }
}

void iFlyCommander::show_help(const std::string& command_name) {
    if (command_name.empty()) {
        std::cout << "\n=== iFly 737 MAX 8 CLI Help ===" << std::endl;
        std::cout << "Usage: ifly_cli.exe [command] [options]" << std::endl;
        std::cout << "\nCommands:" << std::endl;
        std::cout << "  list                     - List all available commands" << std::endl;
        std::cout << "  set <command> <value>    - Set a command to a specific value" << std::endl;
        std::cout << "  get <command>            - Get current value of a command" << std::endl;
        std::cout << "  help [command]           - Show help for all commands or specific command" << std::endl;
        std::cout << "  connect                  - Test connection to iFly 737 MAX" << std::endl;
        std::cout << "\nCategories:" << std::endl;
        std::cout << "  lights                   - Aircraft lighting controls" << std::endl;
        std::cout << "  air_systems              - Air conditioning and pressurization" << std::endl;
        std::cout << "  anti_ice                 - Anti-ice systems" << std::endl;
        std::cout << "  hydraulics               - Hydraulic systems" << std::endl;
        std::cout << "  fuel                     - Fuel system controls" << std::endl;
        std::cout << "\nExamples:" << std::endl;
        std::cout << "  ifly_cli.exe set landing_light_1 on" << std::endl;
        std::cout << "  ifly_cli.exe get taxi_light" << std::endl;
        std::cout << "  ifly_cli.exe help landing_light_1" << std::endl;
        return;
    }
    
    auto it = command_map.find(to_lower(command_name));
    if (it == command_map.end()) {
        std::cout << "Error: Unknown command '" << command_name << "'" << std::endl;
        return;
    }
    
    const CommandInfo& cmd = it->second;
    std::cout << "\n=== Help for '" << command_name << "' ===" << std::endl;
    std::cout << "Description: " << cmd.description << std::endl;
    std::cout << "Category: " << cmd.category << std::endl;
    
    if (!cmd.valid_values.empty()) {
        std::cout << "Valid values: ";
        for (size_t i = 0; i < cmd.valid_values.size(); ++i) {
            std::cout << cmd.valid_values[i];
            if (i < cmd.valid_values.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    
    if (!cmd.value1_desc.empty()) {
        std::cout << "Value1: " << cmd.value1_desc << std::endl;
    }
    if (!cmd.value2_desc.empty()) {
        std::cout << "Value2: " << cmd.value2_desc << std::endl;
    }
    if (!cmd.value3_desc.empty()) {
        std::cout << "Value3: " << cmd.value3_desc << std::endl;
    }
    
    std::cout << "\nExamples:" << std::endl;
    std::cout << "  ifly_cli.exe set " << command_name << " " << (cmd.valid_values.empty() ? "<value>" : cmd.valid_values[0]) << std::endl;
    std::cout << "  ifly_cli.exe get " << command_name << std::endl;
}

bool iFlyCommander::parse_and_execute(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return false;
    }
    
    std::string command = to_lower(argv[1]);
    
    if (command == "help") {
        if (argc >= 3) {
            show_help(argv[2]);
        } else {
            show_help();
        }
        return true;
    }
    
    if (command == "list") {
        if (argc >= 3) {
            list_commands_by_category(argv[2]);
        } else {
            list_commands();
        }
        return true;
    }
    
    if (command == "connect") {
        if (connect_to_ifly()) {
            std::cout << "Successfully connected to iFly 737 MAX 8" << std::endl;
            std::cout << "Aircraft Model: " << g_pShareMem737MAXSDK->Aircraft_Model << std::endl;
        } else {
            std::cout << "Failed to connect to iFly 737 MAX 8. Is the simulator running?" << std::endl;
        }
        return true;
    }
    
    if (command == "set") {
        if (argc < 4) {
            std::cout << "Error: 'set' command requires a command name and value" << std::endl;
            std::cout << "Usage: ifly_cli.exe set <command> <value>" << std::endl;
            return false;
        }
        
        if (!connect_to_ifly()) {
            std::cout << "Error: Cannot connect to iFly 737 MAX 8. Is the simulator running?" << std::endl;
            return false;
        }
        
        return send_command(argv[2], argv[3]);
    }
    
    if (command == "get") {
        if (argc < 3) {
            std::cout << "Error: 'get' command requires a command name" << std::endl;
            std::cout << "Usage: ifly_cli.exe get <command>" << std::endl;
            return false;
        }
        
        if (!connect_to_ifly()) {
            std::cout << "Error: Cannot connect to iFly 737 MAX 8. Is the simulator running?" << std::endl;
            return false;
        }
        
        std::string value = get_command_value(argv[2]);
        std::cout << argv[2] << " = " << value << std::endl;
        return true;
    }
    
    std::cout << "Error: Unknown command '" << command << "'" << std::endl;
    print_usage();
    return false;
}

void iFlyCommander::initialize_command_map() {
    initialize_general_commands(&command_map);
    initialize_annunciators_commands(&command_map);
    initialize_lights_commands(&command_map);
    initialize_air_systems_commands(&command_map);
    initialize_anti_ice_commands(&command_map);
    initialize_apu_commands(&command_map);
    initialize_automatic_flight_commands(&command_map);
    initialize_communication_commands(&command_map);
    initialize_electrical_commands(&command_map);
    initialize_engapu_commands(&command_map);
    initialize_fire_commands(&command_map);
    initialize_fltctrl_commands(&command_map);
    initialize_fms_commands(&command_map);
    initialize_fuel_commands(&command_map);
    initialize_gear_commands(&command_map);
    initialize_hydraulic_commands(&command_map);
    initialize_instrument_commands(&command_map);
    initialize_warning_commands(&command_map);
}

void iFlyCommander::add_command(KEY_COMMAND_IFLY737MAX cmd_id, const std::string& name, 
                              const std::string& description, const std::string& category,
                              const std::vector<std::string>& valid_values,
                              const std::string& value1_desc, const std::string& value2_desc,
                              const std::string& value3_desc, const std::string& get_var) {
    CommandInfo cmd;
    cmd.command_id = cmd_id;
    cmd.name = name;
    cmd.description = description;
    cmd.category = category;
    cmd.valid_values = valid_values;
    cmd.value1_desc = value1_desc;
    cmd.value2_desc = value2_desc;
    cmd.value3_desc = value3_desc;
    cmd.get_variable_name = get_var;
    
    command_map[to_lower(name)] = cmd;
}

std::string iFlyCommander::to_lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::vector<std::string> iFlyCommander::split_string(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

int iFlyCommander::parse_value_to_int(const std::string& value, const std::vector<std::string>& valid_values) {
    std::string lower_value = to_lower(value);
    
    // Try to find the value in the valid values list
    for (size_t i = 0; i < valid_values.size(); ++i) {
        if (to_lower(valid_values[i]) == lower_value) {
            return static_cast<int>(i);
        }
    }
    
    // If not found, try to parse as integer
    try {
        int int_value = std::stoi(value);
        if (int_value >= 0 && int_value < static_cast<int>(valid_values.size())) {
            return int_value;
        }
    } catch (...) {
        // Not a valid integer
    }
    
    return -1; // Invalid value
}

void iFlyCommander::print_usage() {
    std::cout << "iFly 737 MAX 8 Command Line Interface" << std::endl;
    std::cout << "Usage: ifly_cli.exe [command] [options]" << std::endl;
    std::cout << "\nCommands:" << std::endl;
    std::cout << "  help             - Show this help message" << std::endl;
    std::cout << "  list             - List all available commands" << std::endl;
    std::cout << "  connect          - Test connection to iFly 737 MAX" << std::endl;
    std::cout << "  set <cmd> <val>  - Set a command to a specific value" << std::endl;
    std::cout << "  get <cmd>        - Get current value of a command" << std::endl;
    std::cout << "\nExamples:" << std::endl;
    std::cout << "  ifly_cli.exe list" << std::endl;
    std::cout << "  ifly_cli.exe set landing_light_1 on" << std::endl;
    std::cout << "  ifly_cli.exe get taxi_light" << std::endl;
    std::cout << "  ifly_cli.exe help landing_light_1" << std::endl;
}

// Ensure command_map is correctly defined
// std::map<std::string, CommandInfo> command_map; // REMOVE: now a member of iFlyCommander

// Main function


int main(int argc, char* argv[]) {
    iFlyCommander commander;
    if (!commander.initialize()) {
        std::cout << "Error: Failed to initialize iFly SDK" << std::endl;
        return 1;
    }

    // Only command-line mode: require arguments
    if (argc > 1) {
        commander.parse_and_execute(argc, argv);
        return 0;
    } else {
        std::cout << "No command provided. Usage:\n";
        commander.print_usage();
        return 1;
    }
}
