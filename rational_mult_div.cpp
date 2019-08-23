#include <iostream>
#include <math.h>
using namespace std;

class Rational {
public:
    Rational() {
        top = 0;
        bottom = 1;
    }

    Rational(int numerator, int denominator) {
        int a = abs(numerator);
        int b = abs(denominator);
        int nod;
        while (a != 0 and b != 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        nod = a + b;
        if (numerator > 0 && denominator > 0) {
            top = numerator / nod;
            bottom = denominator / nod;
        } else if (numerator < 0 && denominator < 0) {
            top = -numerator / nod;
            bottom = -denominator / nod;
        } else if (numerator < 0) {
            top = numerator / nod;
            bottom = denominator / nod;
        } else if (numerator == 0) {
            top = 0;
            bottom = 1;
        } else {
            top = - numerator / nod;
            bottom = - denominator / nod;
        }

    }

    int Numerator() const {
        return top;
    }

    int Denominator() const {
        return bottom;
    }

private:
    int top;
    int bottom;
};

bool operator==(const Rational& a, const Rational& b) {
    return (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator());
}

Rational operator*(const Rational& a, const Rational& b) {
    int top, bottom;
    top = a.Numerator() * b.Numerator();
    bottom = a.Denominator() * b.Denominator();
    return Rational(top, bottom);
}

Rational operator/(const Rational& a, const Rational& b) {
    if (a.Numerator() == 0) {
        return Rational(0, 1);
    } else {
    int top, bottom;
    top = a.Numerator() * b.Denominator();
    bottom = a.Denominator() * b.Numerator();
    return Rational(top, bottom);
    }
}

// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational операторы * и /
int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}

