#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
	set<string> s;
	string str;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	cout << s.size();
	return 0;
}
