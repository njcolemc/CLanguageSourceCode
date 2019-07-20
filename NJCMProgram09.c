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

int menu(void);									// Menu system to run the menu driver

void echoPound(void); 							// Classic echo program, end with #

void program09_01_min_driver(void);				// functions for Ch9 Problem #1
double min(double n, double m);

void program09_03_printchar_driver(void);		// functions for Ch9 Problem #3
void printchar(char ch, int num_chars_per_line, int num_lines);

void program09_06_sort_driver(void);			// functions for Ch9 Problem #6
void sort(double* x, double* y, double* z);

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
			echoPound();  // remove this line and replace with a call to your own function
			break;

		case 2:
			program09_01_min_driver();
			break;

		case 3:
			program09_03_printchar_driver();
			break;

		case 4:		// remove all of the case numbers that you are not using, or add more if needed.
			program09_06_sort_driver();
			break;

		default:
			printf("Please enter a valid selection.\n");
		}

		// make a couple of blank lines on the screen to separate your program output from the next menu
		printf("\n");

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
	printf(" 1. Echo (#) \n");
	printf(" 2. Exercise 1 Minimum\n");
	printf(" 3. Exercise 3 Print characters\n");
	printf(" 4. Exercise 6 Sort 3 floats\n");			// delete or comment out those you aren't using.
	printf("99. Exit\n\n");

	// get input from user
	printf("Please select number and press enter: ");
	scanf("%d", &choice);

	// eat the end of line character
	getchar();

	return choice;
}

// Put your first program here instead of this one. Put the others after this.

/*
 * Program/Function Name: hello
 * Chapter              : Chapter 9
 * Author               : Your Name
 * Date Created         : Today's Date
 * Purpose              : One-line description
 * Description          : Detailed description (usually 3-10 lines)
 */

 // NOTE: Since everything is in one file, you do not need to include <stdio.h> again so comment it out.
 // I would not delete it entirely in case you want to change it to a stand-alone program again.
 //#include <stdio.h>

void echoPound(void)
{
	char ch;

	while( (ch = getchar()) != '#')
	{
		putchar(ch);
	}
}

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