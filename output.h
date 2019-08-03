#include <stdio.h>
#include <stdlib.h>

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