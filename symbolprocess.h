#include <stdbool.h>
#include <string.h>

#define WORD_SPLIT_TOKENS " \n"
#define EXTERNAL_SIGN ".extern"
#define ENTRY_SIGN ".entry"


void process_symbol(char *line);