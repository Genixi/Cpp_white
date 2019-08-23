#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <string>
using namespace std;

//сначала просто если что то случается - то генерируем исклюение
void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		stringstream ss;
		ss << left << " != "<< right;
		throw runtime_error(ss.str()); // вызывает строчку, которая записанна в потоке
	}
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
