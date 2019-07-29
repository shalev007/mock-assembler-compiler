#include "symbolprocess.h"
#include "symbollist.h"

char ** convertLineToWordsArray(char *line);

void process_symbol(char *line)
{
	int i;
	char ** words = convertLineToWordsArray(line);

	/* loop through each word in the line*/
	while(words[i]) {
		printf("words[%d]: %s\n", i, words[i]);
		i++;
	}
	printf("%s\n", line);
	return;
}

/**
 * converts a string to an array of words without the whitespaces
 */
char ** convertLineToWordsArray(char *line)
{
	char * nextWord;
	char ** wordArray;
	int i;
	wordArray = NULL;
	nextWord = strtok(line, WORD_SPLIT_TOKENS);

	while (nextWord != NULL)
	{
		wordArray = (char **) realloc(wordArray, (i + 1) * sizeof(char *));
		wordArray[i] = (char *) malloc(sizeof(nextWord) * sizeof(char));
		wordArray[i] = nextWord;
		nextWord = strtok (NULL, WORD_SPLIT_TOKENS);
		i++;
	}

	/* add NULL to last index to indicate the end of the array */
	wordArray = (char **) realloc(wordArray, (i + 1) * sizeof(char *));
	wordArray[++i] = (char *) malloc(sizeof(nextWord) * sizeof(char));
	wordArray[i] = NULL;

	return wordArray;
}