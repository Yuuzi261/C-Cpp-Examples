#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void display_race_data(int race_data[][4]);
void cal_total_votes_and_percentage(int race_data[][4], double votes_and_percentage[][2], int*);
void verify_result(double votes_and_percentage[][2]);

int main(void) {

	int total_votes;
	int i, j;
	int race_data[][4] = { {192, 48, 206, 37},
						   {147, 90, 312, 21}, 
						   {186, 12, 121, 38},
						   {114, 21, 408, 39},
						   {267, 13, 382, 29} };
	double votes_and_percantage[4][2];

    for (i = 0;i < 4;i++) {
        for(j = 0;j < 2;j++)
            votes_and_percantage[i][j] = 0;
    }

	display_race_data(race_data);

	total_votes = 0;
	cal_total_votes_and_percentage(race_data, votes_and_percantage, &total_votes);

    verify_result(votes_and_percantage);

    race_data[3][2] = 108;

    for (i = 0;i < 4;i++) {
        for(j = 0;j < 2;j++)
            votes_and_percantage[i][j] = 0;
    }

    display_race_data(race_data);

	total_votes = 0;
	cal_total_votes_and_percentage(race_data, votes_and_percantage, &total_votes);

    verify_result(votes_and_percantage);

	system("pause");
	return 0;

}

void display_race_data(int race_data[][4]) {

	int i;

	printf("\n%s%16s%16s%16s%16s\n", "Precinct", "Candidate A", "Candidate B", "Candidate C", "Candidate D");
	for (i = 0;i < 80;i++)
		printf("_");
	printf("\n");

	for (i = 0;i < 5;i++)
		printf("\n%4d%16d%16d%16d%16d\n", i + 1, race_data[i][0], race_data[i][1], race_data[i][2], race_data[i][3]);

	printf("\n");

}

void cal_total_votes_and_percentage(int race_data[][4], double votes_and_percentage[][2], int* total_votes) {

	int i, j;
    char alphabet[4] = { 'A', 'B', 'C', 'D' };

	for (i = 0;i < 5;i++) {
		for (j = 0;j < 4;j++) {
			*total_votes += race_data[i][j];
			votes_and_percentage[j][0] += race_data[i][j];
		}
	}

	printf("Total votes cast is %d.\n", *total_votes);

	for (i = 0;i < 4;i++) {
        votes_and_percentage[i][1] = votes_and_percentage[i][0] / *total_votes;
        printf("Candidate %c's votes cast is %d.(%.2lf%%).\n", alphabet[i], (int)votes_and_percentage[i][0],votes_and_percentage[i][1] * 100);
    }

}

void verify_result(double votes_and_percentage[][2]) {

    int i, j;
    int max_index, int_temp;
    double max, double_temp;
    char char_temp;
    char alphabet[4] = { 'A', 'B', 'C', 'D' };

    for (i = 0;i < 3;i++) {

        max = votes_and_percentage[i][1];
        max_index = i;

        for (j = i+1;j < 4;j++) {
            if (votes_and_percentage[j][1] > max) {
                max = votes_and_percentage[j][1];
                max_index = j;
            }
        }

        if (max_index != i) {

            int_temp = votes_and_percentage[i][0];
            votes_and_percentage[i][0] = votes_and_percentage[max_index][0];
            votes_and_percentage[max_index][0] = int_temp;

            double_temp = votes_and_percentage[i][1];
            votes_and_percentage[i][1] = votes_and_percentage[max_index][1];
            votes_and_percentage[max_index][1] = double_temp;

            char_temp = alphabet[i];
            alphabet[i] = alphabet[max_index];
            alphabet[max_index] = char_temp;

        }

    }

    if (votes_and_percentage[0][1] > 0.5)
        printf("\nCandidate %c is the winner because he/she get more than 50%% votes cast.\n", alphabet[0]);
    else
        printf("\n1st Candidate %c(%.2lf), 2nd Candidate %c(%.2lf).\n", alphabet[0], votes_and_percentage[0][1], alphabet[1], votes_and_percentage[1][1]);

}