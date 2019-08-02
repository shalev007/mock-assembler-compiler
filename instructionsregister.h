#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define IC_DEFAULT_VALUE 100

/* type of addressing mode */
typedef enum addressingMode {
	IMMEDIATE,
	DIRECT,
	INDEXED,
	REGISTER
} AddressingMode;

/* command struct */
typedef struct {
	unsigned id;
	char * name;
	AddressingMode * allowedAddressingsSrc;
	AddressingMode * allowedAddressingsDest;
}  Command;

signed int get_command_id(char * command);

bool is_command(char * command);

int calculate_command_space(char ** commandline);