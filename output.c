#include "output.h"

OutputLinePtr outputLineHead = NULL;

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
	int i;
	OutputLinePtr current = outputLineHead;

	if(outputLineHead == NULL) {
		printf("\n the list is empty\n");
		return;
	}
	printf("--------Outputline List-------\n");
	while(current != NULL) {
		i = 0;
		printf("--------------------------\n");
		printf("line number: %d\n",current->line.lineNumber);
		printf("data: ");
		while(i < 14) {
			printf("%d",current->line.bits[i]);
			i++;
		}
		printf("\n");
		printf("--------------------------\n");
		current = current->next;
	}
}