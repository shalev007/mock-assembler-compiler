#include "symbolprocess.h"
#include "symbollist.h"
#include "symbol.h"

char ** convert_line_to_words_array(char *line);

bool is_external(char word[]);

bool is_entry(char word[]);

bool is_macro(char word[]);

bool is_symbol_assign(char ** words);

void handle_external_symbol(char ** words);

void handle_macro_symbol(char ** words);

void handle_symbol_assign(char ** words);

void process_symbol(char *line)
{
	char ** words = convert_line_to_words_array(line);
	if(is_entry(words[0])) {/* ignore entry type symbols */
		return;

	}else if(is_external(words[0])) {/* handle external symbols */
		handle_external_symbol(words);
		return;

	}else if(is_macro(words[0])) {/* handle macro symbols */
		handle_macro_symbol(words);
		return;

	}else if(is_symbol_assign(words)) {
		handle_symbol_assign(words);
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

/**
 * checks weather sign is the .define key word
 */
bool is_macro(char word[])
{
	if(strcmp(MACRO_SIGN, word) == 0) {
		return true;
	}

	return false;
}

/**
 * checks weather sign a regular symbol assign
 */
bool is_symbol_assign(char ** words)
{
	int i = 0;
	char * word;
	unsigned wordLength;

	while(words[i]) {
		word = words[i];
		wordLength = strlen(words[i]);
		/* checks if the line is variable assign command */
		if(word[wordLength-1] == SYMBOL_ASSIGN_SIGN) {
			return true;
		}
		i++;
	}
	return false;
}

/**
 * adds symbol to list
 */
void handle_external_symbol(char ** words)
{
	Symbol symbol;

	/* create symbol */
	symbol.name = words[1];
	symbol.type = EMPTY;
	symbol.value = EXTERNAL_ADDRESS_VALUE;
	symbol.isMacro = false;
	symbol.isExternal = true;

	/* add to symbols list */
	add_symbol_to_list(symbol);
}

/**
 * adds symbol to list
 */
void handle_macro_symbol(char ** words)
{
	int i = 0;
	Symbol symbol;
	int macroValue;

	/* prepare macro valus */
	while(words[i]) {
		/* get value after "=" sign */
		if(strcmp(words[i], "=") == 0) {
			macroValue = atoi(words[i+1]);
			break;
		}
		i++;
	}

	/* prepare symbol */
	symbol.name = words[1];
	symbol.type = EMPTY;
	symbol.value = macroValue;
	symbol.isMacro = true;
	symbol.isExternal = false;

	/* add to symbols list */
	add_symbol_to_list(symbol);
}

void handle_symbol_assign(char ** words)
{
	printf("%s\n", get_symbol_name(words));
}