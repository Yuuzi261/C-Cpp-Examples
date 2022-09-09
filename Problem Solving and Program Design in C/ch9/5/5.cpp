#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count;

typedef struct {
    int x;
    int y;
} coordinate;


void visit(char[8][8], coordinate*, int, int, int, int*);
void print_array(coordinate*, int);

int main(void) {

    count = 0;
    int isFind = 0;

    char maze[8][8] = {
                        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
                        ' ', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 
                        ' ', ' ', 'X', ' ', 'X', 'X', ' ', ' ', 
                        ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', 
                        ' ', ' ', ' ', ' ', 'X', 'X', ' ', 'X', 
                        'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 
                        ' ', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 
                        ' ', 'X', 'X', ' ', ' ', ' ', ' ', ' '
                      };

    coordinate path[64];

    visit(maze, path, 0, 1, 0, &isFind);

    if(!isFind)
        printf("Path not found.\n");

    system("pause");
    return 0;

}

void visit(char maze[8][8], coordinate path[64], int x, int y, int path_len, int* isFind) {

    if(x < 0 || x > 7 || y < 0 || y > 7 || maze[x][y] == 'X' || maze[x][y] == 'O')
        return;

    maze[x][y] = 'O';

    path[path_len].x = x;
    path[path_len].y = y;
    path_len++;

    if(x == 7 && y == 7) {

        *isFind = 1;

        print_array(path, path_len);

    }
    else{

        visit(maze, path, x - 1, y, path_len, isFind);
        visit(maze, path, x, y + 1, path_len, isFind);
        visit(maze, path, x + 1, y, path_len, isFind);
        visit(maze, path, x, y - 1, path_len, isFind);

    }

    path_len--;

    maze[x][y] = ' ';

}

void print_array(coordinate path[64], int path_len) {

    printf("Path %d:\n", ++count);

    for(int i = 0; i < path_len;i++)
            printf("( %d , %d )\n", path[i].x, path[i].y);

    printf("\n");

}