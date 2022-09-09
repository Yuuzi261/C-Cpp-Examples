#define _CRT_SECURE_NO_WARNINGS
#define FLAT_RATE 7.99
#define ADDITIONAL_RATE 1.99
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void charges(double*, double*, double*);
void round_money(double*, double*);

int main(void) {

	int month, year, customer;
	double hours_used, charge_per_hour, average_cost;

	FILE* inp = fopen("usage.txt", "r");
	FILE* outp = fopen("charges.txt", "w");

	fscanf(inp, "%d %d", &month, &year);
	fprintf(outp, "Charges for %d/%d\n\n\n", month, year);
	fprintf(outp, "%s%8s%s%8s%s%8s%s\n", "Customer", "", "Hours used", "", "Charge per hour", "", "Average cost");

	while (fscanf(inp, "%d %lf", &customer, &hours_used) != EOF) {
		charges(&hours_used, &charge_per_hour, &average_cost);
		round_money(&charge_per_hour, &average_cost);
		fprintf(outp, "%d%18.1lf%21.2lf%21.2lf\n", customer, hours_used, charge_per_hour, average_cost);
	}

	fclose(inp);
	fclose(outp);

	system("pause");
	return 0;

}

void charges(double* ptr_hours_used, double* ptr_charge_per_hours, double* ptr_average_cost) {
	
	if (*ptr_hours_used <= 10)
		*ptr_charge_per_hours = FLAT_RATE;
	else {
		*ptr_charge_per_hours = FLAT_RATE + ADDITIONAL_RATE * (ceil(*ptr_hours_used) - 10);
	}

	*ptr_average_cost = *ptr_charge_per_hours / *ptr_hours_used;

}

void round_money(double* ptr_charge_per_hours, double* ptr_average_cost) {

	*ptr_charge_per_hours = (int)(*ptr_charge_per_hours * 100 + 0.5) / 100.0;
	*ptr_average_cost = (int)(*ptr_average_cost * 100 + 0.5) / 100.0;

}