#include <iostream>
#include <stdlib.h>

using namespace std;

bool is_equal(int*);
bool is_no_same_number(int*);
bool carry(int*);

int main(void) {

    int TOGD[] = {0, 0, 0, 0};

    cout << "TOO + TOO + TOO + TOO = GOOD\n" << "answer:" << endl;

    while(carry(TOGD)) {

        if( is_no_same_number(TOGD) && is_equal(TOGD) )
            cout << "T = " << TOGD[0] << ", " << "O = " << TOGD[1] << ", " << "G = " << TOGD[2] << ", " << "D = " << TOGD[3] << endl;

        TOGD[3] += 1;

    }

    system("pause");
    return 0;

}

bool is_equal(int TOGD[4]) {

    int TOO = 4 * (TOGD[0] * 100 + TOGD[1] * 11);
    int GOOD = TOGD[2] * 1000 + TOGD[1] * 110 + TOGD[3];

    if(TOO == GOOD)
        return true;
    else
        return false;

}

bool is_no_same_number(int TOGD[4]) {

    int i, j;

    for(i = 0;i < 3;i++) {

        for(j = i + 1;j < 4;j++) {

            if(TOGD[i] == TOGD[j])
                return false;

        } 

    }

    return true;

}

bool carry(int TOGD[4]) {

    for(int i = 3;i > 0;i--) {

        if(TOGD[i] == 10) {

            TOGD[i] = 0;
            TOGD[i - 1] += 1;

        }

    }

    if(TOGD[0] != 10)
        return true;
    else
        return false;

}