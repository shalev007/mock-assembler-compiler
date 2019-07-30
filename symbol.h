#include <string.h>
#include <stdlib.h>
#define SYMBOL_ASSIGN_SIGN ':'

char * get_symbol_name(char ** words);
unsigned int get_symbol_type(char ** words);
unsigned int calculate_symbol_memory_size(char ** words);