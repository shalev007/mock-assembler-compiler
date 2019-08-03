main: main.o fileprocess.o symbolprocess.o symbollist.o instructionsregister.o symbol.o
	gcc -g -ansi  -Wall main.o fileprocess.o symbolprocess.o symbollist.o instructionsregister.o symbol.o -o main
fileprocess.o: fileprocess.c fileprocess.h symbolprocess.h
	gcc -c -ansi -pedantic -Wall fileprocess.c -o fileprocess.o
symbolprocess.o: symbolprocess.c symbolprocess.h symbollist.h
	gcc -c -ansi -pedantic -Wall symbolprocess.c -o symbolprocess.o
symbollist.o: symbollist.c symbollist.h
	gcc -c -ansi -pedantic -Wall symbollist.c -o symbollist.o
instructionsregister.o: instructionsregister.c instructionsregister.h
	gcc -c -ansi -pedantic -Wall instructionsregister.c -o instructionsregister.o
symbol.o: symbol.c symbol.h symbollist.h instructionsregister.h
	gcc -c -ansi -pedantic -Wall symbol.c -o symbol.o
decimalToBin.o: decimalToBin.c decimalToBin.h
	gcc -c -ansi -pedantic -Wall decimalToBin.c -o decimalToBin.o -lm
main.o: main.c fileprocess.h
	gcc -c -ansi -pedantic -Wall main.c -o main.o