#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int xx;
	int yy;
	int zz;
	int mm;
	char nickname[10];
	int ischeck;
}address_t;

void scan_address(FILE*, address_t*, int*);
void print_address(address_t*, int*);
int local_address(address_t*, address_t*);
void find_local_address(address_t*, const int);

int main(void) {

	int address_len = 0;
	FILE *inp = fopen("input.txt", "r");
	address_t address[100];

	scan_address(inp, address, &address_len);

	print_address(address, &address_len);

	find_local_address(address, address_len);

	system("pause");
	return 0;

}

void scan_address(FILE* inp, address_t address[100], int* address_len) {

	address_t input;

	*address_len = 0;

    fscanf(inp, "%d.%d.%d.%d %s", &input.xx, &input.yy, &input.zz, &input.mm, &input.nickname);

	do {

		input.ischeck = 0;
		address[*address_len] = input;

        *address_len += 1;
		fscanf(inp, "%d.%d.%d.%d %s", &input.xx, &input.yy, &input.zz, &input.mm, &input.nickname);

	} while (input.xx != 0 || input.yy != 0 || input.zz != 0 || input.mm != 0 || strcmp(input.nickname, "none") != 0);

}

void print_address(address_t* address, int* address_len) {

	int i;

	for (i = 0; i < *address_len; i++)
		printf("IP[%d]: %d.%d.%d.%d %s\n", i, address[i].xx, address[i].yy, address[i].zz, address[i].mm, address[i].nickname);

}

int local_address(address_t* a, address_t* b) {

	if(a->xx == b->xx && a->yy == b->yy)
		return 1;
	else
		return 0;

}

void find_local_address(address_t address[100], const int address_len) {

	int i, j, ptr_local_address_len;
	address_t* ptr_local_address[100];

	for(i = 0;i < address_len;i++) {
		
		if(!address[i].ischeck) {

			ptr_local_address[0] = &address[i];
			ptr_local_address_len = 1;
			address[i].ischeck = 1;

			for(j = i + 1;j < address_len;j++) {

				if(local_address(&address[i], &address[j])) {
					ptr_local_address[ptr_local_address_len] = &address[j];
					ptr_local_address_len++;
					address[j].ischeck = 1;
				}

			}

			if(ptr_local_address_len > 1) {

				printf("Same locality:  (%d.%d)\n", ptr_local_address[0]->xx, ptr_local_address[0]->yy);
				for(j = 0;j < ptr_local_address_len;j++)
					printf("%s%5s", ptr_local_address[j]->nickname, "");
				printf("\n");

			}

		}

	}

}