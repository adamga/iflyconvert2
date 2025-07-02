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

// Forward declarations
class iFlyCommander;
struct CommandInfo;

// Global variables (avoid conflicts with SDK static variables)
ShareMemory737MAXSDK* g_pShareMem737MAXSDK = new ShareMemory737MAXSDK;
HANDLE g_hMapFile737MAXSDK = nullptr;
LPCTSTR g_pBuf737MAXSDK = nullptr;

// Command structure to hold information about each command
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

class iFlyCommander {
private:
    std::map<std::string, CommandInfo> command_map;
    bool is_connected = false;
    
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
    
private:
    void initialize_command_map();
    void add_command(KEY_COMMAND_IFLY737MAX cmd_id, const std::string& name, 
                    const std::string& description, const std::string& category,
                    const std::vector<std::string>& valid_values,
                    const std::string& value1_desc = "", const std::string& value2_desc = "",
                    const std::string& value3_desc = "", const std::string& get_var = "");
    
    std::string to_lower(const std::string& str);
    std::vector<std::string> split_string(const std::string& str, char delimiter);
    int parse_value_to_int(const std::string& value, const std::vector<std::string>& valid_values);
    void print_usage();
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
    g_hMapFile737MAXSDK = OpenFileMapping(FILE_MAP_READ, FALSE, szName737MAXSDK);
    
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
    // Initialize with the most commonly used commands
    // General/Lighting Commands
    add_command(KEY_COMMAND_GENERAL_LANDING_LIGHT_1_SET, "landing_light_1", 
                "Left Landing Light Switch", "lights", 
                {"off", "flash", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch FLASH; 2:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_LANDING_LIGHT_2_SET, "landing_light_2", 
                "Right Landing Light Switch", "lights", 
                {"off", "flash", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch FLASH; 2:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_TAXI_LIGHT_SET, "taxi_light", 
                "Taxi Light Switch", "lights", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_LOGO_LIGHT_SET, "logo_light", 
                "Logo Light Switch", "lights", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_ANTI_COLLISION_LIGHT_SET, "anti_collision_light", 
                "Anti-Collision Light Switch", "lights", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_WING_LIGHT_SET, "wing_light", 
                "Wing Illumination Switch", "lights", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_WHEEL_WELL_LIGHT_SET, "wheel_well_light", 
                "Wheel Well Light Switch", "lights", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_GENERAL_POSITION_LIGHT_SET, "position_light", 
                "Position Light Switch", "lights", 
                {"strobe_steady", "off", "steady"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch STROBE&STEADY; 1:switch OFF; 2:switch STEADY");
                
    add_command(KEY_COMMAND_GENERAL_DOME_LIGHT_SET, "dome_light", 
                "Dome Light Switch", "lights", 
                {"dim", "off", "bright"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch DIM; 1:switch OFF; 2:switch BRIGHT",
                "1: ignore the guard, press the button directly");
                
    // Air System Commands
    add_command(KEY_COMMAND_AIRSYSTEM_ENG_1_BLEED_SET, "engine_1_bleed", 
                "Engine 1 Bleed Air Switch", "air_systems", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_AIRSYSTEM_ENG_2_BLEED_SET, "engine_2_bleed", 
                "Engine 2 Bleed Air Switch", "air_systems", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_AIRSYSTEM_APU_BLEED_SET, "apu_bleed", 
                "APU Bleed Air Switch", "air_systems", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_AIRSYSTEM_PACK_1_SET, "pack_1", 
                "Left Air Conditioning Pack Switch", "air_systems", 
                {"off", "auto", "high"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch AUTO; 2:switch HIGH");
                
    add_command(KEY_COMMAND_AIRSYSTEM_PACK_2_SET, "pack_2", 
                "Right Air Conditioning Pack Switch", "air_systems", 
                {"off", "auto", "high"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch AUTO; 2:switch HIGH");
                
    // Anti-Ice Commands
    add_command(KEY_COMMAND_ANTIICE_WING_SET, "wing_anti_ice", 
                "Wing Anti-Ice Switch", "anti_ice", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_ANTIICE_ENG_1_SET, "engine_1_anti_ice", 
                "Engine 1 Anti-Ice Switch", "anti_ice", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
                
    add_command(KEY_COMMAND_ANTIICE_ENG_2_SET, "engine_2_anti_ice", 
                "Engine 2 Anti-Ice Switch", "anti_ice", 
                {"off", "on"}, 
                "0: OFF the click sound; 1: ON the click sound",
                "0:switch OFF; 1:switch ON");
    
    // Add more commands as needed - this is a good starting set
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

// Main function
int main(int argc, char* argv[]) {
    iFlyCommander commander;
    
    if (!commander.initialize()) {
        std::cout << "Error: Failed to initialize iFly SDK" << std::endl;
        return 1;
    }
    
    if (!commander.parse_and_execute(argc, argv)) {
        return 1;
    }
    
    return 0;
}
