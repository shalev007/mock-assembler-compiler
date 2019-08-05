#include "fileprocess.h"
#include "lineprocess.h"

int _courrent_line_number = 0;

bool _error_flag = false;

extern void print_symbol_list(); /* TODO delete when done developing */

extern int get_instructions_memory_amount();

extern int get_data_memory_amount();

extern void print_outputline_list();/* TODO delete when done developing */

bool is_empty(char line[]);

void process_file(char *filename)
{
	FILE *file;
    char line[MAX_LINE_INPUT];
    int ic_mem_cells, dc_mem_cells;
    /* is valid file */
	if((file = fopen(filename, "r"))) {
		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)) {
			/* line counter */
			_courrent_line_number++;
			/* skips comment and empty lines */
			if(!is_empty(line)) {
				first_loop_process(line);
			}
		}

		/* reset line counter */
		_courrent_line_number = 0;

		/* save memory cells */
		ic_mem_cells = get_instructions_memory_amount();
		dc_mem_cells = get_data_memory_amount();
		set_saved_memory_cells(ic_mem_cells, dc_mem_cells);

		/* update data symbols adresses after instructions */
		update_data_symbols_addresses();
		/* reset ic and dc counters */
		reset_counters();

		rewind(file);

		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)) {
			/* line counter */
			_courrent_line_number++;
			/* skips comment and empty lines */
			if(!is_empty(line)) {
				second_loop_process(line);
			}
		}
		print_outputline_list();
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
