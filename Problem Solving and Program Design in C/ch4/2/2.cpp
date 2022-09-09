#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){

    double wt_lb,  //input - weight in pounds
           ht_in,  //input - height in inches
           BMI;    //output - BMI

    printf("Enter the weight in pounds> ");
    scanf("%lf", &wt_lb);
    printf("Enter the height in inches> ");
    scanf("%lf", &ht_in);

    BMI = 703 * wt_lb / (ht_in * ht_in);

    BMI = int(BMI * 10 + 0.5) / 10.0;  //rounded to tenths

    printf("Your BMI is %.1lf\n", BMI);

    if(BMI < 18.5)
        printf("Underweight\n");
    else if(BMI < 25)
        printf("Normal\n");
    else if(BMI < 30)
        printf("Overweight\n");
    else
        printf("Obese\n");

    return 0;
}