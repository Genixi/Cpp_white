#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


int main() {
	int Q;
	string stop;
	vector<string> rout;
	map<vector<string>, int> m;
	cin >> Q;

	for(int i = 0; i < Q; ++i) {
		rout.clear();
		int N;
		cin >> N;
		for(int j = 0; j < N; ++j) {
			cin >> stop;
			rout.push_back(stop);
		}

		bool in = false;//маршрута нет
		for(const auto& i : m) {
			if (i.first == rout) {
				in = true;
				cout << "Already exists for " << i.second<<endl;
			}
		}
		if (!in) {
			int len = m.size();
			m[rout] = len + 1;
			cout << "New bus "<< len + 1<<endl;
		}
	}

	return 0;
}
