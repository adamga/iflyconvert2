#pragma once
#ifdef _WIN32
#define IFLYCLI_API __declspec(dllexport)
#else
#define IFLYCLI_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Set a command value (returns 0 on success, nonzero on error)
IFLYCLI_API int ifly_set_command(const char* command, const char* value);

// Get a command value (returns 0 on success, nonzero on error)
// out_value must be a buffer of at least out_value_len bytes
IFLYCLI_API int ifly_get_command(const char* command, char* out_value, int out_value_len);

// List all commands (writes a newline-separated list to out_buf)
IFLYCLI_API int ifly_list_commands(char* out_buf, int buf_len);

#ifdef __cplusplus
}
#endif
