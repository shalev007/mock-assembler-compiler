#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_INPUT 81
#define COMMENT_SIGN ';'

bool is_comment(char line []);
void process_file(char *filename);