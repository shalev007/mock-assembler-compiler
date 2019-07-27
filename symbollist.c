/*structure of a link list that contain a struct of a symbol with parameters 
*/
/*declerations*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>
void printList(symbolListPtr);


/*declerations*/

/*type of symbol*/
enum symbolType {EMPTY,DATA,STRING};

/*the stract and the parameters of a symbol*/

typedef struct {
	char *name;
	enum symbolType type;
	int value;
	bool isMakro;
	bool isExternal;
}  Symbol;

/*struct of pointer for the node next parameter*/
typedef struct node * symbolListPtr;

/*node decleration*/
typedef struct node{
	Symbol symbol;
	symbolListPtr next;
}  ListItem;

/*making the head of the list equal to NULL */
symbolListPtr symbolListHead=NULL;


/*print all the values in the list for the head node to EOF 
if the list is empty print to the user */

void printList(symbolListPtr head){
	symbolListPtr current=head;
	if(head==NULL){
		printf("\n the list is empty");
		return;
	}
	while(current!=NULL){
		printf("%s\n",current->symbol.name );
		printf("%d\n",current->symbol.type  );
		printf("%d\n",current->symbol.value  );
		printf("%d\n",current->symbol.isMakro  );
		printf("%d\n",current->symbol.isExternal  );
		current=current->next;
	}
}