#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#define MAX_LINE_INPUT 81

void process_file(char *filename)
{
	FILE *file;
    char line[MAX_LINE_INPUT];

    /* is valid file */
	if((file = fopen(filename, "r"))) {
		/* read each line */
		while(fgets(line, MAX_LINE_INPUT, file)){
			puts(line);
		}
	} else {
		printf("%s does not exist...\n", filename);
	}
}