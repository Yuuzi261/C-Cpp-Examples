#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void) {

	cout.setf(ios::fixed);
	cout.precision(2);

	int floors;
	double baseprice, amenitiesPrice, amenitiesRate, taxes, taxesRate;

	cout << "Floors > ";
	cin >> floors;
	cout << "Base Price > ";
	cin >> baseprice;
	cout << "The rate of amenities(%) > ";
	cin >> amenitiesRate;
	cout << "The rate of taxes(%) > ";
	cin >> taxesRate;

	amenitiesRate /= 100;
	taxesRate /= 100;

	cout << endl;
	for (int i = 0;i < floors;i++) {
	
		amenitiesPrice = baseprice * amenitiesRate;
		taxes = baseprice * (amenitiesRate + 1) * taxesRate;
		cout << "Floor " << i + 1 << " :" << endl;
		cout << "Base Price : " << baseprice << endl;
		cout << "The charges on amenities : " << amenitiesPrice << endl;
		cout << "The taxes : " << taxes << endl;
		cout << "Total cost : " << baseprice + amenitiesPrice + taxes << "\n" << endl;
		baseprice *= 1.02;
	
	}

	system("pause");
	return 0;

}