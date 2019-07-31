#include "symbollist.h"
#include "symbol.h"

bool is_valid_symbol_type(char * type);

/**
 * returns symbol name/label
 */
char * get_symbol_name(char ** words)
{
	int i = 0;
	char * word;
	char * name;
	unsigned wordLength;

	while(words[i]) {
		word = words[i];
		wordLength = strlen(words[i]);
		if(word[wordLength-1] == SYMBOL_ASSIGN_SIGN) {
			name = (char *) malloc(wordLength * sizeof(char));
			strncat(name, word, wordLength-1);
			break;
		}
		i++;
	}

	return name;
}

unsigned int get_symbol_type(char ** words)
{
	int i = 0;
	SymbolType type;

	while(words[i]) {
		/* word starts with DATA initializer */
		if (words[i][0] == '.') {
			/* validate approved type */
			if(!is_valid_symbol_type(words[i])) {
				printf("unknown data type %s\n", words[i]);
				exit(0);
			}
			type = DATA;
		} else if (words[i]) { /* TODO: check and validate COMMAND type */
		}
		i++;
	}

	return type;
}

bool is_valid_symbol_type(char * type)
{
	if((strcmp(type, DATA_TYPE_DATA) == 0) || (strcmp(type, DATA_TYPE_STRING) == 0)) {
		return true;
	}

	return false;
}