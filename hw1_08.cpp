#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v;

	int num, z;

	cin >> num;

	z = num;

	do {
		v.push_back(z%2);
		z = z/2;
	} while (z != 0);

	for (int i = v.size(); i > 0; i--) {
		cout << v[i-1];
	}

	return 0;
}