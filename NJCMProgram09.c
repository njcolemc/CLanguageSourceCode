/*
 * Program Name  : NJCM09.c
 * Author        : Cole McGee
 * Date Created  : 07/11/2019
 * Purpose       : Menu driver for practice C programming files
 *
 */

 // preprocessor statements
#include <stdio.h>   //header file for input/output
#include <ctype.h>
#pragma warning(disable:4996)	// disables warning about scanf (might flag it in the editor, but it's OK)

 // function prototype definitions

int menu(void);							// Menu system to run the menu driver

void echoPound(void); 						// Classic echo program, end with #

void program09_01_min_driver(void);				// functions for Ch9 Problem #1
double min(double n, double m);

void program09_03_printchar_driver(void);			// functions for Ch9 Problem #3
void printchar(char ch, int num_chars_per_line, int num_lines);

void program09_06_sort_driver(void);				// functions for Ch9 Problem #6
void sort(double* x, double* y, double* z);

// main function

int main(void)
{
	// Display a menu at the start of the program, user enters menu item to proceed.
	int selection = menu();

	while (selection != 99)
	{
		// graphical formatting
		printf("\n\n");

		// switch to the item that the user enters
		switch (selection)
		{

		case 1: 
			echoPound();  // this will run echo, and end with a Pound sign
			break;

		case 2: 
			program09_01_min_driver();
			break;

		case 3: 
			program09_03_printchar_driver();
			break;

		case 4:	
			program09_06_sort_driver();
			break;

		default:
			printf("Please enter a valid selection.\n");
		}

		// formatting
		printf("\n");

		// call menu() and assign it to the switch condition above
		selection = menu();
	}

	return 0;
}

int menu(void)
{
	// declare variables
	int choice;

	// print the menu with the correct numbers the user will choose
	printf(" 1. Echo (#) \n");
	printf(" 2. Exercise 1 Minimum\n");
	printf(" 3. Exercise 3 Print characters\n");
	printf(" 4. Exercise 6 Sort 3 floats\n");
	printf("99. Exit\n\n");

	// get input from user and return it to main()
	printf("Please select number and press enter: ");
	scanf("%d", &choice);

	// eat the end of line character
	getchar();

	return choice;
}

// Echo module
void echoPound(void)
{
	char ch;

	while( (ch = getchar()) != '#')
	{
		putchar(ch);
	}
}

// Minimum finder
void program09_01_min_driver(void)
{
	printf("min(3.0,7.5) = %f\n", min(3.0, 7.5));
	printf("min(-3.0,-7.5) = %f\n", min(-3.0, -7.5));
	printf("min(7.5, 7.5) = %f\n", min(7.5, 7.5));
}

double min(double n, double m)
{
	double min;

	if(n < m)
	{
		min = n;
	}
	else
	{
		min = m;
	}

	return min;
}

// Prints a character a specified number of times, on a specified number of lines.
void program09_03_printchar_driver(void)
{
	printf("\nprintchar('*', 2, 3)\n");
	printchar('*', 2, 3);
	printf("\nprintchar('-', 4, 5)\n");
	printchar('-', 4, 5);
}

void printchar(char ch, int num_chars_per_line, int num_lines)
{
	// printchar
	int i = 1;
	int j = 1;

	for(j = 1; j <= num_lines; j++)
	{
		for(i = 1; i <= num_chars_per_line; i++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}

// feed data to program and then call our own sort() function to sort in ascending order
void program09_06_sort_driver(void)
{
	double a = -2.4;
	double b = 0.0;
	double c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = 0.0;
	c = -2.4;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = -2.4;
	c = 0.0;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 0.0;
	b = -2.4;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 0.0;
	b = 7.3;
	c = -2.4;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = -2.4;
	b = 7.3;
	c = 0.0;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = -2.4;
	b = 0.0;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = 7.3;
	c = 0.0;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = 0.0;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 0.0;
	b = 7.3;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = 7.3;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 0.0;
	b = 0.0;
	c = 7.3;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 0.0;
	b = 7.3;
	c = 0.0;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);

	a = 7.3;
	b = 0.0;
	c = 0.0;
	printf("Before sort: a = %f, b = %f, c = %f\n", a, b, c);
	sort(&a, &b, &c);
	printf("After sort : a = %f, b = %f, c = %f\n\n", a, b, c);
}

// this will sort exactly three double float numbers
void sort(double *a, double *b, double *c)
{
	double temp;
	// sort
	if (*a > *b)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}

	if (*b > *c)
	{
		temp = *c;
		*c = *b;
		*b = temp;

		if (*a > *b)
		{
			temp = *b;
			*b = *a;
			*a = temp;
		}	// double check a,b are correctly sorted
	}
	
}
