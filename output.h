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

/* output line for *.o files */
typedef struct outputLineItem {
	OutputLine line;
	OutputLinePtr next;
} OutputLineItem;

/* external symbol for linker to complete */
typedef struct {
	int line;
	char * symbol;
} ExternalItem;

typedef struct external_item_list {
	ExternalItem external;
	struct external_item_list * next;
} ExternalItemList;

void push_line_to_list(OutputLine line);

void print_outputline_list();

char * decimal_to_bin(int n,int s);

void reset_output_list();

void add_to_external_list(char * name, int line);

void reset_external_list();