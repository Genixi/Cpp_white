#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  SecondName[year] = last_name;
  }
  string GetFullName(int year) {
	  string fname = "none", sname = "none";

	  for (auto i : FirstName) {
		  if (i.first <= year) {
			  fname = i.second;
		  }
	  }
	  for (auto j : SecondName) {
		  if (j.first <= year) {
			  sname = j.second;
		  }
	  }

	  if (fname == "none" && sname == "none") {
		  return "Incognito";
	  } else if(fname != "none" && sname != "none") {
		  return fname + " " + sname;
	  } else if(fname != "none") {
		  return fname + " with unknown last name";
	  } else {
		  return sname + " with unknown first name";
	  }
  }
private:
  map <int, string> FirstName;
  map <int, string> SecondName;
};

