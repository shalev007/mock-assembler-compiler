#include "output.h"

OutputLinePtr outputLineHead = NULL;

ExternalItemList * external_list = NULL;

void push_line_to_list(OutputLine line)
{
	OutputLinePtr current = outputLineHead;
	/* if head is empty*/
	if(outputLineHead == NULL) {
		/* push item to head*/
		outputLineHead = (OutputLinePtr) malloc(sizeof(OutputLineItem));
		outputLineHead->line = line;
		outputLineHead->next = NULL;
	} else {
		/* go to last list item*/
		while(current->next != NULL) {
			current = (OutputLinePtr) current->next;
		}
		/* push line to last item */
		current->next = (OutputLinePtr) malloc(sizeof(OutputLineItem));
		current->next->line = line;
		current->next->next = NULL;
	}
}

void print_outputline_list()
{
	OutputLinePtr current = outputLineHead;

	if(outputLineHead == NULL) {
		printf("\n the list is empty\n");
		return;
	}
	printf("--------Outputline List-------\n");
	while(current != NULL) {
		printf("--------------------------\n");
		printf("line number: %d\n",current->line.lineNumber);
		printf("data: %s\n", current->line.bits);
		printf("--------------------------\n");
		current = current->next;
	}
}

 /*function that take a nuber and make it a bit with the given size */
char * decimal_to_bin(int n,int s)
{
	int c, d, count;
	char *pointer;

	count = 0;
	pointer = (char*)malloc(s+1);

	for (c = s-1; c >= 0; c--) {
		d = n >> c;
		if (d & 1) {
			*(pointer+count) = 1 + '0';
		} else {
			*(pointer+count) = 0 + '0';
		}
		count++;
	}
	*(pointer+count) = '\0';
	return pointer;
}

void reset_output_list()
{
	/* TODO: clean output list */
	outputLineHead = NULL;
}

void add_to_external_list(char * name, int line)
{
	ExternalItem external_item;
	ExternalItemList * current = external_list;
	external_item.line = line;
	external_item.symbol = name;

	if(external_list == NULL) {
		external_list = (ExternalItemList *) malloc(sizeof(ExternalItemList));
		external_list->external = external_item;
		external_list->next = NULL;
	} else {
		while(current->next) {
			current = current->next;
		}
		current->next = (ExternalItemList *) malloc(sizeof(ExternalItemList));
		current->next->external = external_item;
		current->next->next = NULL;
	}

	return;
}

void reset_external_list()
{
	ExternalItemList * current = external_list;
	while(current) {
		current->external.symbol = NULL;
		free(current->external.symbol);
		free(current);
		current = current->next;
	}
	external_list = NULL;
}