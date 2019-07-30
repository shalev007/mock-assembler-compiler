#include "symbol.h"
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