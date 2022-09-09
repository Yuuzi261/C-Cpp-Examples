#include <iostream>
#include <cmath>

using namespace std;

class Complex{
public:
    Complex(double, double);
    Complex(double);
    Complex();
    void setReal(double real) { this->real = real; }
    void setI(double imaginary) { this->imaginary = imaginary; }
    double getReal() const { return real; }
    double getI() const { return imaginary; }
    friend bool operator ==(const Complex&, const Complex&);
    friend const Complex operator +(const Complex&, const Complex&);
    friend const Complex operator -(const Complex&, const Complex&);
    friend const Complex operator -(const Complex&);
    friend const Complex operator *(const Complex&, const Complex&);
    friend ostream& operator <<(ostream&, const Complex&);
    friend istream& operator >>(istream&, Complex&);

private:
    double real;
    double imaginary;

};

bool operator ==(const Complex&, const Complex&);
const Complex operator +(const Complex&, const Complex&);
const Complex operator -(const Complex&, const Complex&);
const Complex operator -(const Complex&);
const Complex operator *(const Complex&, const Complex&);
ostream& operator <<(ostream&, const Complex&);
istream& operator >>(istream&, Complex&);

int main(void) {

    Complex c1, c2;
    cout << "Enter the first complex number c1 (x y) > ";
    cin >> c1;
    cout << "Enter the second complex number c2 (x y) > ";
    cin >> c2;
    
    if(c1 == c2)
        cout << "c1 and c2 are the same." << endl;
    else
        cout << "c1 and c2 are not the same." << endl;

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c3 = " << c3 << endl;
    c3 = -c1;
    cout << "-c1 = " << c3 << endl;
    c3 = -c2;
    cout << "-c2 = " << c3 << endl;

    system("PAUSE");
    return 0;

}

Complex::Complex(double real, double imaginary) {

    this->real = real;
    this->imaginary = imaginary;

}

Complex::Complex(double realPart) {

    real = realPart;
    imaginary = 0;

}

Complex::Complex() {

    real = 0;
    imaginary = 0;

}

bool operator ==(const Complex& complex1, const Complex& complex2) {

    return ((complex1.real == complex2.real) && (complex1.imaginary == complex2.imaginary));

}

const Complex operator +(const Complex& complex1, const Complex& complex2) {

    double real, imaginary;

    real = complex1.real + complex2.real;
    imaginary = complex1.imaginary + complex2.imaginary;

    return Complex(real, imaginary);

}

const Complex operator -(const Complex& complex1, const Complex& complex2) {

    double real, imaginary;

    real = complex1.real - complex2.real;
    imaginary = complex1.imaginary - complex2.imaginary;

    return Complex(real, imaginary);

}

const Complex operator -(const Complex& complex) {

    double real, imaginary;

    real = -1 * complex.real;
    imaginary = -1 * complex.imaginary;

    return Complex(real, imaginary);

}

const Complex operator *(const Complex& complex1, const Complex& complex2) {

    double real, imaginary;

    real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;

    return Complex(real, imaginary);

}

ostream& operator <<(ostream& outputStream, const Complex& complex) {

    if(complex.imaginary >= 0)
        outputStream << complex.real << " + " << complex.imaginary << 'i';
    else
        outputStream << complex.real << " - " << fabs(complex.imaginary) << 'i';

    return outputStream;

}

istream& operator >>(istream& inputStream, Complex& complex) {

    inputStream >> complex.real >> complex.imaginary;

    return inputStream;
    
}