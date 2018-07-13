// Lab5A
// Robert John Graham III
// July 13,2018
// Performance Lab for Pythagoras Output

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
	// Initialize variables here 
	double rightTriangleLegA = 0;
	double rightTriangleLegB = 0;
	double rightTriangleHypotenuse = 0;

	/* Input values and assign to variables here*/
	printf("Input the length of leg A and leg B for your right triangle. \n"); // User prompt
	printf("Separate the two lengths with a space.  (e.g., 1.3 3.7) \n"); // User prompt
	scanf("%lf %lf", &rightTriangleLegA, &rightTriangleLegB);

	/* INPUT VALIDATION */
	/* rightTriangleLegA > 0 tests that the user input was positive */
	/* rightTriangleLegB > 0 tests that the user input was positive */
	// If both sides are positive, compute hypotenuse and print it.  Otherwise, print error message.
	if ((rightTriangleLegA > 0) && (rightTriangleLegB > 0))
	{
		rightTriangleHypotenuse = sqrt((rightTriangleLegA*rightTriangleLegA) + (rightTriangleLegB*rightTriangleLegB));
		printf("Your hypotenuse is %.2f. \n", rightTriangleHypotenuse);
	}
	else
	{
		printf("One of the sides provided is less than or equal to ). Please rerun the program with two positive values.");
	}

	return 0;
}
