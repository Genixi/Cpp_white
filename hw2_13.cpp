#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void ALL_BUSES (const map<string, vector<string>>& m) {
	if (m.size() == 0) {
		cout << "No buses"<<endl;
	} else {
		for(const auto& i : m) {
			cout << "Bus "<< i.first <<": ";
			for (auto j : i.second) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int Q, num;
	cin >> Q;

	map<string, vector<string>> base_buses;
	map<string, vector<string>> base_stops;
	vector<string> bus_line;

	string comand, str, str_new_bus;

	for (int i = 0; i < Q; ++i) {
		cin >> comand;
		if (comand == "ALL_BUSES") {
			ALL_BUSES(base_buses);
		} else if (comand == "BUSES_FOR_STOP") {
			cin >> str; //str - название остановки
			if (base_stops.count(str) == 0) {
				cout << "No stop"<<endl;
			} else {
				for (auto i : base_stops[str]) {
					cout << i << " ";
				}
				cout<<endl;
			}
		} else if (comand == "STOPS_FOR_BUS") {
			cin >> str; // название баса
			if(base_buses.count(str) == 0) {
				cout << "No bus"<<endl;
			} else {
				//получаем перечень остановок для данного автобуса и перебираем его
				for(auto i : base_buses[str]) {
					//i - Это остановка из списка остановок для баса
					cout << "Stop "<< i<<": ";
					if (base_stops[i].size() == 1 && base_stops[i][0] == str) {
						cout << "no interchange";
					}
					for(auto j : base_stops[i]) {

						if (j != str) {
							cout << j << " ";
						}
					}
					cout << endl;
				}
			}
		} else if (comand == "NEW_BUS") {
			cin >> str_new_bus; //название маршрута
			cin >> num; //количество остановок на маршруте
			vector<string> new_line;

			for (int i = 0; i < num; ++i) {
				cin >> str;
				//формируем вектор остановок
				new_line.push_back(str);
				//добавляем в map с остановками
				if(base_stops.count(str) !=0) {
					base_stops[str].push_back(str_new_bus);
				} else {
					base_stops[str].push_back(str_new_bus);
				}
			}
			base_buses[str_new_bus] = new_line;
		}
	}

	return 0;
}
