#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(int*, int*, char*);
int is_prime_number(int);
int is_palindrome(int, int);

int main(void) {

    int number, reverse_number;
    char chr;

    printf("Enter a list of number > ");
    chr = ' ';
    while(chr != '\n') {

        reverse(&number, &reverse_number, &chr);

        if(is_prime_number(number))
            printf("The number is a prime number.\n");
        else
            printf("The number is NOT a prime number.\n");

        if(is_palindrome(number, reverse_number))
            printf("The number is a palindrome.\n");
        else
            printf("The number is NOT a palindrome.\n");

    }

    system("pause");
    return 0;

}

void reverse(int* ptrN, int* ptrRN, char* ptrC) {

    *ptrN = 0, *ptrRN = 0;

    int digit, temp, number_of_digits = 0, zero_count = 0;
    int i = 0;

    while(1) {

        scanf("%c", ptrC);

        if(number_of_digits == 0)
            printf("\nFor ");

        if(*ptrC == ' ' || *ptrC == '\n')
            break;

        printf("%c", *ptrC);

        digit = (int)(*ptrC) - (int)'0';
        *ptrN = *ptrN * 10 + digit;
        *ptrRN += digit * pow(10, number_of_digits);

        number_of_digits++;

        //count the amounts of zero which may disapper after change to the int type.  Ex: 10100 --> (int)00101 --> 101 --> lost 2 zero
        if(digit == 0)
            zero_count++;
        else
            zero_count = 0;

    }

    printf(":\nThe reversed number is ");
    //fill the lost zero
    for(i = 0;i < zero_count;i++)
        printf("0");

    printf("%d.\n", *ptrRN);

}

int is_prime_number(int number) {

    int i, number_sqrt, number_mod_six;
    
    if(number == 2 || number == 3)
        return 1;
    else if(number > 4) {

        number_mod_six = number % 6;
        if( number_mod_six != 1 && number_mod_six != 5 )
            return 0;

        number_sqrt = sqrt(number);
        for(i = 5;i <= number_sqrt;i += 6) {
            if(number % i == 0 || number % (i + 2) == 0)
                return 0;
        }

        return 1;

    }
    else
        return 0;

}

int is_palindrome(int number, int reverse_number) {

    if(number == reverse_number)
        return 1;
    else
        return 0;

}