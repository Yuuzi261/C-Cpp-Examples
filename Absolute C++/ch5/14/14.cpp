#include <iostream>
#include <cmath>

using namespace std;

int find_closest(int database[][6], int*, int*);
bool in_array(int, int*);

int main(void) {

    int closest, i;
    int movie[3] = {0, 0, 0}, rating[3] = {0, 0, 0};
    int database[][6] = {
                            3, 1, 5, 2, 1, 5,
                            4, 2, 1, 4, 2, 4,
                            3, 1, 2, 4, 4, 1,
                            5, 1, 4, 2, 4, 2
                        };

    cout << "Choose three movie to vote (100 - 105) > ";
    for(i = 0;i < 3;i++) {
        cin >> movie[i];
        movie[i]%=100;
    }

    cout << "Enter the rate of each movie (1 - 5) > ";
    for(i = 0;i < 3;i++)
        cin >> rating[i];

    closest = find_closest(database, movie, rating);

    for(i = 0;i <6;i++) {

        if(!(in_array(i, movie)))
            cout << "Predicted rate for movie 10" << i << ": " << database[closest][i] << endl;

    }

    system("pause");
    return 0;

}

int find_closest(int database[][6], int movie[], int rating[]) {

    int closest, i, j;
    double distance, min_distance = 9999;

    for(i = 0;i < 4;i++) {

        distance = 0;
        for(j = 0;j < 3;j++)
            distance += pow(rating[j] - database[i][movie[j]], 2);
        
        distance = sqrt(distance);

        if(distance < min_distance) {

            min_distance = distance;
            closest = i;

        }

    }

    return closest;

}

bool in_array(int element, int array[]) {

    for(int i = 0;i < 3;i++) {

        if(array[i] == element)
            return true;

    }

    return false;

}