main: main.o fileprocess.o symbollist.o
	gcc -g -ansi  -Wall main.o fileprocess.o symbollist.o -o main
fileprocess.o: fileprocess.c fileprocess.h symbollist.h
	gcc -c -ansi -pedantic -Wall fileprocess.c -o fileprocess.o
symbollist.o: symbollist.c symbollist.h
	gcc -c -ansi -pedantic -Wall symbollist.c -o symbollist.o
main.o: main.c fileprocess.h
	gcc -c -ansi -pedantic -Wall main.c -o main.o
