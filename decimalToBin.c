#include <decimalToBin.h>

char symbols [4]={'*','#','%','!'};

 /*function that take a nuber and make it a bit with the given size */
int * number_to_bit(int numberToBit,int size)
{
	int  counter = 12;
	int i = 0;
	int mask;
	int* bitNum = malloc(sizeof(int)*11);
	/*the loop run with mask and print into an array the given number as bits */
	for (; counter >= 0; counter--) {
		mask = numberToBit >> counter;
		bitNum[counter] = mask & 1 ? 1 : 0;
	}
	/*pointer that give a validation option of -1 at the wanted place */
	bitNum[size] = -1;

	return bitNum;
}

/*uses the binary to deicmal to pick one of the spacial symbols*/
char  number_to_special4(int firstNum,int seccendNum)
{
  
	int whichSymbol;
	whichSymbol=binary_to_decimal(firstNum,seccendNum,2);
	return symbols[whichSymbol];

}
/*calulating two bit of a binary number and gives a number between 0-3*/
int binary_to_decimal(int firstNum,int seccendNum,int whichBase)
{
	int decimalNumber;
	/*calculating the number given by binnary to decimal formula of two numbers */
	decimalNumber += firstNum*pow(whichBase,0);
	decimalNumber += seccendNum*pow(whichBase,1);
	
	return decimalNumber;

}
/*take a char and putting him into an int then useing number to bit to get the ascii code in binary */
int * char_to_bit(char charToBit,int size)
{
	int caster=charToBit;

	return  number_to_bit(int charToBit,int size);

}
