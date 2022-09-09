#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap(double, double, double, char);
double g(double);
double h(double);

int main(void){

    char function;
    double a, b;
    int n;

    printf("g(x) = x^2(sinx)\nh(x) = (4-x^2)^(1/2)\n");
    do{
        printf("Enter the function you want.  (g or h) > ");
        scanf(" %c", &function);
    } while ((function != 'g') && (function != 'h'));

    if(function == 'g')
        a = 0, b = 3.14159;
    else
        a = -2, b = 2;
        
    printf("\nIntegration interval : [%lf, %lf]\n", a, b);
        
    for(n = 2;n < 129;n*=2){
        printf("\nFor n = %d\nArea = %lf\n", n, trap(a, b, n, function));
    }

    return 0;

}

double trap(double a, double b, double n, char function){

    int i;
    double area = (b - a) / (2 * n), temp = 0;

    if(function == 'g'){

        for(i = 1;i < n;i++){
            temp += g( a + ((b - a) / n) * i );
        }
            
        temp*=2;
        temp += g(a) + g(b);

    }
    else {

        for(i = 1;i < n;i++){
            temp += h( a + ((b - a) / n) * i );
        }

        temp*=2;
        temp += h(a) + h(b);

    }

    area*=temp;

    return area;

}

double g(double x){
    return x * x * sin(x);
}

double h(double x){
    return sqrt(4 - x * x);
}