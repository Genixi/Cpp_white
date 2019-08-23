#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(string s) {
	map<char, int> m;
	for (auto i : s) {
		++m[i];
	}
	return m;
}

int main() {

	int N;
	string str1, str2;
	map<char, int> m1, m2;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> str1 >> str2;
		m1 = BuildCharCounters(str1);
		m2 = BuildCharCounters(str2);

		if (m1 == m2) {
			cout << "YES"<<endl;
		} else {
			cout << "NO"<<endl;
		}

	}

	return 0;
}