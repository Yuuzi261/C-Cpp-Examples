#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int vol, mins; //volume to be infused and minutes over which to infused

	printf("Volume to be infused (ml) => ");
	scanf("%d", &vol);
	printf("Minutes over which to infuse => ");
	scanf("%d", &mins);

	printf("VTBI: %d ml\n", vol);
	printf("Rate: %d ml/hr\n", vol * 60 / mins);

	return 0;
}