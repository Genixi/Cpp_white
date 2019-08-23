#include <iostream>
#include <math.h>
#include <sstream>
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
            top = numerator / nod;
            bottom = denominator / nod;
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

// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational операторы << и >>

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream<< rational.Numerator() <<'/'<<rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int top;
    int bottom;
    if (stream.tellg() == -1) {
       return stream;
    }
    stream >> top;
    stream.ignore(1);
    stream >> bottom;
    rational = Rational(top, bottom);
    return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }
        
        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
