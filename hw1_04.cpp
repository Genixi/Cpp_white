#include <string>
#include <iostream>
using namespace std;


int main() {
	float n, a, b, x, y, total;
	cin >> n>> a>> b>> x>> y;

	if (n > b) {
		total = n * (1 - y/100);
		cout << total;
	}
	if (n > a && n <= b) {
		total = n * (1 - x/100);
		cout << total;
	}
	if (n <= a) {
		total = n;
		cout << total;
	}

	return 0;
}
