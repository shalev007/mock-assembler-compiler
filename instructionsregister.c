#include "instructionsregister.h"

int _IC = IC_DEFAULT_VALUE;

/* 0,1,2,3 */
AddressingMode allAddressModes[] = {IMMEDIATE, DIRECT, INDEXED, REGISTER};
/* 1,2,3 */
AddressingMode noImmediateAddressModes[] = {DIRECT, INDEXED, REGISTER};
/* 1,2 */
AddressingMode drctAndIndxAddressModes[] = {DIRECT, INDEXED};
/* 1,3 */
AddressingMode drctAndRegsAddressModes[] = {DIRECT, REGISTER};

/**
* Collection of all the commands,
* with their allowed addressing modes
* for source operand and destination operand
* as mentioned in assigment notebook.
*/
Command command_list[16] = {
	{
		0,
		"mov",
		allAddressModes,
		noImmediateAddressModes
	},
	{
		1,
		"cmp",
		allAddressModes,
		allAddressModes
	},
	{
		2,
		"add",
		allAddressModes,
		noImmediateAddressModes
	},
	{
		3,
		"sub",
		allAddressModes,
		noImmediateAddressModes
	},
	{
		4,
		"not",
		NULL,
		noImmediateAddressModes
	},
	{
		5,
		"clr",
		NULL,
		noImmediateAddressModes
	},
	{
		6,
		"lea",
		drctAndIndxAddressModes,
		noImmediateAddressModes
	},
	{
		7,
		"inc",
		NULL,
		noImmediateAddressModes
	},
	{
		8,
		"dec",
		NULL,
		noImmediateAddressModes
	},
	{
		9,
		"jmp",
		NULL,
		drctAndRegsAddressModes
	},
	{
		10,
		"bne",
		NULL,
		drctAndRegsAddressModes
	},
	{
		11,
		"red",
		NULL,
		noImmediateAddressModes
	},
	{
		12,
		"prn",
		NULL,
		allAddressModes
	},
	{
		13,
		"jsr",
		NULL,
		drctAndRegsAddressModes
	},
	{
		14,
		"rts",
		NULL,
		NULL
	},
	{
		15,
		"stop",
		NULL,
		NULL
	}
};

bool validate_command(char ** commandline);

bool validate_command_addressing_mode(char * name, char * dest, char * src);

signed int get_command_id(char * command)
{
	int count = 16;

	while(count--) {
		if(strcmp(command_list[count].name, command) == 0) {
			return command_list[count].id;
		}
	}
	return -1;
}

bool is_command(char * command)
{
	if (get_command_id(command) > -1) {
		return true;
	}

	return false;
}

int calculate_command_space(char ** commandline)
{
	int i = 0;
	int numOfOperands = 0;
	char * commandName;
	char * dest = NULL;
	char * src = NULL;

	/* validate that command exists */
	if(!validate_command(commandline)) {
		return 0;
	}

	commandName = commandline[0];

	/* calculate number of operands */
	while(commandline[i]) {
		if(strcmp(commandline[i], commandName) != 0) {
			numOfOperands++;
		}
		i++;
	}

	/* assign destination and source operands */
	if(numOfOperands == 1) {
		dest = commandline[1];

	} else if(numOfOperands == 2) {
		dest = commandline[2];
		/* create the src without the ',' sign*/
		src = (char *) malloc(sizeof(commandline[1]) * sizeof(char));
        strncat(src, commandline[1], sizeof(commandline[1])-1);
	}

	/* validate that command can use these addressing modes */
	if (!validate_command_addressing_mode(commandName, dest, src)) {
		return 0;
	}

	return 0;
}

bool validate_command(char ** commandline)
{
	if(!is_command(commandline[0])) {
		printf("%s is not a valid command...\n", commandline[0]); /*TODO: continue and add error flag to true and file read line number*/
		return false;
	}

	return true;
}

bool validate_command_addressing_mode(char * name, char * dest, char * src)
{
	return true;
}