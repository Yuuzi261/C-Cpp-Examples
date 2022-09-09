#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int blob_check(int graph[5][5], int is_check[5][5], int, int);

int main(void) {

	int graph[5][5] = { {0, 1, 0, 1, 1},
						{1, 0, 0, 0, 1},
						{0, 0, 1, 0, 1},
						{0, 1, 1, 0, 0},
						{1, 1, 0, 0, 0} };
	int is_checked[5][5];
	int i, j, x, y, ans;

	for (i = 0;i < 5;i++)
		for (j = 0;j < 5;j++)
			is_checked[i][j] = 0;
	
    printf("Enter the coordinate of the graph > ");
	scanf("%d %d", &x, &y);

	ans = blob_check(graph, is_checked, x, y);

    if(ans) {

        if(ans != 1)
            printf("There are %d pixels belonging to the object at (%d , %d).\n", ans, x, y);
        else
            printf("There is one pixel belonging to the object at (%d , %d).\n", x, y);

    }
    else
        printf("There is no pixel belonging to the object at (%d , %d)\n", x, y);

	system("pause");
	return 0;

}

int blob_check(int graph[5][5], int is_checked[5][5], int x, int y) {

	if (x < 0 || x > 4 || y < 0 || y > 4)
		return 0;
	else if (graph[y][x] == 0)
		return 0;
	else if (graph[y][x] == 1 && is_checked[y][x] == 0) {
		is_checked[y][x] = 1;
        return 1 + blob_check(graph, is_checked, x, y + 1) + 
		           blob_check(graph, is_checked, x + 1, y + 1) + 
		           blob_check(graph, is_checked, x + 1, y) + 
		           blob_check(graph, is_checked, x + 1, y - 1) + 
		           blob_check(graph, is_checked, x, y - 1) + 
		           blob_check(graph, is_checked, x - 1, y - 1) + 
		           blob_check(graph, is_checked, x - 1, y) + 
		           blob_check(graph, is_checked, x - 1, y + 1);
	}
	else
		return 0;
	
}