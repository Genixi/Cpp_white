#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <string>
using namespace std;

class Rational {
public:
    Rational() {
        top = 0;
        bottom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            stringstream ss;
            ss << "denominator == 0";
            throw invalid_argument(ss.str());
        }

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
    if (b.Numerator() == 0) {
        stringstream ss;
        ss << "denominator == 0 ";
        throw domain_error(ss.str());
    }
    if (a.Numerator() == 0) {
        return Rational(0, 1);
    } else {
    int top, bottom;
    top = a.Numerator() * b.Denominator();
    bottom = a.Denominator() * b.Numerator();
    return Rational(top, bottom);
    }
}

// Вставьте сюда реализацию operator / для класса Rational

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
