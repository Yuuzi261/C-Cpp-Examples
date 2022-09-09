#define _CRT_SECURE_NO_WARNINGS
#define water_bp 100
#define mercury_bp 357
#define copper_bp 1187
#define silver_bp 2193
#define gold_bp 2660
#include <stdio.h>
#include <stdlib.h>

int within_x_percent(int, double, double);

int main(void){

    double bp,   //input - boiling point
           dev;  //input - the range of deviation
    printf("Enter the boiling point(°C) and the deviation(%) (bp dev) > ");
    scanf("%lf %lf", &bp, &dev);

    if(within_x_percent(water_bp, bp, dev))
        printf("Water\n");
    else if(within_x_percent(mercury_bp, bp, dev))
        printf("Mercury\n");
    else if(within_x_percent(copper_bp, bp, dev))
        printf("Copper\n");
    else if(within_x_percent(silver_bp, bp, dev))
        printf("Silver\n");
    else if(within_x_percent(gold_bp, bp, dev))
        printf("Gold\n");
    else
        printf("Substance unknown\n");

    return 0;
}

int within_x_percent(int metal_bp, double bp, double dev){
    if(metal_bp * (1 - dev / 100) <= bp && bp <= metal_bp * (1 + dev / 100))
        return 1;
    else
        return 0;
}