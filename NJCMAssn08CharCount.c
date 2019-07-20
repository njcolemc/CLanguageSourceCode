/*
	Program	: NJCMASsn08CharCount.c
	Author	: Cole McGee
	Date	: 07/11/2019
	Desc.	: This program will count the number of characters including new-line/end-of-line,
				the number of uppercase letters, the number of lowercase letters, number of lines,
				and number of words.
	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char fname[50];

int main(int argc, char *argv[] )
{
	// 	Declare the variables for the letters in the file, the address for the file,
	// 		and for the name of the file to be called.
	int ch;
	FILE * fp;
	//	Also declare variables to store the values of numberOfChars, numberOfUppercase,
	//		numberOfLowercase, numberOfLines, and numberOfWords, and initialize to 0.
	int numChars, numUpper, numLower, numLines, numWords;
	numChars = numUpper = numLower = numLines = numWords = 0;

	if(argc!=2)
	{
		printf("Please enter one filename after the program name. Press enter to exit");
		goto endOfProgram;
	} else { goto programStart;}

	programStart:
	// Ask for the name of the file, assign it to fname, and then open in read mode with fopen()
	//printf("\nEnter the name of the file: \t");
	//scanf("%s", fname);
	fp = fopen(argv[1], "r");

	// If there is no file, print error.
	if (fp == NULL)
	{
		printf("Failed to open file. Bye\n");
		exit(1);
	}

	// If the file exists, and the contents are not EOF, put the characters on the screen
	while ((ch = getc(fp)) != EOF)
	{

		if (ch == '\n')
		{ 	
			++numLines; 
		}	// increments line count

		if (ch != EOF && ch != '\0')
		{ 
			++numChars;
		}	// increments char count

		if ( isspace(ch) && !(ispunct(ch)))
		{ 
			numWords++;
		}	// increments word count
		
		if (isupper(ch))
		{
			++numUpper;
		}	// increments upper count

		if (islower(ch))
		{
			++numLower;
		}	// increments lower count
	}
	printf("The file %s contains: \n", argv[1]);
	printf("\n\tNumber of Characters: \t\t%4d\n", numChars);
	printf("\tNumber of Uppercase letters: \t%4d\n", numUpper);
	printf("\tNumber of Lowercase letters: \t%4d\n", numLower);
	printf("\tNumber of Lines: \t\t%4d\n", numLines);			
	printf("\tNumber of Words: \t\t%4d\n", numWords); 
	
	// close the file
	fclose(fp);


	// --------------------------
	// end of main
	getchar();
	endOfProgram: getchar();return 0;
}