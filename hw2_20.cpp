#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int N;
	string str;
	cin >> N;
	vector<string> v;
	for(int i=0; i<N; ++i) {
		cin >> str;
		v.push_back(str);
	}

	sort(begin(v), end(v), [] (string x, string y) {
		string aLow, bLow;
		for(auto c : x) {
			aLow += tolower(c);
		}
		for(auto c : y) {
				bLow += tolower(c);
		}
		return aLow < bLow;
	});

	for(int i=0; i<N; ++i) {
		cout << v[i]<< " ";
	}

	return 0;
}
