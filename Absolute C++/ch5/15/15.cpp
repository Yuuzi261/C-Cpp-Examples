#include <iostream>
#include <ctime>

using namespace std;

int rand_int();
void convert_origin_pin(int*, int*, int*);
bool compare(int*, int*);

int main(void) {

    srand(time(NULL));

    int i = 0;
    int pin[5] = {1, 2, 3, 4, 5}, num[10], input[5], convert_pin[5];
    char digit;

    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;

    cout << "NUM: ";

    for(i = 0;i < 10;i++) {

        num[i] = rand_int();
        cout << num[i] << ' ';

    }
    cout << endl;

    convert_origin_pin(pin, num, convert_pin);

    do {

        cout << "Enter the password > ";

        i = 0;
        do{

            digit = cin.get();
            if(isdigit(digit)) {
                input[i] = (int)digit - 48;
                i++;
            }

        } while(digit != '\n');

        if(compare(input, convert_pin)) {
            cout << "Login Successfully." << endl;
            break;
        }
        else
            cout << "ERROR." << endl;

        cout << endl;

    } while(true);

    system("pause");
    return 0;

}

int rand_int() {

    return rand() % 3 + 1;

}

void convert_origin_pin(int pin[], int num[], int convert_pin[]) {

    for(int i = 0;i < 5;i++)
        convert_pin[i] = num[pin[i]];

}

bool compare(int input[], int convert_pin[]) {

    for(int i = 0;i < 5;i++) {

        if(input[i] != convert_pin[i])
            return false;

    }

    return true;

}