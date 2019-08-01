#include "instructionsregister.h"


const char * command_list[] = {
	"mov", /* id: 0 */
	"cmp", /* id: 1 */
	"add", /* id: 2 */
	"sub", /* id: 3 */
	"not", /* id: 4 */
	"clr", /* id: 5 */
	"lea", /* id: 6 */
	"inc", /* id: 7 */
	"dec", /* id: 8 */
	"jmp", /* id: 9 */
	"bne", /* id: 10 */
	"red", /* id: 11 */
	"prn", /* id: 12 */
	"jsr", /* id: 13 */
	"rts", /* id: 14 */
	"stop" /* id: 15 */ 
};

signed int get_command_id(char * command)
{
	int count = 16;

	while(count--) {
		if(strcmp(command_list[count], command) == 0) {
			return count;
		}
	}
	return -1;
}

bool is_command(char * command)
{
	if (get_command_id(command) > -1) {
		return true;
	}

	return false;
}