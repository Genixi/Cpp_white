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
            ss << "Invalid argument";
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

Rational operator+(const Rational& a, const Rational& b) {
    int top, bottom;
    top = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
    bottom = a.Denominator() * b.Denominator();
    return Rational(top, bottom);
}

Rational operator-(const Rational& a, const Rational& b) {
    int top, bottom;
    top = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
    bottom = a.Denominator() * b.Denominator();
    return Rational(top, bottom);
}

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
        ss << "Division by zero";
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

Rational ParseData(const string& s) {
    stringstream stream(s);
    Rational r;
    int a, b;
    stream >> a;
    stream.ignore(1);
    stream >> b;

    r = Rational(a, b);
    return r;
}

int main() {
    string str;
    Rational r1, r2, res;
    char operation;
    cin >> str;
    try {
        r1 = ParseData(str);
    } catch (invalid_argument& ig) {
        cout<<ig.what()<<endl;
        return 1;
    }
    cin >> operation;
    cin >> str;
    try {
        r2 = ParseData(str);
    } catch (invalid_argument& ig) {
        cout<<ig.what()<<endl;
        return 1;
    }

    try {
        if (operation == '*') {
            res = r1*r2;
        } else if (operation == '+') {
            res = r1+r2;
        } else if (operation == '/') {
            res = r1/r2;
        } else {
            res = r1-r2;
        }
    } catch (domain_error& er) {
        cout << er.what() << endl;
        return 2;
    }

    cout << res.Numerator()<<"/"<<res.Denominator();
    return 0;
}
