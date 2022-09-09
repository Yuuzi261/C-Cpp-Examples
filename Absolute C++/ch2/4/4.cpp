#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPrimeNumber(int);

int main(void) {

    int i;

    cout << "The prime number in 3 - 100 : " << endl;

    for(i = 3;i < 100;i+=2) {

        if(isPrimeNumber(i))
            cout << i << ' ';

    }

    system("pause");
    return 0;

}

bool isPrimeNumber(int n) {

    int i, maxN = (int)sqrt(n);

    for(i = 3;i <= maxN;i+=2) {

        if(n%i == 0)
            return false;

    }

    return true;

}