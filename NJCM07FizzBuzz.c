/*
	Program	: NJCM07FizzBuzz.c
	Author	: Cole McGee
	Date	: 07/06/2019
	Desc.	: Classic fizz buzz program, asks user for input, then will tell them if it is a FIZZ--divisible by 3--or a BUZZ--divisible by 5.

*/
#include <stdio.h>
#include <ctype.h>

// These are the FIZZ and BUZZ constants that'll be used in the program, easily able to change.
#define	FIZZ	3
#define	BUZZ	5

int main(void){
	// Declare and assign a min and max for the user input, and then declare the user input.
	const int MIN_NUM = 1;
	const int MAX_NUM = 1000;
	int number;

	// Introduction and get user data.
	printf("Welcome to FIZZBUZZ.\n\nEnter an integer between %d and %d, and\nI will tell you if it's a FIZZ (divisible by %d) \nor a BUZZ (divisible by %d)", MIN_NUM, MAX_NUM, FIZZ, BUZZ);
	getdata: printf("\nWhat is your integer? (Enter -1 to quit) ");
	scanf(" %d", &number);

	while(number != -1){

		// check to see if number is an integer
		// Use an elseif chain to validate user input is between the limits
		if (number < MIN_NUM){
			printf("Please enter a valid number greater than %d\n", MIN_NUM);
			goto getdata;
		}
		if (number > MAX_NUM){
			printf("Please enter a valid number less than %d\n", MAX_NUM);
			goto getdata;
		}

		// Use an elseif chain to determine if input is a FIZZ, BUZZ, FIZZBUZZ, or neither.
		// check for fizzbuzz first or fizzbuzz's wont be detected.
		if ( ( (number % FIZZ) == 0 ) && ( (number % BUZZ) == 0 ) )
		{
			printf("The number %d is a FIZZBUZZ", number);
		} 
		else if( (number % BUZZ) == 0)
		{
			printf("The number %d is a BUZZ", number);
		} 
		else if( (number % FIZZ) == 0 )
		{
			printf("The number %d is a FIZZ", number);
		}
		else
		{
			printf("The number %d is neither a FIZZ nor a BUZZ", number);
		}
		goto getdata;
	}


	// Exit code
	printf("\n\nPress the return key to exit the program...");
	getchar();getchar();return 0;
}
