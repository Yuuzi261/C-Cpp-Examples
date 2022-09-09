#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {

    int word_len;
    bool isFirst = true;
    string str;

    while(true){

        cout << "Enter the a sentense (enter -q to quit) > ";

        getline(cin, str);

        if(str == "-q")
            break;

        word_len = 0;
        for(int i = 0;i < str.length();i++) {
            
            if(isalpha(str[i]))
                word_len++;
            else {

                if(word_len == 4 && isFirst == true)
                    str = str.replace(i - 4, 4, "Love");
                else if(word_len == 4)
                    str = str.replace(i - 4, 4, "love");

                isFirst = false;
                word_len = 0;

            }

        }

        cout << str << endl;

    }

        

    system("PAUSE");
    return 0;

}