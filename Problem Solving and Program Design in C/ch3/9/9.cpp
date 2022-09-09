#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_data();
void cal_cases(int);

int main(void){

    printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT\n\n");

    //first input
    input_data();
    //second input
    input_data();
    //third input
    input_data();

    return 0;
}

void input_data(){
    int days;  //input - days
    printf("Enter day number>> ");
    scanf("%d", &days);
    cal_cases(days);
}

void cal_cases(int days){
    int cases = 40000 / (1 + 39999 * exp(-0.24681 * days));
    printf("By day %d, modle predicts %d cases total.\n\n", days, cases);
}