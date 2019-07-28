#include "symbollist.h"


/**
 * print all the values in the list for the head node to EOF
 * if the list is empty print to the user
 */
void printSymbolList()
{
	symbolListPtr current = symbolListHead;

	if(symbolListHead == NULL) {
		printf("\n the list is empty\n");
		return;
	}
	printf("--------Symbols List-------\n");
	while(current != NULL) {
		printf("--------------------------\n");
		printf("name: %s\n",current->symbol.name);
		printf("type: %d\n",current->symbol.type);
		printf("value: %d\n",current->symbol.value);
		printf("isMakro: %d\n",current->symbol.isMakro);
		printf("isExternal: %d\n",current->symbol.isExternal);
		printf("--------------------------\n");
		current = current->next;
	}
}

void pushSymbolToList(Symbol symbol)
{
	symbolListPtr current = symbolListHead;
	/* if head is empty*/
	if(symbolListHead == NULL) {
		/* push item to head*/
		symbolListHead = (symbolListPtr) malloc(sizeof(ListItem));
		symbolListHead->symbol = symbol;
		symbolListHead->next = NULL;
	} else {
		/* go to last list item*/
		while(current->next != NULL) {
			current = current->next;
		}
		/* push symbol to last item */
		current->next = (symbolListPtr) malloc(sizeof(ListItem));
		current->next->symbol = symbol;
		current->next->next = NULL;
	}
}