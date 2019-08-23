#include <iostream>
#include <vector>
using namespace std;

void WORRY(vector<bool>& line, int id) {
	line[id] = true;
}

void QUIET(vector<bool>& line, int id) {
	line[id] = false;
}

void COME(vector<bool>& line, int k) {
	line.resize(line.size()+ k, false);
}

int WORRY_COUNT(vector<bool>& line) {
	int count = 0;
	for (auto el : line) {
		if (el == true) {
			count++;
		}
	}
	return count;
}

int main() {

	vector<bool> line;
	vector<int> count;
	int Q, res_count;
	string comand;
	int num;

	cin >> Q;

	int i = 0;

	while (i < Q) {
		cin >> comand;
		if (comand != "WORRY_COUNT") {
			cin >> num;
		}
		i++;

		if (comand == "WORRY") {
			//cout<<"comand = WORRY" << " "<< "num = "<< num<<endl;
			WORRY(line, num);
		} else if (comand == "QUIET") {
			//cout<<"comand = QUIET" << " "<< "num = "<< num<<endl;
			QUIET(line, num);
		} else if (comand == "COME") {
			//cout<<"comand = COME" << " "<< "num = "<< num<<endl;
			COME(line, num);
		} else if (comand == "WORRY_COUNT") {
			//cout<<"comand = WORRY_COUNT";
			res_count = WORRY_COUNT(line);
			count.push_back(res_count);
		}
	}


	for(int z : count) {
		cout << z<< endl;
	}

	return 0;
}