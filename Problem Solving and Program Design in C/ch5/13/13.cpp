#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){

    int player_number, HO_sum, H_sum, input_return_value;
    char batting_record;
    FILE *inp;      //declare

    inp = fopen("input.txt", "r");

    input_return_value = -2;

    while (fscanf(inp, "%d", &player_number) != EOF){

        HO_sum = 0, H_sum = 0;

        printf("Player %d's record:", player_number);

        while (1){

            if(input_return_value = fscanf(inp, "%c", &batting_record) == EOF)
                break;

            if(batting_record == 'H'){
                HO_sum++;
                H_sum++;
            }
            else if(batting_record == 'O')
                HO_sum++;
            else if(batting_record == '\n')
                break;

            printf("%c", batting_record);

        }

        printf("\nPlayer %d's batting average: %.3lf\n\n", player_number, ((double) H_sum) / HO_sum);

    }
    
    return 0;
    
}