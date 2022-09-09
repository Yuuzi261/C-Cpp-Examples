#include <iostream>
#include <ctype.h>

using namespace std;

int main(void) {

    int score_list[] = {0, 0, 0, 0, 0, 0};
    char score;

    cout << "Enter the score list > ";

    do {

        score = cin.get();

        if(isdigit(score))
            score_list[(int)score - 48] += 1;

    } while(score != '\n');

    for(int i = 0;i < 6;i++)
        cout << score_list[i] << " grade(s) of " << i << endl;

    system("pause");
    return 0;

}