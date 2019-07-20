/*
 * Program Name  : NJCM06.c
 * Author        : Cole McGee
 * Date Created  : 07/06/2019
 * Purpose       : [Menu driver for practice C programming files]
 */

// preprocessor statements
// header file for input/output
#include <stdio.h>   
// header file for string functions
#include <string.h>

// disables warning about scanf (might flag it in the editor, but it's OK)
#pragma warning(disable:4996)	

// function prototype definitions

int menu(void);

void exercise_06_06_square_cube(void);
void exercise_06_07_print_string_backward(void);
void exercise_06_11_print_array_backward(void);
void exercise_06_03_EC_print_descending_chars(void);
void exercise_06_08_EC_diff_div_product(void);

// main function

int main(void)
{
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
			printf("Select an item from the menu and it will show you the details.\n");
			break;

		case 2:
			exercise_06_06_square_cube();
			break;

		case 3:
			exercise_06_07_print_string_backward();
			break;

		case 4:
			exercise_06_11_print_array_backward();
			break;

		case 5:
			exercise_06_03_EC_print_descending_chars();
			break;

		case 6:
			exercise_06_08_EC_diff_div_product();
			break;

		default:
			printf("Please enter a valid selection.\n");
		}

		// make a couple of blank lines on the screen to separate your program output from the next menu
		printf("\n\n");

		// get the next menu selection, otherwise, you have an infinite loop!
		selection = menu();
	}

	return 0;
}

int menu(void)
{
	// declare variables
	int choice;

	// print the menu
	printf("----------------------------------------------\n");
	printf(" 1. Program Details \n");
	printf(" 2. #6.6 Print table of squares and cubes\n");			// put brief names of your programs/functions here
	printf(" 3. #6.7 Print string backward with while loop\n");
	printf(" 4. #6.11 Read into array and print backward\n");
	printf(" 5. #6.3 EC Pattern of descending chars\n");
	printf(" 6. #6.8-9 EC Divide difference by product\n");
	printf("99. Exit\n\n");
	printf("----------------------------------------------\n");
	// get input from user
	printf("Please select number and press enter: ");
	scanf("%d", &choice);
	printf("----------------------------------------------\n");
	// eat the end of line character
	getchar();

	return choice;
}

/*
 * Function Name	: hello
 * Description      : This is a sample of how to write a function
 *					  within the menu driver
 */

 // NOTE: Since everything is in one file, you do not need to include <stdio.h> again so comment it out.
 // I would not delete it entirely in case you want to change it to a stand-alone program again.
 //#include <stdio.h>


//------------------------------------------------------------------------
/*
 * Function Name	: exercise_06_06_square_cube
 * Description      : This program asks for a min and max integer, then displays each integer between those along with its square and its cube.
 */

void exercise_06_06_square_cube(void)
{
	// declare the min and max
	double min, max;

	// Introduce the program. It can handle floats but doesn't show decimals, so the user isn't told that.
	printf("This program will ask for a minimum and then maximum\n");
	printf("integer, then it will print a table of each one, with\n");
	printf("that integer's square and cube next to it.\n\n");

	// Get the user's integers
	printf("Enter a minimum integer squared and cubed: ");
	scanf(" %lf", &min);
	
	printf("Enter a maximum integer squared and cubed: ");
	scanf(" %lf", &max);

	// Print the table's header
	printf("      Number       Square         Cube\n");
	// Print the table's data
	double x = min;
	while(x >= min && x<=max){
		printf("%12.0lf %12.0lf %12.0lf\n", x, x*x, x*x*x);
		x = x + 1;
	}
}

//------------------------------------------------------------------------
/*
 * Function Name	: exercise_06_07_print_string_backward
 * Description      : This program asks for a word, then prints it backwards.
 */

void exercise_06_07_print_string_backward(void)
{
	// this creates space in memory for the string we will reverse
	char input[81];
	// this creates space in memory for the while loop parameter, and for the string parameter
	int i, length;

	// instructions for the program
	printf("This will accept a word and then print it backward.\n");
	// asks for word
	printf("Enter a word: ");
	// gets word to reverse 
	scanf("%s", input);
	
	// length is used in the while loop and must be set before the loop starts
	length = strlen(input);
	// i is used in the while loop and must be set before the loop starts
	i = length - 1;
	// the while loop checks one condition--have we reached the end of the string?
	while (i >= 0)
	{
		// prints the letter right before the null character, then to the left of that, etc.
		printf("%c", input[i]);
		// changes the length variable to move one letter left of the last 
		// 		printed character, or it will endlessly print the last character
		length = length - 1;
		// moves the index number one letter left so the loop knows when we 
		// 		reach the end of the string
		i--;
	}
	// whitespace for readability
	printf("\n");
}

//------------------------------------------------------------------------
/*
 * Function Name	: exercise_06_11_print_array_backward
 * Description      : [fill in]
 */

void exercise_06_11_print_array_backward(void)
{
	int aArray[9], bArray[9], a, b;
	// put your code here
	printf("This program will ask you for an array of integers.\n");
	printf("Then it will print those integers in reverse order.\n");
	printf("Start entering integers, separate them by pressing enter.\n\n");


	// for loop will get the user's array
	for(a = 0; a <= 7; a++){
		printf("Enter an integer: ");
		scanf("%d", &aArray[a]);
	}

	// another for loop will reverse the user's array
	for(a = 7, b = 0; a >= 0; a--, b++){
		bArray[b] = aArray[a];
	}

	printf("\nThe numbers in reverse order are:\n\n");
	for(b = 0; b <= 7; b++){
		printf("%8d\n", bArray[b]);
	}


}

//------------------------------------------------------------------------
/*
 * Function Name	: exercise_06_03_EC_print_descending_chars
 * Description      : [fill in]
 */

void exercise_06_03_EC_print_descending_chars(void)
{
	// put your code here
	printf("You need to create code for exercise_06_03_EC_print_descending_chars!");

}

void exercise_06_08_EC_diff_div_product(void)
{
	// put your code here
	printf("You need to create code for exercise_06_08_EC_diff_div_product!");
}
