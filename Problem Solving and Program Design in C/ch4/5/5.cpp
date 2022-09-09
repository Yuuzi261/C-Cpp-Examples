#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){

    double n;  //input - Data Usage, Gbs

    printf("Enter the Data Usage (n), Gbs > ");
    scanf("%lf", &n);

    if(n <= 0)
        printf("BAD DATA\n");
    else if(n <= 1)
        printf("Charges : 250\n");
    else if(n <= 2)
        printf("Charges : 500\n");
    else if(n <= 5)
        printf("Charges : 1000\n");
    else if(n <= 10)
        printf("Charges : 1500\n");
    else
        printf("Charges : 2000\n");

    return 0;
}