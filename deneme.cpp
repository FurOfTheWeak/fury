#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imaginary * other.imaginary,
                             real * other.imaginary + imaginary * other.real);
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }
};

int main() {
    vector<ComplexNumber> complexNumbers;
    complexNumbers.push_back(ComplexNumber(3, 4));
    complexNumbers.push_back(ComplexNumber(1, 2));
    complexNumbers.push_back(ComplexNumber(5, 6));

    cout << "Complex Numbers: ";
    for (const ComplexNumber& number : complexNumbers) {
        cout << number << " ";
    }
    cout << endl;

    sort(complexNumbers.begin(), complexNumbers.end(), [](const ComplexNumber& a, const ComplexNumber& b) {
        return (a.real * a.real + a.imaginary * a.imaginary) < (b.real * b.real + b.imaginary * b.imaginary);
    });

    cout << "Sorted Complex Numbers: ";
    for (const ComplexNumber& number : complexNumbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
