
#include "iflycli_dll.h"
#include "../ifly_cli/main.cpp" // Pulls in iFlyCommander and all command logic

#include <string>
#include <vector>
#include <map>
#include <cstring>

// Reuse your iFlyCommander class from the CLI
static iFlyCommander g_commander;

// Set a command value
extern "C" IFLYCLI_API int ifly_set_command(const char* command, const char* value) {
    if (!g_commander.initialize()) return 1;
    return g_commander.send_command(command, value) ? 0 : 2;
}

// Get a command value
extern "C" IFLYCLI_API int ifly_get_command(const char* command, char* out_value, int out_value_len) {
    if (!g_commander.initialize()) return 1;
    std::string val = g_commander.get_command_value(command);
    if (val.size() + 1 > (size_t)out_value_len) return 3;
    std::strncpy(out_value, val.c_str(), out_value_len);
    out_value[out_value_len-1] = 0;
    return 0;
}

// List all commands
extern "C" IFLYCLI_API int ifly_list_commands(char* out_buf, int buf_len) {
    if (!g_commander.initialize()) return 1;
    std::string all;
    for (const auto& name : g_commander.get_all_command_names()) {
        all += name + "\n";
    }
    if (all.size() + 1 > (size_t)buf_len) return 3;
    std::strncpy(out_buf, all.c_str(), buf_len);
    out_buf[buf_len-1] = 0;
    return 0;
}
