#include "symbolprocess.h"
#include "symbollist.h"

char ** convert_line_to_words_array(char *line);

bool is_external(char word[]);

bool is_entry(char word[]);

void handle_external_symbol(char ** words);

void process_symbol(char *line)
{
	char ** words = convert_line_to_words_array(line);

	/* ignore entry type symbols */
	if(is_entry(words[0])) {
		return;
	}

	/* handle external symbols */
	if(is_external(words[0])) {
		handle_external_symbol(words);
	}
	return;
}

/**
 * converts a string to an array of words without the whitespaces
 */
char ** convert_line_to_words_array(char *line)
{
	char * nextWord;
	char ** wordArray;
	int i = 0;
	char *lineClone;
	wordArray = NULL;
	/* allocate space same as line */
	lineClone = (char *) malloc((strlen(line)+1)* sizeof(char));
	/* clone line */
	strcpy(lineClone, line);
	/*grabs the next word from the string (without whitespaces)*/
	nextWord = strtok(lineClone, WORD_SPLIT_TOKENS);

	while (nextWord != NULL)
	{
		/*reallocating space from the next word in the array*/
		wordArray = (char **) realloc(wordArray, (i + 1) * sizeof(char *));
		/* allocate space for the incoming word*/
		wordArray[i] = (char *) malloc(sizeof(nextWord) * sizeof(char));
		/* actually setting the word */
		wordArray[i] = nextWord;
		/* grabing the next word from the string */
		nextWord = strtok (NULL, WORD_SPLIT_TOKENS);
		i++;
	}

	/* add NULL to last index to indicate the end of the array */
	wordArray = (char **) realloc(wordArray, i * sizeof(char *));
	wordArray[i] = (char *) malloc(sizeof(nextWord) * sizeof(char));
	wordArray[i] = NULL;

	/* free alloctated spaces */
	free(lineClone);
	free(nextWord);
	
	return wordArray;
}

/**
 * checks weather sign is the .external key word
 */
bool is_external(char word[])
{
	if(strcmp(EXTERNAL_SIGN, word) == 0) {
		return true;
	}

	return false;
}

/**
 * checks weather sign is the .entry key word
 */
bool is_entry(char word[])
{
	if(strcmp(ENTRY_SIGN, word) == 0) {
		return true;
	}

	return false;
}

void handle_external_symbol(char ** words)
{
	Symbol symbol;

	/* create symbol */
	symbol.name = words[1];
	symbol.type = EMPTY;
	symbol.value = EXTERNAL_ADDRESS_VALUE;
	symbol.isMakro = false;
	symbol.isExternal = true;

	/* add to symbols list */
	addSymbol(symbol);
}