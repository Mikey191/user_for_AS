#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include "Oper.h"
#include "Citys.h"

struct passager {
	string _second_name;
	string _first_name;
	string _date;
};

struct s_ticket {
	//string numFlight;
	//string pointSrc;
	//string pointDst;
	//string dateFlight;
	//string timeUp;
	//string timeDown;
	//string typeAirplane;
	//double costTicket;
	//int countSeats;
	//string _second_name;
	//string _first_name;
	//string _date;
	flight f;
	passager p;
};

class ticket {
public:
	multimap<string, s_ticket> m;
	ticket(){
		ifstream is("12.txt");
		string key;//записываем туда numFlight
		s_ticket st;
		if (is) {
			while (!is.eof()) {
				is >> key;
				st.f.numFlight = key;
				is >> st.f.pointSrc;
				is >> st.f.pointDst;
				is >> st.f.dateFlight;
				is >> st.f.timeUp;
				is >> st.f.timeDown;
				is >> st.f.typeAirplane;
				is >> st.f.costTicket;
				is >> st.f.countSeats;
				is >> st.p._second_name;
				is >> st.p._first_name;
				is >> st.p._date;
				m.insert(make_pair(key, st));
			}
		}
		is.close();
	}
	~ticket(){
		ofstream os("12.txt");
		
		for (auto it = m.begin(); it != m.end(); ++it) {
			os << it->second.f.numFlight;
			os << it->second.f.pointSrc;
			os << it->second.f.pointDst;
			os << it->second.f.dateFlight;
			os << it->second.f.timeUp;
			os << it->second.f.timeDown;
			os << it->second.f.typeAirplane;
			os << it->second.f.costTicket;
			os << it->second.f.countSeats;
			os << it->second.p._second_name;
			os << it->second.p._first_name;
			os << it->second.p._date;
		}
		os.close();
	}
	void OutCity() {

	}
};