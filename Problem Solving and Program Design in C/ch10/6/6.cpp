#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    
    char language[20];
    int length;
    char list[12][20];

} word_list;

void load_word_list(char[20], word_list*);
void add_word(word_list*, char[20]);
int contains(word_list*, char[20]);
int equal_lists(word_list*, word_list*);
void display_word_list(word_list*);

int main(void) {

    word_list list1, list2;
    char file_name[20], new_word[20];

    printf("Enter the name of input file: ");
    scanf("%s", file_name);

    load_word_list(file_name, &list1);

    printf("Enter the language of second list: ");
    scanf("%s", list2.language);

    list2.length = 0;
    printf("Enter the words to add new word (0 to end the input): \n");
    do {

        scanf("%s", new_word);
        add_word(&list2, new_word);

    } while(strcmp(new_word, "0"));

    printf("Enter the words to search in first list (0 to end the search): \n");
    do {

        scanf("%s", new_word);
        if(contains(&list1, new_word))
            printf("%s was in the first list.\n", new_word);
        else {
            if(strcmp(new_word, "0"))
                printf("%s not found in the first list.\n", new_word);
        }

    } while(strcmp(new_word, "0"));

    if(equal_lists(&list1, &list2))
        printf("The first list and the second list are the same.\n");
    else
        printf("The first list and the second list are NOT the same.\n");

    display_word_list(&list1);
    display_word_list(&list2);

    system("pause");
    return 0;

}

void load_word_list(char file_name[20], word_list* list1) {

    FILE* inp = fopen(file_name, "r");
    int i = 0, input_status;

    fscanf(inp, "%s", list1->language);

    do {

        input_status = fscanf(inp, "%s", list1->list[i]);
        i++;

    } while(input_status != EOF);

    list1->length = i - 1;

}

void add_word(word_list* list2, char new_word[20]) {

    int is_exist = 0;

    if(!strcmp(new_word, "0"))
        return;

    if(list2->length != 12) {

        for(int i = 0;i < list2->length;i++) {
            if(strcmp(list2->list[i], new_word) == 0)
                is_exist = 1;
        }
        if(!is_exist) {
            strcpy(list2->list[list2->length], new_word);
            list2->length++;
        }
        else
            printf("%s is already in the list.\n", new_word);
        
    }
    else
        printf("List full, %s not add.\n", new_word);

}

int contains(word_list* list1, char new_word[20]) {

    int is_exist = 0;

    for(int i = 0;i < list1->length;i++) {
        if(!strcmp(list1->list[i], new_word))
            is_exist = 1;
    }

    if(is_exist)
        return 1;
    else
        return 0;

}

int equal_lists(word_list* list1, word_list* list2) {

    if(strcmp(list1->language, list2->language) || list1->length != list2->length)
        return 0;

    for(int i = 0;i < list2->length;i++) {

        if(!contains(list1, list2->list[i]))
            return 0;

    }

    return 1;

}

void display_word_list(word_list* list) {

    int i;

    printf("======WORDLIST======\n");
    printf("Language: %s\n", list->language);
    printf("List size: %d\n", list->length);
    for(i = 0;i < list->length;i++)
        printf("Word %d: %s\n", i, list->list[i]);

}