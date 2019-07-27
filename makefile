main: fileprocess.o main.o
	gcc -g -ansi  -Wall fileprocess.o main.o -o main
fileprocess.o: fileprocess.c
	gcc -c -ansi -pedantic -Wall fileprocess.c -o fileprocess.o
main.o: main.c
	gcc -c  -ansi -pedantic -Wall main.c -o main.o
