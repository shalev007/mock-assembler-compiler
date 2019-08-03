#include "dataregister.h"

int _DC = DEFAULT_VALUE;

extern int get_file_line();

extern void set_error_mode();

DataType get_data_type(char ** data);

bool validate_data(char ** data, DataType type);

bool validate_data_type(char **data);

bool validate_string_type(char **data);

int calculate_data_type(char ** data);

int calculate_string_type(char ** data);

int calculate_data_space(char ** data)
{
	int size = 0;
	DataType type = get_data_type(data);

	if (!validate_data(data, type)) {
		return 0;
	}

	if (type == DATA_TYPE) {
		size = calculate_data_type(data);
	} else if (type == STRING_TYPE) {
		size = calculate_string_type(data);
	}
	return size;
}

bool validate_data(char ** data, DataType type)
{
	/* if type data */
	if (type == DATA_TYPE) {
		return validate_data_type(data);

	} else if (type == STRING_TYPE) { /* if is string */
		return validate_string_type(data);

	}

	printf("undefined data type %s in line %d\n", data[0], get_file_line());
	set_error_mode();
	return false;
}

bool validate_data_type(char **data)
{
	/* TODO validate data*/
	return true;
}

bool validate_string_type(char **data)
{
	/* TODO validate string*/
	return true;
}

DataType get_data_type(char ** data)
{
	if (strcmp(data[0], DATA_TYPE_SYMBOL) == 0) {
		return DATA_TYPE;
	} else if (strcmp(data[0], STRING_TYPE_SYMBOL) == 0) {
		return STRING_TYPE;
	}

	return NDT;
}

int calculate_data_type(char ** data)
{
	int i = 1;

	while(data[i]) {
		i++;
	}

	return i-1;
}

int calculate_string_type(char ** data)
{
	int i = 0;
	int counter = 0;

	while(data[1][i]) {
		if (isalpha(data[1][i])) {
			counter++;
		}
		i++;
	}

	return counter;
}