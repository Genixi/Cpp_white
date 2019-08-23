#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	//ofstream output("C:\\Users\\Alexey\\Desktop\\CCpp\\YandexCoursera\\output.txt");
	int row=0, col=0;
	input >> row;
	input.ignore(1);
	input >> col;
	input.ignore(1);

	for (int i = 1; i <= row; ++i) {
		int temp = 0;
		for (int j = 1; j < col; ++j) {
			input >> temp;
			input.ignore(1);
			cout << setw(10) << temp << ' ';
		}
		input >> temp;
		input.ignore(1);
		cout << setw(10) << temp;
		if (i != row) {
			cout << endl;
		}
	}

	return 0;
}
