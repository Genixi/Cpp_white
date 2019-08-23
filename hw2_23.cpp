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
  string GetFullNameWithHistory(int year) {
	  vector<string> fnSorted;
	  vector<string> snSorted;
	  string fname, sname, ftemp, stemp;

	  if (FirstName.size() > 0) {
		  for(auto i : FirstName) {
			  if (i.first <= year && fnSorted.size() == 0) {
				  fnSorted.push_back(i.second);
			  } else if (i.first <= year && i.second != fnSorted[0]) {
				  fnSorted.insert(fnSorted.begin(), i.second);
			  }
		  }
	  }

	  if (SecondName.size() > 0) {
		  for(auto i : SecondName) {
			  if (i.first <= year && snSorted.size() == 0) {
				  snSorted.push_back(i.second);
			  } else if (i.first <= year && i.second != snSorted[0]) {
				  snSorted.insert(snSorted.begin(), i.second);
			  }
		  }
	  }

	  if (fnSorted.size() == 0) {
		  fname = "none";
	  } else if(fnSorted.size() == 1) {
		  fname = fnSorted[0];
	  } else {
		  fname = fnSorted[0];
		  for (int i = 1; i < fnSorted.size()-1; ++i) {
			  ftemp += fnSorted[i] + ", ";
		  }
		  ftemp +=fnSorted[fnSorted.size() - 1];
		  fname += " (" + ftemp + ")";
	  }

	  if (snSorted.size() == 0) {
		  sname = "none";
	  } else if(snSorted.size() == 1) {
		  sname = snSorted[0];
	  } else {
		  sname = snSorted[0];
		  for (int i = 1; i < snSorted.size()-1; ++i) {
			  stemp += snSorted[i] + ", ";
		  }
		  stemp += snSorted[snSorted.size() - 1];
		  sname += " (" + stemp + ")";
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

