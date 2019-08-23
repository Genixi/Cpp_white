#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Factorial(int x) {
	if (x < 0) {
		return 1;
	} else if(x == 0) {
		return 1;
	} else {
		int res = 1;
		int count = 1;
		while (count <= x) {
			res *= count;
			count += 1;
		}
		return res;
	}
}

int main() {
	int a;
	cin >> a;
	cout << Factorial(a);
	return 0;
}
