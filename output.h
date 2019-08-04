#include <stdio.h>
#include <stdlib.h>

#define CELL_BIT_SIZE 14

typedef enum machineCode {
	A,
	E,
	R
} MachineCode;

typedef struct outputLine {
	int lineNumber;
	char *bits;
} OutputLine;


typedef struct outputLineItem * OutputLinePtr;

typedef struct outputLineItem {
	OutputLine line;
	OutputLinePtr next;
} OutputLineItem;

void push_line_to_list(OutputLine line);

void print_outputline_list();

char * decimal_to_bin(int n,int s);