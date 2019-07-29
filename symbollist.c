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

/* remove ONE item from list with the name value the same to the given name */
void removeFromSymbolList(char *nameToRemove)
{
	/* two pointer one is helper that get the priveus node and one that run on the list */
	symbolListPtr current = symbolListHead;
	symbolListPtr helper=symbolListHead-1;
	/*if the list is empty the function return with a messege that the list is empty */
	if(symbolListHead == NULL){
		printf("\n the list is empty\n");
		return;
	}

	/*
	* run on the list with str cmp if value equal to zero
	* (mean that the name is equal to the given) the curret node next replaced with the next
	* of the helper and get freed then the function break.
	 */
	while(current->next != NULL) {
		if (strcmp(current->symbol.name, nameToRemove) == 0)
		{
			helper->next=current->next;
			free(current);
			break;
		}
		current = current->next;
		helper = helper->next;

	}
}

bool isInSymbolsList(Symbol symbol)
{
	symbolListPtr current = symbolListHead;
	if(current != NULL) {
		while(current != NULL) {
			if (strcmp(current->symbol.name, symbol.name) == 0) {
				return true;
			}
			current = current->next;
		}
	}

	return false;
}

void addSymbol(Symbol symbol)
{
	if(!isInSymbolsList(symbol)) {
		pushSymbolToList(symbol);
	}
}