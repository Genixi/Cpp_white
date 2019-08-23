#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrom(string word) {
	int l = word.size();
	for (int i=0; i < l; ++i) {
		if (word[i] != word[l - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	string a;
	cin >> a;
	cout << isPalindrom(a);
	return 0;
}