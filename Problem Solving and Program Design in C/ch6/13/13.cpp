#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    start, build_id, build_num, identifier, number, stop
}STATE;

STATE transition(STATE, char);

int main(void) {

    char transition_char;
    STATE state = start;

    printf("Enter the data > ");

    do {
        if (state == identifier) {
            printf(" - Identifier\n");
            state = start;
        }
        else if (state == number) {
            printf(" - Number\n");
            state = start;
        }
        scanf("%c", &transition_char);
        if (transition_char != ' ' && transition_char != '.' && transition_char != '\n')
            printf("%c", transition_char);
        state = transition(state, transition_char);
    } while (state != stop);

    system("pause");
    return 0;

}

STATE transition(STATE state, char transition_char) {

    if (state == start) {
        if (transition_char == ' ')
            return start;
        else if (isdigit(transition_char))
            return build_num;
        else if (isalpha(transition_char))
            return build_id;
        else if (transition_char == '.')
            return stop;
    }
    else if (state == build_num) {
        if (isdigit(transition_char))
            return build_num;
        else if (transition_char == ' ')
            return number;
        else if (transition_char == '\n')
            printf(" - Number\n");
            return stop;
    }
    else if (state == build_id) {
        if (isalpha(transition_char) || isdigit(transition_char) || transition_char == '_')
            return build_id;
        else if (transition_char == ' ')
            return identifier;
        else if (transition_char == '\n')
            printf(" - Identifier\n");
            return stop;
    }

    return state;

}