#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void is_divisible_by_9(int);

int main(void) {

	int i, number;

	for(i = 0;i < 3;i++){
		printf("Enter the number > ");
		scanf("%d", &number);
		is_divisible_by_9(number);
	}
	
	return 0;
}

void is_divisible_by_9(int n) {

	int sum = 0, temp;

	temp = n;

	printf("The reverse of number = ");

	while (n != 0) {
		printf("%d", n % 10);
		sum += n % 10;
		n /= 10;
	}

	if (sum % 9 == 0)
		printf("\nThe number %d CAN divisble by 9.\n\n", temp);
	else
		printf("\nThe number %d CAN'T divisble by 9.\n\n", temp);

}