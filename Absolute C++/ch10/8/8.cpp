#include <iostream>
#include <string>

using namespace std;

class Television {
public:
    Television() { connectivitySupport = new string[0]; }
    Television(string, double, int, string*);
    Television(const Television&);
    ~Television() { delete [] connectivitySupport; }
    void setDisplayType(string type) { displayType = type; }
    void setDimension(double dimension) { this->dimension = dimension; }
    void setConnectivitySupport(int, string*);
    string getDisplayType() const { return displayType; }
    double getDimension() const { return dimension; }
    int getSize() const { return size; }
    string* getConnectivitySupport() const { return connectivitySupport; }
    Television& operator=(const Television&);

private:
    string displayType;
    double dimension;
    int size;
    string* connectivitySupport;

};

int setStringArray(string**);
void CustomizeTelevision(Television**, int);

int main(void) {

    int size, amountOfTV;
    double dimension;
    char isContinue;
    string displayType;
    string* temp_input = new string[0];

    cout << "Enter the default type of TV > ";
    cin >> displayType;
    cout << "Enter the default dimension of TV > ";
    cin >> dimension;
    cout << "Enter the default connectivity support of TV (-q to end)" << endl << "> ";
    size = setStringArray(&temp_input);

    Television defaultTV(displayType, dimension, size, temp_input);

    cout << "Enter total amounts of the television > ";
    cin >> amountOfTV;

    Television* TVarray = new Television[amountOfTV];

    for(int i = 0;i < amountOfTV;i++)
        TVarray[i] = defaultTV;

    cout << endl << "[CREATE SUCCESSFULLY]" << endl << endl;
    cout << "Customize any of them? {y/n} > ";
    cin >> isContinue;

    while(isContinue == 'y' || isContinue == 'Y') {

        CustomizeTelevision(&TVarray, amountOfTV);
        cout << "Continue customizing? {y/n} > ";
        cin >> isContinue;

    }

    cout << endl << "[LIST OF TELEVISION]" << endl << endl;
    for(int i = 0;i < amountOfTV;i++) {

        cout << "[TV " << i << "]" << endl;
        cout << "Type: " << TVarray[i].getDisplayType() << endl;
        cout << "Dimension: " << TVarray[i].getDimension() << endl;
        cout << "Support Connectivity: " << endl;
        for(int j = 0;j < TVarray[i].getSize();j++)
            cout << j + 1 << ". " << TVarray[i].getConnectivitySupport()[j] << endl;
        cout << endl;

    }

    system("pause");
    return 0;

}

int setStringArray(string** strPtr) {

    int size = 10, elements = 0;
    string temp_input;

    delete [] *strPtr;
    *strPtr = new string[size];

    while(true) {

        cin >> temp_input;

        if(temp_input == "-q")
            break;

        if(elements == size) {

            size += 10;
            string* tempPtr = new string[size];

            for(int i = 0;i < elements;i++)
                *(tempPtr + i) = *(*strPtr + i);

            delete [] *strPtr;
            *strPtr = tempPtr;

        }

        *(*strPtr + elements) = temp_input;
        elements++;

    }

    return elements;

}

void CustomizeTelevision(Television** TVarray, int amountOfTV) {

    int index;
    string modeChooser;

    cout << "Which television do you want to customize? index[0-" << amountOfTV - 1 << "]." << endl << "> ";
    cin >> index;

    do {

        cout << "Which attribute do you want th change?" << endl << "-t: displayType, -d: dimension, -c: connectivity support, -q: leave editer" << endl << "> ";
        cin >> modeChooser;

        if(modeChooser == "-t") {
            string displayType;
            cout << "Enter the type of TV " << index << " > ";
            cin >> displayType;
            (*TVarray)[index].setDisplayType(displayType);
        }
        else if(modeChooser == "-d") {
            double dimension;
            cout << "Enter the dimension of TV " << index << " > ";
            cin >> dimension;
            (*TVarray)[index].setDimension(dimension);
        }
        else if(modeChooser == "-c") {
            int size;
            string* temp_input = new string[0];
            cout << "Enter the default connectivity support of TV (-q to end)" << endl << "> ";
            size = setStringArray(&temp_input);
            (*TVarray)[index].setConnectivitySupport(size, temp_input);
        }
        else if(modeChooser == "-q")
            break;
        else
            cout << "[UNKNOWN COMMAND]" << endl;

    } while(modeChooser != "-q");

}

Television::Television(string displayType, double dimension, int size, string* connectivitySupport) {

    this->connectivitySupport = new string[0];
    setDisplayType(displayType);
    setDimension(dimension);
    setConnectivitySupport(size, connectivitySupport);

}

Television::Television(const Television& origin) {

    this->connectivitySupport = new string[0];
    setDisplayType(origin.displayType);
    setDimension(origin.dimension);
    setConnectivitySupport(origin.size, origin.connectivitySupport);

}

void Television::setConnectivitySupport(int size, string* list) {

    delete [] connectivitySupport;

    this->size = size;
    connectivitySupport = new string[size];

    for(int i = 0;i < size;i++)
        *(connectivitySupport + i) = *(list + i);

}

Television& Television::operator=(const Television& origin) {

    if(this != &origin) {

        setDisplayType(origin.displayType);
        setDimension(origin.dimension);
        setConnectivitySupport(origin.size, origin.connectivitySupport);

    }

    return *this;

}