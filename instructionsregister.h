#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define IC_DEFAULT_VALUE 100

signed int get_command_id(char * command);

bool is_command(char * command);

int calculate_command_space(char ** commandline);