#include <stdbool.h>
#include <string.h>

#define WORD_SPLIT_TOKENS " ,\n\t"
#define EXTERNAL_SIGN ".extern"
#define ENTRY_SIGN ".entry"
#define MACRO_SIGN ".define"
#define EXTERNAL_ADDRESS_VALUE 0


void process_symbol(char *line);