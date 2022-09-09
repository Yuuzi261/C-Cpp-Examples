#include <iostream>

using namespace std;

class Postnet {
public:
    Postnet(int);
    Postnet(string);
    Postnet() {};
    void setBarCode(string);
    void outputZipCode() const;
    void outputBarCode() const;

private:
    int barCode[25];
    int numList[5] = {7, 4, 2, 1, 0};
    void convertStrToBarcode(string);
    void convertIntToBarcode(int);

};

int main(void) {

    int zipCode;
    string barCode;

    cout << "Enter the bar code as a 27-digit number > ";
    cin >> barCode;
    Postnet postnet(barCode);
    cout << "ZIP CODE: ";
    postnet.outputZipCode();
    cout << endl << endl;

    cout << "Enter the zip code as a 5-digit number > ";
    cin >> zipCode;
    postnet = Postnet(zipCode);
    cout << "BAR CODE: ";
    postnet.outputBarCode();
    cout << endl;

    system("pause");
    return 0;

}

Postnet::Postnet(int zipCode) {
    convertIntToBarcode(zipCode);
}

Postnet::Postnet(string barCode) {
    convertStrToBarcode(barCode);
}

void Postnet::setBarCode(string barCode) {
    convertStrToBarcode(barCode);
}

void Postnet::outputZipCode() const {

    int index = 0, digit;

    for(int i = 0;i < 5;i++) {

        digit = 0;
        for(int j = 0; j < 5;j++)
            digit += barCode[index + j] * numList[j];

        if(digit != 11)
            cout << digit;
        else
            cout << 0;

        index += 5;

    }

}

void Postnet::outputBarCode() const {

    cout << 1;
    for(int i = 0;i < 25;i++)
        cout << barCode[i];
    cout << 1;

}

void Postnet::convertStrToBarcode(string barCode) {

    for(int i = 1;i < 26;i++) {
        this->barCode[i-1] = barCode[i] - 48;
    }

}

void Postnet::convertIntToBarcode(int zipcode) {

    int index, amountOf1;
    int zipcode_separation[5];

    for(int i = 4;i >= 0;i--) {

        if(zipcode % 10 != 0)
            zipcode_separation[i] = zipcode % 10;
        else
            zipcode_separation[i] = 11;
        zipcode /= 10;

    }

    for(int i = 0;i < 25;i++)
        barCode[i] = -1;

    index = 0;
    for(int i = 0;i < 5;i++) {

        amountOf1 = 0;
        for(int j = 0;j < 5;j++) {

            if(zipcode_separation[i] >= numList[j] && zipcode_separation[i] != 0) {

                barCode[index + j] = 1;
                zipcode_separation[i] -= numList[j];
                amountOf1++;

            }
            else
                barCode[index + j] = 0;

        }

        if(amountOf1 != 2)
            barCode[index + 4] = 1;

        index += 5;

    }

}