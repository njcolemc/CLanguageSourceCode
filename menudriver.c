/*
 * Program Name  : NJCMAssn05MenuDriver.c [Change LastFirst to your own names]
 * Author        : Cole McGee
 * Date Created  : 20 June 2019
 * Purpose       : [Menu driver for practice C programming files]
 *
 * You will use this file and attach your c programs to the bottom of this file,
 * but they will now be functions instead of stand-alone programs.
 * This file has Hello World included as an example.
 *
 * Using a menu driver has two purposes, first to give you experience using menu drivers,
 * second to facilitate the ease of grading multiple program assignments.
 *
 * Steps to add a program/function:
 * 1. Move to the very bottom of this file.
 * 2. Write the code for your new function (remember not to use main as its name because there can only be one main).
 * 3. Go to the top and add the prototype definition above main().
 * 4. Add a case block to run the function.
 * 5. Add a menu option.
 * 6. Run the program.
 * 7. Debug and test as needed.
 * 8. Repeat for each of your other program assignments in this chapter.
 *
 * Notes        :
 *
 * Each C program must have one - and ONLY one - main() function.
 * The main() function serves as the starting point.
 *
 * Yes! You should turn in only ONE .c file even if there are multiple programs
 * required for the chapter!
 *
 * Remember to change the name of the file to use your own name and replace NN
 * with the chapter number (use a leading 0 for chapters 1-9).
 */

 // preprocessor statements
#include <stdio.h>   //header file for input/output
#pragma warning(disable:4996)	// disables warning about scanf (might flag it in the editor, but it's OK)


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
	// variable declaration and initialization via call to menu()
	// This also serves as the 'priming' read for the following while loop
	int selection = menu();

	while (selection != 99)
	{
		// make a couple of blank lines on the screen to separate your program output from the menu
		printf("\n\n");

		// The switch statement is similar to a chained if-else except conditions fall through in C!
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

		// make a couple of blank lines on the screen to separate your program output from the next menu
		printf("\n\n");

		// get the next menu selection, otherwise, you have an infinite loop!
		selection = menu();
	}
    getchar(); getchar();
	return 0;
}

int menu(void){
	// declare variables
	int choice;

	// print the menu
	printf("                  Menu Driver Program                  \n");
	printf("_______________________________________________________\n\n");
	printf(" 1. #5.1 Minutes to Hours\n");			// put brief names of your programs/functions here
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
/*
 * Program/Function Name: NJCMAssn05_01MinutesToHours.c
 * Chapter              : Chapter 2
 * Author               : Your Name
 * Date Created         : Today's Date
 * Purpose              : One-line description
 * Description          : Detailed description (usually 3-10 lines)
 */

// good practice to comment out all necessary libraries, to know which are required for this block of program,
// but are already included above. In this case it is just stdio.h
//#include <stdio.h>

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
/* Program	:
 * Author	:
 * Date		:
 * Desc.	:
 */

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



