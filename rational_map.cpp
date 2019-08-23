#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <vector>
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

bool operator<(const Rational& a, const Rational& b) {
    return (a.Numerator()*b.Denominator() < b.Numerator() * a.Denominator());
}

// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}

