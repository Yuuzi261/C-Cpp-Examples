#include <iostream>
#include <cctype>

using namespace std;

class Sentence {
public:
    Sentence(char*, int);
    Sentence() {};
    ~Sentence();
    void setSentence(char*, int);
    int getHeadWordAmount() const { return headWordAmount; }
    int getNailWordAmount() const { return nailWordAmount; }

private:
    void init(char*, int);
    void countWordAmount(int);
    int headWordAmount;
    int nailWordAmount;
    char* headPtr;
    char* nailPtr;
    char* sentence;

};

int main(void) {

    char input_sentence[10000];

    cout << "Enter a sentence > ";
    cin.getline(input_sentence, 10000);
    Sentence sentence(input_sentence, 10000);

    cout << "Count from head: " << sentence.getHeadWordAmount() << "word(s)." << endl;
    cout << "Count from nail: " << sentence.getNailWordAmount() << "word(s)." << endl;

    if(sentence.getHeadWordAmount() == sentence.getNailWordAmount())
        cout << "The amount of word(s) that counting from head and counting from nail is the same." << endl;
    else
        cout << "The amount of word(s) that counting from head and counting from nail is NOT the same." << endl;

    system("pause");
    return 0;

}

Sentence::Sentence(char* sentence, int length) {
    init(sentence, length);
}

Sentence::~Sentence() {
    delete sentence;
}

void Sentence::init(char* sentence, int length) {

    int i = 0, size = 0;

    this->sentence = new char[length];

    do{

        *(this->sentence + i) = *(sentence + i);
        i++;
        size++;

    } while(*(sentence + i) != '\0');

    headPtr = sentence;
    nailPtr = sentence + i - 1;

    countWordAmount(size);

}

void Sentence::countWordAmount(int size) {

    bool headNowIsWord = false, nailNowIsWord = false;

    headWordAmount = 0, nailWordAmount = 0;

    for(int i = 0;i < size;i++) {

        if(isalpha(*headPtr)) {
            headNowIsWord = true;
        }
        else if(headNowIsWord && *headPtr != '\'' && *headPtr != '-') {
            headWordAmount++;
            headNowIsWord = false;
        }

        if(isalpha(*nailPtr)) {
            nailNowIsWord = true;
        }
        else if(nailNowIsWord && *nailPtr != '\'' && *nailPtr != '-') {
            nailWordAmount++;
            nailNowIsWord = false;
        }

        headPtr++;
        nailPtr--;

    }

    if(headNowIsWord)
        headWordAmount++;
    if(nailNowIsWord)
        nailWordAmount++;

}

void Sentence::setSentence(char* sentence, int length) {
    init(sentence, length);
}