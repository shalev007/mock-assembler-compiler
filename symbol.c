#include "instructionsregister.h"
#include "symbollist.h"
#include "symbol.h"

bool is_valid_symbol_data_type(char * type);

bool is_valid_symbol_command_type(char * command);

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
			if(!is_valid_symbol_data_type(words[i])) {
				printf("unknown data type %s\n", words[i]);
				exit(0);
			}
			type = DATA;
			break;
		}
		i++;
	}

	if(type != DATA) {
		if(!is_valid_symbol_command_type(words[1])) {/* validate COMMAND type */
			printf("unknown command %s\n", words[1]);
			exit(0);
		}
	}
	return type;
}

bool is_valid_symbol_data_type(char * type)
{
	if((strcmp(type, DATA_TYPE_DATA) == 0) || (strcmp(type, DATA_TYPE_STRING) == 0)) {
		return true;
	}

	return false;
}

bool is_valid_symbol_command_type(char * command)
{
	get_command_id(command);
	return false;
}