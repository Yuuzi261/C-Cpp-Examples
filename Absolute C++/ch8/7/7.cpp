#include <iostream>

using namespace std;

class PrimeNumber{
public:
    PrimeNumber(int);
    PrimeNumber() { primeNum = 1; }
    void setPrime(int);
    int getPrime() const { return primeNum; }
    PrimeNumber operator ++();
    PrimeNumber operator ++(int);
    PrimeNumber operator --();
    PrimeNumber operator --(int);
    friend istream& operator >>(istream&, PrimeNumber&);
    friend ostream& operator <<(ostream&, const PrimeNumber&);

private:
    bool isPrime(int) const;
    int primeNum;

};

istream& operator >>(istream&, PrimeNumber&);
ostream& operator <<(ostream&, const PrimeNumber&);

int main(void) {

    PrimeNumber prime, temp;

    cout << "Enter a prime number(must >= 2)..." << endl << "If the number is not prime, it will be automatically set to the next smallest prime number." << endl << "> ";
    cin >> prime;
    cout << "Prime: " << prime << endl;
    cout << "Prime++: " << prime++ << endl;
    prime--;
    cout << "++Prime: " << ++prime << endl;
    prime--;
    cout << "Prime--: " << prime-- << endl;
    prime++;
    temp = --prime;
    if(temp.getPrime() == 1)
        cout << "--Prime: There is no prime number less than 2." << endl;
    else
        cout << "--Prime: " << temp << endl;
    

    system("PAUSE");
    return 0;

}

PrimeNumber::PrimeNumber(int number) {

    while(!isPrime(number))
        number--;

    primeNum = number;

}

void PrimeNumber::setPrime(int number) {

    while(!isPrime(number))
        number--;

    primeNum = number;

}

bool PrimeNumber::isPrime(int number) const {

    if(number == 2 || number == 3)
        return true;
    else if(number > 4){

        int remainder = number % 6;

        if(remainder != 1 && remainder != 5)
            return false;

        int nSqrt = (int)floor(sqrt(number));

        for(int i = 5;i <= nSqrt;i++) {
            if(number % i == 0 || number % (i + 2) == 0)
                return false;
        }

        return true;

    }
    else
        return false;

}

PrimeNumber PrimeNumber::operator++() {

    primeNum++;
    while(!isPrime(primeNum))
        primeNum++;

    return PrimeNumber(primeNum);

}

PrimeNumber PrimeNumber::operator++(int) {

    int temp = primeNum;

    primeNum++;
    while(!isPrime(primeNum))
        primeNum++;

    if(temp == 1)
        return PrimeNumber();
    else
        return PrimeNumber(temp);

}

PrimeNumber PrimeNumber::operator--() {

    if(primeNum <= 2) {
        primeNum = 1;
        return PrimeNumber();
    }
    else{
        primeNum--;
        while(!isPrime(primeNum))
            primeNum--;
    }

    return PrimeNumber(primeNum);

}

PrimeNumber PrimeNumber::operator--(int) {

    int temp = primeNum;

    if(temp < 2)
        return PrimeNumber();
    else if(temp == 2) {
        primeNum = 1;
        return PrimeNumber(temp);
    }
    else{
        primeNum--;
        while(!isPrime(primeNum))
            primeNum--; 
    }

    return PrimeNumber(temp);

}

istream& operator >>(istream& inputStream, PrimeNumber& primeNumber) {

    int num;

    do{
        inputStream >> num;
    }while(num < 2);

    primeNumber.setPrime(num);

    return inputStream;

}

ostream& operator <<(ostream& outputStream, const PrimeNumber& primeNumber) {

    outputStream << primeNumber.primeNum;
    
    return outputStream;

}