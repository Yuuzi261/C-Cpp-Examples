#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char*, int);

int main(void) {

    int i = 0, j = 0;
    char temp_char, str[100];

    printf("Enter the string > ");
    do {

        scanf("%c", &temp_char);
        if (isalpha(temp_char)) {
            str[i] = tolower(temp_char);
            i++;
        }
        else if (isdigit(temp_char)) {
            str[i] = temp_char;
            i++;
        }

    } while (temp_char != '\n');

    str[i] = '\0';

    printf("input string : %s\n", str);

    if (isPalindrome(str, i - 1))
        printf("This is Palindrome.\n");
    else
        printf("This is NOT Palindrome.\n");

    system("pause");
    return 0;

}

int isPalindrome(char str[100], int len) {

    if (len == 0)
        return 1;
    else if (len == 1) {
        if (str[0] == str[len])
            return 1;
        else
            return 0;
    }
    else if (str[0] == str[len]) {
        str[len] = '\0';
        return isPalindrome(&str[1], len - 2);
    }
    else
        return 0;

}