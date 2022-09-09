#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double, int, int);
double derivative_f(double, int, int);

int main(void) {

	int c, n, count = 0;
	double x, y;

	printf("Enter the c and n.  (type:c n) > ");
	scanf("%d %d", &c, &n);

	x = c / 2.0;
	y = f(x, c, n);

	while (fabs(y) > 0.000001) {

		x = x - f(x, c, n) / derivative_f(x, c, n);
		y = f(x, c, n);

		if(++count == 100){
			printf("Can't find the real root.\n");
			break;
		}

	}

	if(count != 100)
		printf("The answer of c^(1/n) is %lf.\n", x);

	return 0;
}

double f(double x,int c, int n) {
	return (pow(x,n) - c);
}

double derivative_f(double x,int c,int n) {
	return (n * pow(x, n - 1));
}