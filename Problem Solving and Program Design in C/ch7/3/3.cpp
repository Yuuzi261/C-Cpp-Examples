#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");

	int data_num, mass_sum;
	int i;
	int location_x[10], location_y[10], location_z[10], mass[10];
	double C_x, C_y, C_z;

	fscanf(inp, "%d", &data_num);

	for (i = 0;i < data_num;i++)
		fscanf(inp, "%d %d %d %d", &location_x[i], &location_y[i], &location_z[i], &mass[i]);

	/*for (i = 0;i < data_num;i++) {
	
		fprintf(outp, "%d %d %d %d\n", location_x[i], location_y[i], location_z[i], mass[i]);
	
	}*/

	mass_sum = 0;
	for (i = 0;i < data_num;i++)
		mass_sum += mass[i];

	C_x = 0, C_y = 0, C_z = 0;
	for (i = 0;i < data_num;i++) {
	
		C_x += location_x[i] * mass[i];
		C_y += location_y[i] * mass[i];
		C_z += location_z[i] * mass[i];
	
	}

	fprintf(outp, "[%lf, %lf, %lf]", C_x / mass_sum, C_y / mass_sum, C_z / mass_sum);

	fclose(inp);
	fclose(outp);

	system("pause");
	return 0;

}