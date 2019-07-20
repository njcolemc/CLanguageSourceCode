/*
 * Program Name  : NJCMAssn05MenuDriver.c 
 * Author        : Cole McGee
 * Date Created  : 20 June 2019
 * Purpose       : [Menu driver to run multiple programs from one source file]
 */

// preprocessor statements
#include <stdio.h>   //header file for input/output
#pragma warning(disable:4996)	// disables warning about scanf for visual studio


// function prototype definitions
int menu(void);

// Primary function for Ch.5 Ex.1 plus the auxiliary function to get user data for that problem
void exercise_05_1_min_to_hour(void);
void getData05_1(void);

// Define the variables for the above functions
int minutes, h, m; // minutes is user input, h and m are hours and minutes for the output
const int MINUTES_IN_HOUR = 60; // just incase the number of minutes in an hour changes later on down the line.

// This function does approximately the same as exercise_05_01 but does NOT use a separate get data function.
void exercise_05_5_addemup(void);


// main function

int main(void){

	int selection = menu();

	while (selection != 99)
	{
		printf("\n\n");

		// backend for the menu
		switch (selection)
		{

		case 1:
			exercise_05_1_min_to_hour();  // remove this line and replace with a call to your own function
			break;

		case 2:
			exercise_05_5_addemup();
			break;

		default:
			printf("Please enter a valid selection.\n");
		}

		printf("\n\n");

		// get the next menu selection.
		selection = menu();
	}
	
	getchar(); getchar(); return 0;
}

int menu(void){
	// declare variables
	int choice;

	// print the menu
	printf("                  Menu Driver Program                  \n");
	printf("_______________________________________________________\n\n");
	printf(" 1. #5.1 Minutes to Hours\n");
	printf(" 2. #5.5 AddEmUp\n\n");
	printf("99. Exit\n\n");

	// get input from user
	printf("Please select a valid number (1-99) and press enter: ");
	scanf("%d", &choice);
	printf("_______________________________________________________\n");
	// eat the end of line character
	getchar();

	return choice;
}

// ------------------------------------Program05_01-----------------------------------------------------

void exercise_05_1_min_to_hour(void){
	// Problem from book: Write a program that converts time in minutes to time in hours and minutes.
	// Use #define or const to create a symbolic constant for 60. Use a while loop to allow the 
	// user to enter values repeatedly and terminate the loop if a value for the time of 0 or less is entered.


	// Ask for user data, call the auxiliary function which is defined below this current function.
	printf("_____________________________________________________________\n");	
	getData05_1();

	while(minutes > 0){	

		// calculate the arguments to be passed to the output
		m = minutes % MINUTES_IN_HOUR; // modulo will save ONLY the remainder
		h = minutes / MINUTES_IN_HOUR; // int division trashes the remainder, which is perfect in this case

		// this will correctly format the word "hour(s)" in the output depending on the value of h
		switch (h){

			case 1:
				printf("%d minutes is equivalent to %d hour", minutes, h);
				break;

			default:
				printf("%d minutes is equivalent to %d hours", minutes, h);

		}

		// this will correctly format the word "minute(s)" in the output depending on the value of m
		switch (m){
			case 1:
				printf(" and %d minute.\n\n", m);
				break;

			default:
				printf(" and %d minutes.\n\n", m);

		}

		// ask for user data again to generate new conditions for the loop
		getData05_1();

	}
	printf("_____________________________________________________________\n");
}

void getData05_1(void){

	printf("Please enter an integer number of minutes you want converted \nto hours and minutes (enter 0 to exit): ");
	scanf(" %d", &minutes);
}

// ------------------------------------Program05_05-----------------------------------------------------

void exercise_05_5_addemup(void){
	// Problem from book: Change the program addemup.c which found the sum of the first 20 integers. Modify 
	// the program so that you can tell it interactively how far the calculation should proceed.
	// That is, replace the 20 with a variable that is read in.

	// Define the variables
	long int count, sum, limit;           /* declaration statement          */
    
    // Scan for input
	printf("_____________________________________________________________________________________\n");
	printf("This program will add all of the positive integers up to the integer that you choose.\n");
	printf("Please enter your integer, or enter 0 to exit: ");
	scanf(" %ld", &limit);

    // Add the numbers based on the input
    while (limit > 0){
    	count = 0;
    	sum = 0;
	    while (count <= limit) {
	        sum = sum + count;
	    	count = count + 1;
		}
		// Print the output
		printf("sum = %ld\n\n", sum);
		
		// Get new data to feed through the loop
		printf("Please enter your integer, or enter 0 to exit: ");
		scanf(" %ld", &limit);
	}
	printf("_____________________________________________________________________________________\n");
}



