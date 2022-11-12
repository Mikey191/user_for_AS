#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>

class city {
public:
	set<string> name_city;
	city() {
		ifstream is("11.txt");
		string temp_name;
		if (is) {
			while (!is.eof()) {
				is >> temp_name;
				name_city.insert(temp_name);
			}
		}
	}
	~city() {
		save();
	}
	void addCity() {
		string temp;
		cout << "Enter city: ";
		cin >> temp;
		name_city.insert(temp);
		save();
	}
	void editCity() {
		string temp, new_city;
		cout << "Enter city for change: ";
		cin >> temp;
		auto it = name_city.find(temp);
		if (it != name_city.end()) {
			name_city.erase(temp);
			cout << "Enter new City: ";
			cin >> new_city;
			name_city.insert(new_city);
		}
		else cout << "City is not found" << endl;
	}
	void save() {
		ofstream os("11.txt");
		for (auto it = name_city.begin(); it != name_city.end(); ++it) {
			os << *it;
		}
	}
};