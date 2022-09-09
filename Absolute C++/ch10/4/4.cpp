#include <iostream>
#include <string>

using namespace std;

class Subscriber {
public:
    Subscriber(string);
    Subscriber(const Subscriber&);
    Subscriber() { channelList = new string[0]; }
    ~Subscriber();
    void setSubscriber(string);
    void outputSubscriber() const;
    void resetChannels();
    Subscriber& operator=(const Subscriber&);

private:
    void handleChannels();
    string name;
    int numChannels;
    string* channelList;
    int size;

};

int main(void) {

    string input_name;

    cout << "Enter name > ";
    cin >> input_name;
    cout << "Enter the subscribed channel (-q to end) > ";
    Subscriber Object_A(input_name);
    cout << endl << "[Generating Object_A...]" << endl << endl;
    Object_A.outputSubscriber();
    cout << endl << "[Generating Object_B automatically...]" << endl;
    Subscriber Object_B;
    cout << endl << "[Letting Object_B equal to Object_A...]" << endl;
    Object_B = Object_A;
    cout << endl << "[Resetting the channels of Object_A...]" << endl;
    Object_A.resetChannels();
    cout << endl << "[Showing Object_A and Object_B...]" << endl << endl;
    cout << "Object_A:" << endl;
    Object_A.outputSubscriber();
    cout << endl << "Object_B:" << endl;
    Object_B.outputSubscriber();
    cout << endl << "The result show the it is deep copy." << endl;

    system("pause");
    return 0;

}

Subscriber::Subscriber(string name) {

    this->name = name;
    size = 10;
    channelList = new string[10];
    handleChannels();

}

Subscriber::Subscriber(const Subscriber& old_object) {

    name = old_object.name;
    numChannels = old_object.numChannels;
    size = old_object.size;
    channelList = new string[size];

    for(int i = 0;i < numChannels;i++)
        *(channelList + i) = *(old_object.channelList + i);

}

Subscriber::~Subscriber() {
    delete [] channelList;
    cout << "Hey MotherFucker!" << endl;
}

void Subscriber::setSubscriber(string name) {

    this->name = name;
    resetChannels();
    handleChannels();

}

void Subscriber::outputSubscriber() const {

    cout << "=====[INFO]=====" << endl;
    cout << "Name: " << name << endl;
    cout << "Total subscribed channels: " << numChannels << endl;
    cout << "List of channels:" << endl;
    for(int i = 0;i < numChannels;i++)
        cout << i + 1 << ". " << *(channelList + i) << endl;

}

void Subscriber::resetChannels() {

    numChannels = 0;
    delete [] channelList;
    size = 10;
    channelList = new string[size];

}

Subscriber& Subscriber::operator=(const Subscriber& subscriber) {

    if(this != &subscriber) {

        name = subscriber.name;
        numChannels = subscriber.numChannels;
        size = subscriber.size;

        delete [] channelList;
        channelList = new string[size];

        for(int i = 0;i < numChannels;i++)
            *(channelList + i) = *(subscriber.channelList + i);

    }

    return *this;

}

void Subscriber::handleChannels() {

    string input;

    numChannels = 0;
    while(true) {

        cin >> input;

        if(input == "-q")
            break;

        numChannels++;

        if(numChannels > size) {

            string* temp = new string[size + 10];

            for(int i = 0;i < size;i++)
                *(temp + i) = *(channelList + i);

            size += 10;
            delete [] channelList;
            channelList = temp;

        }

        *(channelList + numChannels - 1) = input;

    }

}