#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

class Date {
public:
	Date(int a = 0, int b = 0, int c = 0) {
		year = a;
		month = b;
		day = c;
	}
	void printdate() const {
		cout << year << '-' << month << '-' << day;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year;
	int month;
	int day;
};

bool CheckDate(const string& date_str) {
	stringstream stream(date_str);
	int year, month, day;

//	char def1, def2;
//	stream >> year >> def1 >> month >> def2;
//	if (def1 == '-' && def2 == '-' && stream.peek() == EOF) {
//		cout << "Wrong date format: " << date_str << endl;
//		return false;
//	}
	try {
		stream >> year;
		if (stream.peek() == '-') {
			stream.ignore(1);
		} else {
			cout << "Wrong date format: " << date_str << endl;
			return false;
		}
		stream >> month;
		if (stream.peek() == '-') {
			stream.ignore(1);
		} else {
			cout << "Wrong date format: " << date_str << endl;
			return false;
		}
		if (stream.peek() != EOF) {
			stream >> day;
			if(!stream) {
				cout << "Wrong date format: " << date_str << endl;
				return false;
			}
			if(stream.peek() != EOF) {
				cout << "Wrong date format: " << date_str << endl;
				return false;
			}
		} else {
			cout << "Wrong date format: " << date_str << endl;
			return false;
		}
//		if (stream.peek() != EOF) {
//			cout << "Wrong date format: " << date_str << endl;
//			return false;
//		}

		if (month < 1 || month > 12) {
			cout << "Month value is invalid: " << month << endl;
			return false;
		}
		if (day < 1 || day > 31) {
			cout << "Day value is invalid: " << day << endl;
			return false;
		}
		return true;
	} catch (exception& ex) {
		cout << "Wrong date format: " << date_str << endl;
		return false;
	}
}

Date ParseDate(const string& date_str) {
	stringstream stream(date_str);
	int year, month, day;
	stream >> year;
	stream.ignore(1);
	stream >> month;
	stream.ignore(1);
	stream >> day;
	Date date(year, month, day);
	return date;
}

bool operator<(const Date& a, const Date& b) {
	if (a.GetYear() != b.GetYear()){
		return a.GetYear() < b.GetYear();
	} else if (a.GetMonth() != b.GetMonth()) {
		return a.GetMonth() < b.GetMonth();
	} else {
		return a.GetDay() < b.GetDay();
	}
}

void PrintVecWithDate (const Date& date, vector<string> vec) {
	sort(vec.begin(), vec.end());
	for (auto i : vec) {
		cout << setfill('0');
		cout <<setw(4)<<date.GetYear()<<'-'<<setw(2)<<date.GetMonth()<<'-'<<setw(2)<<date.GetDay();
		cout <<' ' << i << endl;
	}
}

class Database{
public:

	void AddEvent(const Date& date, const string& event) {
		if(find(database[date].begin(), database[date].end(), event) == database[date].end()) {
			database[date].push_back(event);
		}
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if(database.count(date) > 0) {
			for (int i=0; i < database[date].size(); i++) {
				if(database[date][i] == event) {
					database[date].erase(database[date].begin() + i);
					return true;
				}
			}
		}
		return false;
	}

	int  DeleteDate(const Date& date) {
		int N;
		N = database[date].size();
		database.erase(date);
		return N;
	}

	vector<string> Find(const Date& date) const {
		vector<string> s;
		if(database.count(date)>0) {
			s = database.at(date);
		}
		return s;
	}

	void Print() const {
		for (auto item : database) {
			PrintVecWithDate(item.first, item.second);
		}
	}

private:
	map<Date, vector<string>> database;
};

int main() {
	Database db;
	string command, todo;
	while(getline(cin, command)) {
		stringstream stream;
		stream.str(command);

		if (command == "") {
			continue;
		} else {
			stream >> todo;
		}

		if (todo == "Add") {
			string date_str, event_str;
			stream >> date_str;
			if (CheckDate(date_str)) {
				Date date = ParseDate(date_str);
				stream >> event_str;
				db.AddEvent(date, event_str);
			}
		} else if (todo == "Del") {
			string date_str;
			stream >> date_str;
			if (CheckDate(date_str)) {
				Date date = ParseDate(date_str);
				if(stream.eof()) {
					int N = db.DeleteDate(date);
					cout << "Deleted " << N << " events" << endl;
				} else {
					string event_str;
					stream >> event_str;
					if (db.DeleteEvent(date, event_str)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found\n";
					}
				}
			}
		} else if (todo == "Find") {
			string date_str;
			stream >> date_str;
			if (CheckDate(date_str)) {
				Date date = ParseDate(date_str);
				vector<string> ev = db.Find(date);
				sort(ev.begin(), ev.end());
				for(auto& i : ev) {
					cout << i << endl;
				}
			}
		} else if (todo == "Print") {
			db.Print();
		} else if (todo == "") {
			continue;
		} else {
			cout << "Unknown command: " << todo << endl;
		}
	}
	return 0;
}
