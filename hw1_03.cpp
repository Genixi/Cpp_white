#include <string>
#include <iostream>
using namespace std;


int main() {

	int a, b, c;
	cin >> a>> b;

	if (b == 0) {
		cout << "Impossible";
	} else {
		c = a / b;
		cout << c;
	}

	return 0;
}
