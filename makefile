main: fileprocess.o main.o symbollist.o
	gcc -g -ansi  -Wall fileprocess.o main.o symbollist.o -o main
fileprocess.o: fileprocess.c
	gcc -c -ansi -pedantic -Wall fileprocess.c -o fileprocess.o
symbollist.o:symbollist.c
	gcc -c -ansi -pedantic -Wall symbollist.c -o symbollist.o
main.o: main.c
	gcc -c -ansi -pedantic -Wall main.c -o main.o
