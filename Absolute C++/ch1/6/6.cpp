#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void) {

	cout.setf(ios::fixed);
	cout.precision(2);

	double distance, time, charge;

	do {
		cout << "Enter the distance and time.  (distance time) > ";
		cin >> distance >> time;
	} while (distance <= 0 || time <= 0);

	charge = 2;

	if (distance > 8)
		charge += 3 + (distance - 8);
	else if(distance > 2)
		charge += (distance - 2) * 0.5;

	charge += time * 0.2;

	cout << "The fare is " << charge << endl;

	system("pause");
	return 0;

}