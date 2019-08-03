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

extern int get_file_line();

extern void set_error_mode();

bool validate_command(char ** commandline);

bool validate_command_addressing_mode(char * name, AddressingMode dest, AddressingMode src);

AddressingMode addressing_mode_type(char * operand);

bool is_registor_name(char * operand);

bool is_valid_registor(char * operand);

Command get_command_by_name(char * name);

bool is_empty_command_operand_dest(Command command);

bool is_empty_command_operand_src(Command command);

bool is_empty_operands_command(Command command);

bool is_empty_addressing_mode(AddressingMode addressing_mode);

bool is_addressing_mode_allowed_by_command(AddressingMode addressing_mode, AddressingMode * command_allowed);

int calculate_space_by_addressing_modes(AddressingMode dest, AddressingMode src);

int calculate_space_by_addressing_mode(AddressingMode);

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

Command get_command_by_name(char * name)
{
	int id = get_command_id(name);
	return command_list[id];
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
	int space = 0;

	char * commandName;
	char * dest = NULL;
	char * src = NULL;

	AddressingMode destAddressMode;
	AddressingMode srcAddressMode;

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
		src = commandline[1];
	}

	destAddressMode = addressing_mode_type(dest);
	srcAddressMode = addressing_mode_type(src);

	/* validate that command can use these addressing modes */
	if (!validate_command_addressing_mode(commandName, destAddressMode, srcAddressMode)) {
		return 0;
	}

	space = calculate_space_by_addressing_modes(destAddressMode, srcAddressMode);

	/* free allocated space */
	commandName = NULL;
	dest = NULL;
	src = NULL;
	free(commandName);
	free(dest);
	free(src);

	return space;
}

bool validate_command(char ** commandline)
{
	if(!is_command(commandline[0])) {
		printf("%s is not a valid command on line %d\n", commandline[0], get_file_line());
		set_error_mode();
		return false;
	}

	return true;
}

bool validate_command_addressing_mode(char * name, AddressingMode dest, AddressingMode src)
{
	Command command;
	command = get_command_by_name(name);
	
	/* if a command cannot recive any operands */
	if (is_empty_operands_command(command)) {
		if (is_empty_addressing_mode(dest) && is_empty_addressing_mode(src)) {
			return true;
		} else {
			printf("command %s cannot recive any arguments on line %d\n", command.name, get_file_line());
			set_error_mode();
			return false;
		}
	}

	if (!is_empty_command_operand_src(command)) {
		if (is_empty_addressing_mode(src)) {
			printf("command %s must recive source argument on line %d\n", command.name, get_file_line());
			set_error_mode();
			return false;
		}else if (!is_addressing_mode_allowed_by_command(src, command.allowedAddressingsSrc)) {
			printf("source argument is not alowed by command %s on line %d\n", command.name, get_file_line());
			set_error_mode();
			return false;
		}
	}

	if (!is_empty_command_operand_dest(command)) {
		if (is_empty_addressing_mode(dest)) {
			printf("command %s must recive destination argument on line %d\n", command.name, get_file_line());
			set_error_mode();
			return false;
		}else if (!is_addressing_mode_allowed_by_command(dest, command.allowedAddressingsDest)) {
			printf("destination argument is not alowed by command %s on line %d\n", command.name, get_file_line());
			set_error_mode();
			return false;
		}
	}

	return true;
}

AddressingMode addressing_mode_type(char * operand)
{
	int i = 0;
	bool isArray = false;

	if(operand == NULL) { /* Not Address Mode */
		return NAM;
	} else if (operand[0] == IMMEDIATE_SYMBOL) { /* IMMEDIATE */
		return IMMEDIATE;
	} else if(is_registor_name(operand)) { /* REGISTER */
		/* validate registor name */
		if (!is_valid_registor(operand)) {
			printf("%c is not a valid registor on line %d\n", operand[1], get_file_line());
			set_error_mode();
			return NAM;
		}
		return REGISTER;
	}

	/* INDEXED */
	while(operand[i]) {
		if (operand[i] == '[') {
			isArray = true;
		} else if ((operand[i] == ']') && isArray) {
			return INDEXED;
		}
		i++;
	}

	/* must be DIRECT */
	return DIRECT;
}

bool is_registor_name(char * operand)
{
	if ((strlen(operand) == 2) && (operand[0] == 'r') && (isdigit((int) operand[1]))) {
		return true;
	}

	return false;
}

bool is_valid_registor(char * operand)
{
	/* convert char to int */
	int registorNumber = operand[1] - '0';

	if (registorNumber > MAX_REGISTERS) {
			return false;
	}

	return true;
}

bool is_empty_command_operand_dest(Command command)
{
	if (command.allowedAddressingsDest == NULL) {
		return true;
	}

	return false;
}

bool is_empty_command_operand_src(Command command)
{
	if (command.allowedAddressingsSrc == NULL) {
		return true;
	}

	return false;
}

bool is_empty_operands_command(Command command)
{
	if (is_empty_command_operand_dest(command) && is_empty_command_operand_src(command)) {
		return true;
	}

	return false;
}

bool is_empty_addressing_mode(AddressingMode addressing_mode)
{
	if (addressing_mode == NAM) {
		return true;
	}

	return false;
}

bool is_addressing_mode_allowed_by_command(AddressingMode addressing_mode, AddressingMode * command_allowed)
{
	int i = 0;
	while(command_allowed[i]) {
		if (command_allowed[i] == addressing_mode) {
			return true;
		}
		i++;
	}
	return true;
}

int calculate_space_by_addressing_modes(AddressingMode dest, AddressingMode src)
{
	int space = 1;
	
	if (is_empty_addressing_mode(dest)) { /* only command */
		return space;
	} else if (dest == REGISTER && src == REGISTER) { /* register type operands share the same memory cell */
		space += 1;
		return space;
	}

	space += calculate_space_by_addressing_mode(dest) + calculate_space_by_addressing_mode(src);
	return space;
}

int calculate_space_by_addressing_mode(AddressingMode addressing_mode)
{
	if (is_empty_addressing_mode(addressing_mode)) {
		return 0;
	} else if (addressing_mode == INDEXED) {
		return 2;
	}

	return 1;
}

int get_instructions_counter(int size)
{
	/* increment counter */
	_IC += size;

	/* return last value */
	return _IC - size;
}

int get_instructions_memory_amount()
{
	return _IC - IC_DEFAULT_VALUE;
}