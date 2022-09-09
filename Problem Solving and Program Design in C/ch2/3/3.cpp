#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main(void) {
	double hours, minutes;

	printf("Please enter the hours and minutes:");

	scanf("%lf %lf", &hours, &minutes);

	hours = hours + minutes / 60; //convert the elapsed time into hours.

	printf("Temperature is %lf ¢XC.\n", 4 * hours * hours / (hours + 2) - 20); //print the temperature.

	return 0;
}