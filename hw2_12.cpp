#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void CHANGE_CAPITAL(map<string, string>& m, string country, string new_capital) {
	if (m.count(country) == 0) {
		m[country] = new_capital;
		cout << "Introduce new country "<< country<< " with capital "<< new_capital<<endl;
	} else if (m[country] == new_capital) {
		cout << "Country "<< country<< " hasn't changed its capital"<<endl;
	} else if (m[country] != new_capital) {
		cout <<"Country "<<country<<" has changed its capital from "<<m[country]<<" to "<<new_capital<<endl;
		m[country] = new_capital;
	}
}

void RENAME(map<string, string>& m, string old_country_name, string new_country_name) {
	if (m.count(new_country_name) != 0 || new_country_name == old_country_name || m.count(old_country_name) == 0) {
		cout << "Incorrect rename, skip"<<endl;
	} else {
		cout <<"Country "<<old_country_name<<" with capital "<<m[old_country_name]<<" has been renamed to "<<new_country_name<<endl;
		string temp = m[old_country_name];
		m[new_country_name] = temp;
		m.erase(old_country_name);
	}

}

void ABOUT(map<string, string>& m, string country) {
	if (m.count(country) == 0) {
		cout << "Country "<< country << " doesn't exist"<<endl;
	} else {
		cout << "Country "<< country << " has capital "<< m[country]<<endl;
	}
}

void DUMP(map<string, string>& m) {
	if (m.size() == 0) {
		cout << "There are no countries in the world" << endl;
	} else {
		for(const auto& i : m) {
			cout<< i.first <<"/"<< i.second << " ";
		}
		cout << endl;
	}

}

int main() {

	int Q;
	string comand, str1, str2;
	map<string, string> m;
	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		cin >> comand;
		if (comand == "CHANGE_CAPITAL") {
			cin >> str1 >> str2;
			CHANGE_CAPITAL(m, str1, str2);
		} else if (comand == "RENAME") {
			cin >> str1 >> str2;
			RENAME(m, str1, str2);
		} else if (comand == "ABOUT") {
			cin >> str1;
			ABOUT(m, str1);
		} else if (comand == "DUMP") {
			DUMP(m);
		}
	}

	return 0;
}