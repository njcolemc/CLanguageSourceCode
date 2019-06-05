/*
PROGRAM	: fahrCelsTable.c
AUTHOR	:
DATE	: 06/04/2019
DESC.	: Convert defined range of fahrenheit temperatures to celsius using while-loop.
*/

#include <stdio.h>

/* print Fahrenheight-Celcius table for fahr = 0, 20, ..., 300 */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf ("%3.0f\t%6.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
