main:main.o
		gcc -ansi -lm  -Wall  main.o -o main

main.o: main.c
		gcc -ansi -pedantic -Wall -c main.c
