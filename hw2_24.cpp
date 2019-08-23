#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString {
	public:
		ReversibleString() {}
		ReversibleString (const string& s) {
			str = s;
		}
		void Reverse() {
			reverse(str.begin(), str.end());
		}
		string ToString() const {
			return str;
		}
	private:
	string str;
};

