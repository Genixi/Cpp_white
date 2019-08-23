#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int Q;
	string comand, word1, word2;
	map<string, set<string>> dict;
	cin >> Q;

	for(int i = 0; i < Q; ++i) {
		cin >> comand;

		if (comand == "ADD") {
			cin >> word1 >> word2;
			dict[word1].insert(word2);
			dict[word2].insert(word1);

		} else if (comand == "COUNT") {
			cin >> word1;
			int t = dict[word1].size();
			cout<< t <<endl;
		} else if (comand == "CHECK") {
			cin >> word1 >> word2;
			if (dict.count(word1) != 0 && dict[word1].count(word2) != 0) {
				cout << "YES"<<endl;
			} else {
				cout << "NO"<<endl;
			}
		}
	}

	return 0;
}
