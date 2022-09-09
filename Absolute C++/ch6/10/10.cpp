#include <iostream>

using namespace std;

class Weight{
public:
    void setWeightPounds(double);
    void setWeightKilograms(double);
    void setWeightOunces(double);
    double getWeightPounds();
    double getWeightKilograms();
    double getWeightOunces();

private:
    double weight;

};

int main(void) {

    Weight weight;
    double input_weight;

    cout << "CLASS TEST START..." << endl << endl;

    cout << "Enter the weight in pounds > ";
    cin >> input_weight;
    weight.setWeightPounds(input_weight);
    cout << "Kilograms: " << weight.getWeightKilograms() << endl;
    cout << "Ounces: " << weight.getWeightOunces() << endl << endl;

    cout << "Enter the weight in kilograms > ";
    cin >> input_weight;
    weight.setWeightKilograms(input_weight);
    cout << "Pounds: " << weight.getWeightPounds() << endl;
    cout << "Ounces: " << weight.getWeightOunces() << endl << endl;

    cout << "Enter the weight in ounces > ";
    cin >> input_weight;
    weight.setWeightOunces(input_weight);
    cout << "Pounds: " << weight.getWeightPounds() << endl;
    cout << "Kilograms: " << weight.getWeightKilograms() << endl << endl;

    system("pause");
    return 0;

}

void Weight::setWeightPounds(double pounds) {
    weight = pounds;
}

void Weight::setWeightKilograms(double kilograms) {
    weight = kilograms * 2.21;
}

void Weight::setWeightOunces(double ounces) {
    weight = ounces / 16;
}

double Weight::getWeightPounds() {
    return weight;
}

double Weight::getWeightKilograms() {
    return weight / 2.21;
}

double Weight::getWeightOunces() {
    return weight * 16;
}