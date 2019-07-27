main:main.o
		gcc -ansi -lm  -Wall  main.o -o main
fileprocess.o: fileprocess.c
	gcc -ansi -pedantic -Wall -c fileprocess.c
readfile.o: readfile.c
		gcc -ansi -pedantic -Wall -c readfile.c
main.o: main.c
		gcc -ansi -pedantic -Wall -c main.c
