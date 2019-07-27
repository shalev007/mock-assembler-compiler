#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 
#define MAX_LINE_INPUT 81
#define COMMENT_SIGN ';'

bool is_comment(char line []);

void process_file(char *filename)
{
	FILE *file;
    char line[MAX_LINE_INPUT];

    /* is valid file */
	if((file = fopen(filename, "r"))) {
		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)){
			/* skips comment lines */
			if(!is_comment(line)) {
				/*symbol process*/
			}
		}
	} else {
		printf("%s does not exist...\n", filename);
	}
}

bool is_comment(char line[])
{
	if(((char) line[0]) == COMMENT_SIGN) {
		return true;
	}

	return false;
}