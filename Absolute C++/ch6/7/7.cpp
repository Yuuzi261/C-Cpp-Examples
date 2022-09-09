#include <iostream>

using namespace std;

const string type_arr[3] = { "deep dish", "hand tossed", "pan" };
const string size_arr[3] = { "small", "medium", "large" };

enum Size {
	SMALL = 1, MEDIUM, LARGE
};

class Pizza {
public:
	void setType(int);
	void setSize(int);
	void setPepperoni(int);
	void setCheese(int);
	int getType();
	int getSize();
	int getPepperoni();
	int getCheese();
	void outputDescription();
	double computePrice();

private:
	int type;
	int size;
	int pepperoni;
	int cheese;

};

int main(void) {

	int inputType, inputSize, inputToppings;
	Pizza pizza;

	cout << "1) deep dish" << endl << "2) hand tossed" << endl << "3) pan" << endl;
	cout << "Enter the type you want > ";
	cin >> inputType;
	pizza.setType(inputType);

	cout << "1) small" << endl << "2) medium" << endl << "3) large" << endl;
	cout << "Enter the size you want > ";
	cin >> inputSize;
	pizza.setSize(inputSize);

	cout << "Enter the number of pepperoni > ";
	cin >> inputToppings;
	pizza.setPepperoni(inputToppings);

	cout << "Enter the number of cheese > ";
	cin >> inputToppings;
	pizza.setCheese(inputToppings);
	pizza.outputDescription();

	system("pause");
	return 0;

}

void Pizza::setType(int inputType) {
	type = inputType;
}

void Pizza::setSize(int inputSize) {
	size = inputSize;
}

void Pizza::setPepperoni(int inputToppings) {
	pepperoni = inputToppings;
}

void Pizza::setCheese(int inputToppings) {
	cheese = inputToppings;
}

int Pizza::getType() {
	return type;
}

int Pizza::getSize() {
	return size;
}

int Pizza::getPepperoni() {
	return pepperoni;
}

int Pizza::getCheese() {
	return cheese;
}

void Pizza::outputDescription() {

	cout << endl << "[Details]" << endl;
	cout << "Type: " << type_arr[type - 1] << endl;
	cout << "Size: " << size_arr[size - 1] << endl;
	cout << "Toppings..." << endl;
	cout << "Pepperoni: " << pepperoni << endl;
	cout << "Cheese: " << cheese << endl;
	cout << "Total: " << computePrice() << '$' << endl;

}

double Pizza::computePrice() {

	double price;

	switch (size) {
	case SMALL:
		price = 10;
		break;
	case MEDIUM:
		price = 14;
		break;
	case LARGE:
		price = 17;
		break;
	default:
		break;
	}

	return price + 2 * (pepperoni + cheese);

}