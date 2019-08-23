#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ADD(vector<vector<string>>& schedule, int i, string task) {
	schedule[i].push_back(task);
}

void NEXT(vector<vector<string>>& schedule, int month_number) {
	int next_month_days;
	switch(month_number) {
	case 1:
		next_month_days = 28;
		break;
	case 2:
		next_month_days = 31;
		break;
	case 3:
		next_month_days = 30;
		break;
	case 4:
		next_month_days = 31;
		break;
	case 5:
		next_month_days = 30;
		break;
	case 6:
		next_month_days = 31;
		break;
	case 7:
		next_month_days = 31;
		break;
	case 8:
		next_month_days = 30;
		break;
	case 9:
		next_month_days = 31;
		break;
	case 10:
		next_month_days = 30;
		break;
	case 11:
		next_month_days = 31;
		break;
	case 12:
		next_month_days = 31;
		break;
	default:
		cout<<"Switch error!";
	}

	if(next_month_days > schedule.size()) {
		schedule.resize(31);
	} else if (next_month_days < schedule.size()) {
		vector<string> last_days;
		for (int j = next_month_days; j < schedule.size(); j++){
			schedule[next_month_days - 1].insert(end(schedule[next_month_days - 1]), begin(schedule[j]), end(schedule[j]));
		}
		schedule.resize(next_month_days);
	}
}

void DUMP(vector<vector<string>>& schedule, int num) {
	cout<< schedule[num].size()<< " ";
	for (auto i : schedule[num]) {
		cout<< i << " ";
	}
	cout<<endl;
}

void MonthSchedule() {
	int month_number = 1;
	vector<vector<string>> schedule(31);
	int Q;
	string comand, task;
	int num;

	cin >> Q;
	int i = 0;

	while (i < Q) {
		cin >> comand;
		if (comand == "ADD") {
			cin >> num;
			cin >> task;
		} else if (comand == "DUMP") {
			cin >> num;
		}
		i++;

		if (comand == "ADD") {
			ADD(schedule, num - 1, task);
		} else if (comand == "NEXT") {
			NEXT(schedule, month_number);
			if (month_number == 12) {
				month_number = 1;
			} else {
				month_number++;
			}
		} else if (comand == "DUMP") {
			DUMP(schedule, num - 1);
		}
	}

}


int main() {

	MonthSchedule();

	return 0;
}