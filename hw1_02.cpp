#include <string>
#include <iostream>
#include <cmath>
using namespace std;


int main() {

	double a, b, c;
	cin >> a >> b >> c;


	double d;
	double x1, x2;
	d = b*b - 4*a*c;

	if (d == 0 && a!=0) {
		x1 = (-b / (2*a));
		x2 = x1;
		cout << x1;
	}

	if (d > 0 && a!=0) {
		double temp;
		temp = sqrt(d);
		x1 = (-b + temp) / (2*a);
		x2 = (-b - temp) / (2*a);
		cout << x1 <<" "<< x2;
	}


	if (a == 0 && b!=0) {
		x1 = -c / b;
		cout << x1;
	}

	return 0;
}

