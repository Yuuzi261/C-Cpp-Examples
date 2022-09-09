#define _CRT_SECURE_NO_WARNINGS
#define FEET_PER_MILES 5280
#define METERS_PER_MILES 5280.0 / 3282 * 1000
#include <stdio.h>
#include <stdlib.h>

double ask_for_the_data(void);
void cal_the_fps_and_mps(double);

int main(void){

    double sec;   //pure seconds

    //star1
    sec = ask_for_the_data();
    cal_the_fps_and_mps(sec);
    //star2
    sec = ask_for_the_data();
    cal_the_fps_and_mps(sec);
    //star3
    sec = ask_for_the_data();
    cal_the_fps_and_mps(sec);
    //star4
    sec = ask_for_the_data();
    cal_the_fps_and_mps(sec);

    return 0;
}

double ask_for_the_data(void){
    int mins;       //input - minutes
    double sec;     //input - seconds
    printf("Please Enter the star's data.(minutes second) > ");
    scanf("%d %lf", &mins, &sec);

    return mins * 60 + sec;
}

void cal_the_fps_and_mps(double sec){
    double fps, mps;
    fps = FEET_PER_MILES / sec;
    mps = METERS_PER_MILES / sec;
    printf("fps = %.2lf\n", fps);
    printf("mps = %.2lf\n", mps);
}