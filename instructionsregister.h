#include <stdio.h>

#define DEFAULT_VALUE 100

int _IC;

char * command_list[] = {
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

signed int get_command_id(char *);