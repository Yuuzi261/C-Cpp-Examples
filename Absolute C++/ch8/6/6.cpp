#include <iostream>
#include <vector>

using namespace std;

class MyInteger {
public:
    MyInteger(int);
    MyInteger() {}
    void setNum(int);
    vector<int> getNum() const { return number; }
    int operator [](int);
    friend istream& operator >>(istream&, MyInteger&);

private:
    vector<int> number;

};

istream& operator >>(istream&, MyInteger&);

int main(void) {

    int index = -2;
    MyInteger num(0);

    cout << "Enter a number > ";
    cin >> num;

    while(true) {

        cout << "Enter an index (-1 to end) > ";
        cin >> index;
        
        if(index == -1)
            break;
        else if(num[index] != -1)
            cout << "The index " << index << " of the number is " << num[index] << '.' << endl << endl;
        else
            cout << "index out of range." << endl << endl;

    }

    system("PAUSE");
    return 0;

}

MyInteger::MyInteger(int number) {
    setNum(number);
}

void MyInteger::setNum(int number) {
    
    int capacity =  this->number.capacity();

    while(number != 0) {

        this->number.reserve(capacity++);
        this->number.push_back(number % 10);
        number /= 10;

    }

}

int MyInteger::operator [](int index) {

    if(index >= number.capacity())
        return -1;
    else {
        return  number[index];
    }

}

istream& operator >>(istream& inputStream, MyInteger& num) {

    int number;

    inputStream >> number;
    num.setNum(number);
    
    return inputStream;

}