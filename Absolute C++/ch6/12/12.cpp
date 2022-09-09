#include <iostream>
#include <fstream>

using namespace std;

class BoxOfProduce {
public:
    void setProduce(string, int);
    string getProduce(int);

private:
    string produce[3];

};

void showProduce(BoxOfProduce&);
void changeProduce(BoxOfProduce&, string produceList[5]);

int main(void) {

    srand(time(NULL));

    int i;
    char inputChar;

    fstream inputStream;
    BoxOfProduce box;
    string produceList[5];

    inputStream.open("produceList.txt");
    for(i = 0;i < 5;i++)
        inputStream >> produceList[i];
    inputStream.close();

    for(i = 0;i < 3;i++)
        box.setProduce(produceList[rand()%5], i);

    cout << "[PRODUCE LIST]" << endl;
    for(i = 0;i < 5;i++)
        cout << i + 1 << ". " << produceList[i] << endl;
    cout << endl;

    do {

        showProduce(box);
        cout << "Change the produce in box?[y/n] > ";
        cin >> inputChar;
        if(inputChar == 'y')
            changeProduce(box, produceList);
        else
            break;

    } while(true);

    cout << endl << "The box is delivered, please check the produce in box..." << endl;
    showProduce(box);

    system("pause");
    return 0;

}

void BoxOfProduce::setProduce(string input_produce, int index) {
    produce[index] = input_produce;
}

string BoxOfProduce::getProduce(int index) {
    return produce[index];
}

void showProduce(BoxOfProduce& box) {

    cout << "[PRODUCE IN BOX]" << endl;
    for(int i = 0;i < 3;i++)
        cout << i + 1 << ". " << box.getProduce(i) << endl;
    cout << endl;

}

void changeProduce(BoxOfProduce& box, string produceList[5]) {

    int index, newProduceIndex;

    cout << "Which produce you what to change?[1-3] > ";
    cin >> index;
    cout << "Choose a produce in list to change[1-5] > ";
    cin >> newProduceIndex;

    box.setProduce(produceList[newProduceIndex - 1], index - 1);

}