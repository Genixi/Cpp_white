#include <string>
#include <iostream>
using namespace std;

int main() {

	string a, b, c;

	cin >> a >> b >> c;

	string min = "min";
	if (a <= b && a <= c) {
		min = a;
	}
	if (b <= a && b <= c) {
		min = b;
	}
	if (c <= a && c <= b) {
		min = c;
	}

	cout << min;

	return 0;
}
