#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int den) {
        int gcd = findGCD(num, den);
        numerator = num / gcd;
        denominator = den / gcd;
    }

    int findGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return findGCD(b, a % b);
    }

    void setNumerator(int a) {
        numerator = a;
    }

    int getNumerator() {
        return numerator;
    }

    void setDenominator(int a) {
        denominator = a;
    }

    int getDenominator() {
        return denominator;
    }

    Rational addRationalNumber(Rational r) {
        int num = numerator * r.denominator + r.numerator * denominator;
        int den = denominator * r.denominator;
        return Rational(num, den);
    }

    Rational multiRationalNumber(Rational r) {
        int num = numerator * r.numerator;
        int den = denominator * r.denominator;
        return Rational(num, den);
    }

    Rational divRationalNumber(Rational r) {
        int num = numerator * r.denominator;
        int den = denominator * r.numerator;
        return Rational(num, den);
    }

    void printRationalNumber() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Rational r1(1, 2);
    Rational r2(2, 3);
    //r3 = addRationalNumber(r1, r2);

    Rational sum = r1.addRationalNumber(r2);
    sum.printRationalNumber();

    Rational product = r1.multiRationalNumber(r2);
    product.printRationalNumber();

    Rational quotient = r1.divRationalNumber(r2);
    quotient.printRationalNumber();

    return 0;
}
