#include <iostream>

using namespace std;

class Money {
public:
	int getDollars();
	int getCents();
	void setDollars(int);
	void setCents(int);
	double computeMonetary();

private:
	int dollars;
	int cents;

};

int main(void) {

	cout.setf(ios::fixed);
	cout.precision(1);

	int dollars, cents;
	Money money[2];

	for (int i = 0;i < 2;i++) {

		cout << "Enter dollars > ";
		cin >> dollars;
		money[i].setDollars(dollars);
		cout << "Enter cents > ";
		cin >> cents;
		money[i].setCents(cents);
		cout << "dollars: " << money[i].getDollars() << endl << "cents: " << money[i].getCents() << endl;
		cout << "monetary: " << money[i].computeMonetary() << " dollars" << endl << endl;

	}

	system("pause");
	return 0;

}

int Money::getDollars() {
	return dollars;
}

int Money::getCents() {
	return cents;
}

void Money::setDollars(int inputDollars) {
	dollars = inputDollars;
}

void Money::setCents(int inputCents) {
	cents = inputCents;
}

double Money::computeMonetary() {
	return dollars + 0.1 * cents;
}