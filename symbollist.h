/**
* structure of a link list that contain a struct of a symbol with parameters
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>

/* type of symbol */
enum symbolType {EMPTY, DATA, STRING};


/* the stract and the parameters of a symbol */
typedef struct {
	char *name;
	enum symbolType type;
	int value;
	bool isMakro;
	bool isExternal;
}  Symbol;

/* struct of pointer for the node next parameter ד*/
typedef struct node * symbolListPtr;

/* node decleration */
typedef struct node {
	Symbol symbol;
	symbolListPtr next;
}  ListItem;

/* list head */
symbolListPtr symbolListHead;

/* print symbol list */
void printSymbolList();

/* push symbol to list */
void pushSymbolToList(Symbol);
/* remove node from symbol to list */
void removeFromSymbolList(char *nameToRemove);