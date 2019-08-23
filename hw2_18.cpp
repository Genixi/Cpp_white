#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	int Q;
	string stop;
	set<string> rout;
	map<set<string>, int> m;
	cin >> Q;

	for(int i = 0; i < Q; ++i) {
		rout.clear();
		int N;
		bool in = false;//маршрута нет

		cin >> N;
		for(int j = 0; j < N; ++j) {
			cin >> stop;
			rout.insert(stop);
		}

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
