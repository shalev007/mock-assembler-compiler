#include "fileprocess.h"
#include "symbollist.h"


void process_file(char *filename)
{
	FILE *file;
    char line[MAX_LINE_INPUT];
    Symbol symbol;

    /* is valid file */
	if((file = fopen(filename, "r"))) {
		/* initiate symbols list */

		/*TODO: remove this code*/
		/*
		symbol.name = "shalev";
		symbol.type = DATA;
		symbol.value = 123123;
		symbol.isMakro = false;
		symbol.isExternal = false;

		pushSymbolToList(symbol);
		pushSymbolToList(symbol);
		pushSymbolToList(symbol);
		printSymbolList();

		*/
		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)){
			/* skips comment lines */
			if(!is_comment(line)) {
				/*symbol process*/
			}
		}
	} else {
		printf("%s does not exist...\n", filename);
	}
}

bool is_comment(char line[])
{
	if(((char) line[0]) == COMMENT_SIGN) {
		return true;
	}

	return false;
}