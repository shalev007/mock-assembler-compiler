#include <stdio.h>
#include <stdlib.h>

#define CELL_BIT_SIZE 14

typedef enum machineCode {
	A,
	R,
	E
} MachineCode;

typedef struct outputLine {
	int lineNumber;
	int *bits;
} OutputLine;


typedef struct outputLineItem * OutputLinePtr;

typedef struct outputLineItem {
	OutputLine line;
	OutputLinePtr next;
} OutputLineItem;

void push_line_to_list(OutputLine line);

void print_outputline_list();