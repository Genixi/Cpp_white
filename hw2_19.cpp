#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

bool module(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	int N, n;
	cin >> N;
	vector<int> v;
	for(int i=0; i<N; ++i) {
		cin >> n;
		v.push_back(n);
	}

	sort(begin(v), end(v), module);

	for(int i=0; i<N; ++i) {
		cout << v[i]<< " ";
	}

	return 0;
}
