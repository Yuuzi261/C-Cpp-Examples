#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void is_divisible_by_9();

int main(void) {

	is_divisible_by_9();	//154368
	is_divisible_by_9();	//621594
	is_divisible_by_9();	//123456

	return 0;
}

void is_divisible_by_9() {

	int sum = 0, i = 0, reverse_num = 0;
	char digit;

	printf("Enter the number > ");
	scanf("%c", &digit);
	printf("The number ");
	while (digit != '\n') {
		printf("%c", digit);
		digit = (int)digit - (int)'0';
		reverse_num += digit * pow(10, i);
		sum += digit;
		i++;
		scanf("%c", &digit);
	}

	if (sum % 9 == 0)
		printf(" CAN divisble by 9.\n");
	else
		printf(" CAN'T divisble by 9.\n");

	printf("The reverse of the number is %d.\n\n", reverse_num);

}