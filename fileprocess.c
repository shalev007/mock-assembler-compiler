#include "fileprocess.h"
#include "symbolprocess.h"


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
				process_symbol(line);
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