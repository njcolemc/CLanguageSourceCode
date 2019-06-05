/*
PROGRAM	: forFahrCelsTable.c
AUTHOR	: 
DATE	: 06/04/2019
DESC.	: Uses for-loop to convert fahrenheit to celcius for a defined range of values.
*/

#include <stdio.h>

#define	LOWER	0
#define	UPPER	300
#define STEP	20

/* print Fahrenheit-Celsius table */
main(){
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.2f\n", fahr, (5.0/9.0)*(fahr-32));
}
