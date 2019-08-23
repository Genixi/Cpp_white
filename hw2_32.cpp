#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	string line;
	float num;
	cout << fixed << setprecision(3);
	while(getline(input, line)) {
		num = stof(line);
		cout << num << endl;
	}

	return 0;
}
