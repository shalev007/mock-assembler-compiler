main: main.o fileprocess.o symbolprocess.o symbollist.o
	gcc -g -ansi  -Wall main.o fileprocess.o symbolprocess.o symbollist.o -o main
fileprocess.o: fileprocess.c fileprocess.h symbolprocess.h
	gcc -c -ansi -pedantic -Wall fileprocess.c -o fileprocess.o
symbolprocess.o: symbolprocess.c symbolprocess.h symbollist.h
	gcc -c -ansi -pedantic -Wall symbolprocess.c -o symbolprocess.o
symbollist.o: symbollist.c symbollist.h
	gcc -c -ansi -pedantic -Wall symbollist.c -o symbollist.o
main.o: main.c fileprocess.h
	gcc -c -ansi -pedantic -Wall main.c -o main.o
