#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    sortedStr.push_back(s);
    UpdateStr();
  }
  vector<string> GetSortedStrings() {
    return sortedStr;
  }
private:
  void UpdateStr() {
	  sort(begin(sortedStr), end(sortedStr));
  }
  vector<string> sortedStr;
};

