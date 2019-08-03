#include "fileprocess.h"
#include "symbolprocess.h"

int _courrent_line_number = 0;

bool _error_flag = false;

extern void print_symbol_list(); /* TODO delete when done developing */

bool is_empty(char line[]);

void process_file(char *filename)
{
	FILE *file;
    char line[MAX_LINE_INPUT];
    /* is valid file */
	if((file = fopen(filename, "r"))) {
		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)) {
			/* line counter */
			_courrent_line_number++;
			/* skips comment and empty lines */
			if(!is_empty(line)) {
				process_symbol(line);
			}
		}
		print_symbol_list();
		_courrent_line_number = 0;
		printf("\n error mode: %d\n", _error_flag);
	} else {
		printf("%s does not exist...\n", filename);
	}
}

bool is_empty(char line[])
{
	unsigned i = 0;
	bool isEmpty = true;

	while(line[i]) {
		/* checks if char is empty (whitespace, tab, new line...)*/
		if(!isspace(line[i])) {
			/* if first character is a comment sign */
			if(line[i] == COMMENT_SIGN) {
				return true;
			}
			isEmpty = false;
			break;
		}
		i++;
	}
	return isEmpty;
}

int get_file_line()
{
	return _courrent_line_number;
}

void set_error_mode()
{
	_error_flag = true;
}
