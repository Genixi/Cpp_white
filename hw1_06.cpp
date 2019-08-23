#include <string>
#include <iostream>
using namespace std;

int main() {
	string str;

	cin >> str;
	int i = 0;
	int total = 0;
	for (auto ch : str) {
		if (ch == 'f') {
			total += 1;
			if (total == 2) {
				cout << i;
				break;
			}
		}
		i++;
	}

	if (total == 0) {
		cout <<-2;
	}
	if (total == 1) {
		cout <<-1;
	}
	
	return 0;
}