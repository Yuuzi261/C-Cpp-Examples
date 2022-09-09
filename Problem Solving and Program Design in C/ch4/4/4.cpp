#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){

    char color_beginning;

    printf("Enter the begining of the color > ");
    scanf("%c", &color_beginning);

    switch (color_beginning){
        case ('O'):
        case ('o'):
            printf("ammonia\n");
            break;
        case ('B'):
        case ('b'):
            printf("carbon monoxide\n");
            break;
        case ('Y'):
        case ('y'):
            printf("hydrogen\n");
            break;
        case ('G'):
        case ('g'):
            printf("oxygen\n");
            break;
        default:
            printf("contents unknown\n");
    }

    return 0;
}