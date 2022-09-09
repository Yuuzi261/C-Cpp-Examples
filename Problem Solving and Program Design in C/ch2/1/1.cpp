#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main(void) {
	double rate = 1.5, BOR, EOR; //beginning odometer reading and ending odometer reading

	printf("TAXI FARE CALCULATOR\nEnter beginning odometer reading=> ");
	scanf("%lf", &BOR);
	printf("Enter ending odometer reading=> ");
	scanf("%lf", &EOR);
	printf("You traveled a distence of %.1lf miles. At $%.2f per miles, your fare is $%.2lf.\n", EOR - BOR, rate, (EOR - BOR) * rate);

	return 0;
}