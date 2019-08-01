#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT_VALUE 100

int _IC;

signed int get_command_id(char * command);

bool is_command(char * command);