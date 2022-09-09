#include <iostream>
#include <stdlib.h>
using namespace std;

double cal_calores(double*, int*, int, int);

int main(void) {

    cout.setf(ios::fixed);
	cout.precision(2);

    int minute = 15, MPH = 4;
    double weight, calores = 0;

    cout << "Enter the weight > ";
    cin >> weight;

    calores += cal_calores(&weight, &minute, 3, MPH);
    while(minute) {

        MPH += 2;
        calores += cal_calores(&weight, &minute, 4, MPH);

    }

    cout << "Total burned : " << calores << " calores" << endl;

    system("pause");
    return 0;

}

double cal_calores(double* weight, int* minute, int time, int MPH) {

    *minute -= time;
    return 0.0175 * (MPH*5/3.0) * (*weight) * (time);

}