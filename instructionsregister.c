#include "instructionsregister.h"

signed int get_command_id(char * command)
{
	int count = 16;

	while(count--) {
		printf("%s\n", command_list[count]);
	}
	return -1;
}