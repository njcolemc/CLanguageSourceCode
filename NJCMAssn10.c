// C Primer Plus
// Chapter 10 Exercise 1:

// Modify the rain program in Listing 10.7 so that it does the calculations
// using pointers instead of subscripts. (You still have to declare and
// initialize the array.)

#include <stdio.h>
#define NUM_STUDENTS 	10 // number of students in class 
#define NUM_TESTS 		4 // number of tests in class


int main(void)
{
	// initializing rainfall data for 2010 - 2014
    const float grades[NUM_TESTS][NUM_STUDENTS] =
    {
        {65,75,85,95,74,74,98,75,85,65},
        {88,65,75,78,99,88,77,76,98,100},
        {78,65,78,82,93,81,79,97,82,65},
        {68,82,75,65,100,85,77,85,95,85},
    };

// ------------------------- 

	float subtot, total;

	// declare pointers
	const float (*tests_ptr)[NUM_STUDENTS];
	const float *student_ptr;

	printf(" TEST \t\tAVERAGE \n");
	for (tests_ptr = grades, total = 0; tests_ptr < grades + NUM_TESTS; tests_ptr++)
	{
		// for each year, sum rainfall for each month
		for (student_ptr = *tests_ptr, subtot = 0; student_ptr < *tests_ptr + NUM_STUDENTS; student_ptr++)
			subtot += *student_ptr;
		subtot /= NUM_STUDENTS;
		printf("%5d %15.1f\n", (int) (1 + (tests_ptr - grades)), subtot);
		total += subtot; // total for all years }
	}

	//printf("\nThe test average is %.1f percent.\n\n", total/NUM_TESTS);
	
	printf("\nSTUDENT AVERAGES:\n");
	printf(" STU1  STU2  STU3  STU4  STU5  STU6  STU7  STU8  STU9 STU10\n");

	int students, test;

	for (students = 0; students < NUM_STUDENTS; students++)
	{ 
		// for each month, sum rainfall over years
		for (test = 0, subtot = 0; test < NUM_TESTS; test++)
			subtot += *(*(grades + test) + students);
		printf(" %4.1f ", subtot/NUM_TESTS);
	}

	printf("\n");
	return 0; 
}


