#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i, odd_sum, even_sum, sum;
	int barcodes[12];

	for (i = 0;i < 12;i++)
		scanf("%d", &barcodes[i]);

	odd_sum = 0, even_sum = 0;
	for (i = 0;i < 11;i+=2)
		odd_sum += barcodes[i];

	for (i = 1;i < 11;i += 2)
		even_sum += barcodes[i];

	sum = odd_sum * 3 + even_sum;

	if (sum % 10 == barcodes[11] || 10 - sum % 10 == barcodes[11])
		printf("validated.\n");
	else
		printf("error in barcode.\n");

	printf("The result of steps 1 = %d.\nThe result of steps 2 = %d.\n", odd_sum * 3, sum);

	system("pause");
	return 0;

}