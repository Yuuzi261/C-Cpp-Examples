#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char grade;
	double minAve, curAve, percentage; //minAve is minimum average required, curAve is current average in course
	//percantage is the final counts as a percentage of the course grade

	printf("Enter desired grade> ");
	scanf("%c", &grade);
	printf("Enter minimum average required> ");
	scanf("%lf", &minAve);
	printf("Enter current average in course> ");
	scanf("%lf", &curAve);
	printf("Enter how much the final counts as a percentage of the course grade> ");
	scanf("%lf", &percentage);

	printf("\nYou need a score of %.2lf on the final to get a %c.\n", (minAve - curAve * ((100 - percentage) / 100)) / (percentage / 100), grade);
	//calculate the score on the final

	return 0;
}