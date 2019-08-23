#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> s;
	for(const auto& i : m) {
		s.insert(i.second);
	}
	return s;
}

