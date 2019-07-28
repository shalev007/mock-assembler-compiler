#include "symbollist.h"


/**
 * print all the values in the list for the head node to EOF
 * if the list is empty print to the user
 */
void printList(symbolListPtr head)
{
	symbolListPtr current=head;

	if(head == NULL) {
		printf("\n the list is empty");
		return;
	}

	while(current != NULL) {
		printf("%s\n",current->symbol.name);
		printf("%d\n",current->symbol.type);
		printf("%d\n",current->symbol.value);
		printf("%d\n",current->symbol.isMakro);
		printf("%d\n",current->symbol.isExternal);
		current = current->next;
	}
}