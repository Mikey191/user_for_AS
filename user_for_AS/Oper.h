#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

template <class T>
void getValue(string prompt, T& value)
{
	cout << prompt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... try again" << endl;
		cout << prompt;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);
}
template <>
inline void getValue<string>(string prompt, string& value)
{
	cout << prompt;
	getline(cin, value);
}
template <>
inline void getValue<char>(string prompt, char& value)
{
	cout << prompt;
	cin.getline(&value, 30);
}
template <>
inline void getValue<int>(string prompt, int& value)
{
	cout << prompt;
	cin >> value;
	cin.ignore();
}
template <>
inline void getValue<double>(string prompt, double& value)
{

	cout << prompt;
	cin >> value;
	cin.ignore();

}


struct flight {
	string numFlight;
	string pointSrc;
	string pointDst;
	string dateFlight;
	string timeUp;
	string timeDown;
	string typeAirplane;
	double costTicket;

	int countSeats;
};
class Flight {

	map<string, flight> allFlight;

public:
	Flight() {
		InToFlight();
	}
	~Flight() {
		OutToFile();
	}

	void addFlight() {
		auto it = allFlight.begin();
		flight f;
		bool flag = false;
		do {
			flag = false;
			getValue("enter number of Flight : ", f.numFlight);
			if (allFlight.count(f.numFlight)) {
				flag = true;
			}
		} while (flag);
		getValue("enter Point of Source : ", f.pointSrc);
		getValue("enter Point of Distination : ", f.pointDst);
		getValue("enter Date of Flightn : ", f.dateFlight);
		getValue("enter Time of Up : ", f.timeUp);
		getValue("enter Time of Down : ", f.timeDown);
		getValue("enter Type of Airplane : ", f.typeAirplane);
		getValue("enter Cost of Ticket : ", f.costTicket);
		getValue("enter Count of Seats : ", f.countSeats);

		allFlight[f.numFlight] = f;
	}

	void editFlight() {
		if (!allFlight.empty()) {
			Flight::print();
			cout << endl;

			flight f1;
			string edit_flight, exit;

			cout << "if you changed your mind, if you don't want to change anything, enter - exit" << endl;
			cout << "choose number of Flight which edit and other : " << endl;

			bool flag = 0;
			do {
				getValue("enter number of Flight : ", exit);
				for (auto it = allFlight.begin(); it != allFlight.end(); ++it)
					if (exit == it->first) {
						edit_flight = exit;
						flag = 1;
					}
					else
						cout << "error try again " << endl;
			} while (!flag);

			getValue("if you do not edit flight - enter '0'-zero, \nif you edit flight - enter new flight  : ", f1.numFlight);
			if (f1.numFlight == "0" || (f1.numFlight).empty()) {
				f1.numFlight = allFlight[edit_flight].numFlight;
			}

			getValue("if you do not edit pointSrc - enter 'no', \nif you edit pointSrc - enter new pointSrc  : ", f1.pointSrc);
			if (f1.pointSrc == "0" || (f1.pointSrc).empty()) {
				f1.pointSrc = allFlight[edit_flight].pointSrc;
			}
			getValue("if you do not edit pointDst - enter 'no', \nif you edit pointDst - enter new pointDst  : ", f1.pointDst);
			if (f1.pointDst == "0" || (f1.pointDst).empty()) {
				f1.pointDst = allFlight[edit_flight].pointDst;
			}
			getValue("if you do not edit dateFlight - enter 'no', \nif you edit dateFlight - enter new dateFlight  : ", f1.dateFlight);
			if (f1.dateFlight == "0" || (f1.dateFlight).empty()) {
				f1.dateFlight = allFlight[edit_flight].dateFlight;
			}
			getValue("if you do not edit timeUp - enter 'no', \nif you edit timeUp - enter new timeUp  : ", f1.timeUp);
			if (f1.timeUp == "0" || (f1.timeUp).empty()) {
				f1.timeUp = allFlight[edit_flight].timeUp;
			}
			getValue("if you do not edit timeDown - enter 'no', \nif you edit timeDown - enter new timeDown  : ", f1.timeDown);
			if (f1.timeDown == "0" || (f1.timeDown).empty()) {
				f1.timeDown = allFlight[edit_flight].timeDown;
			}
			getValue("if you do not edit typeAirplane - enter 'no', \nif you edit typeAirplane - enter new typeAirplane  : ", f1.typeAirplane);
			if (f1.typeAirplane == "0" || (f1.typeAirplane).empty()) {
				f1.typeAirplane = allFlight[edit_flight].typeAirplane;
			}
			getValue("if you do not edit costTicket - enter 'no', \nif you edit costTicket - enter new costTicket  : ", f1.costTicket);
			if (f1.costTicket == 0) {
				f1.costTicket = allFlight[edit_flight].costTicket;
			}
			getValue("if you do not edit countSeats - enter 'no', \nif you edit countSeats - enter new countSeats  : ", f1.countSeats);
			if (f1.countSeats == 0) {
				f1.countSeats = allFlight[edit_flight].countSeats;
			}
			allFlight.erase(allFlight.find(edit_flight));
			allFlight[f1.numFlight] = f1;

			cout << endl;
		}
		else {
			cout << "empty" << endl;
		}
	}

	void delFlight() {

		string del_flight;
		Flight::print();
		getValue("select Flight what you want delete : ", del_flight);
		allFlight.erase(del_flight);

	}

	void print() {
		for (auto it = allFlight.begin(); it != allFlight.end(); ++it) {
			cout << it->first << "\t" << (it->second).numFlight << endl << "\t" << (it->second).pointSrc
				<< endl << "\t" << (it->second).pointDst << endl << "\t" << (it->second).dateFlight << endl << "\t" << (it->second).timeUp
				<< endl << "\t" << (it->second).timeDown << endl << "\t" << (it->second).typeAirplane
				<< endl << "\t" << (it->second).costTicket << endl << "\t" << (it->second).countSeats << endl;
		}
	}

	void OutToFile() {
		ofstream ft("1.txt");
		if (!allFlight.empty()) {
			for (auto it = allFlight.begin(); it != allFlight.end(); ++it) {
				ft << it->first << endl;
				ft << (it->second).numFlight << endl;
				ft << (it->second).pointSrc << endl;
				ft << (it->second).pointDst << endl;
				ft << (it->second).dateFlight << endl;
				ft << (it->second).timeUp << endl;
				ft << (it->second).timeDown << endl;
				ft << (it->second).typeAirplane << endl;
				ft << (it->second).costTicket << endl;
				ft << (it->second).countSeats << endl;
			}
		}
		else
			cout << "empty" << endl;
		ft.close();
	}

	void InToFlight() {
		flight* f;
		ifstream ft("1.txt");

		if (ft) {
			while (!ft.eof()) {
				f = new flight;
				flight* ff;
				string x;
				ft >> x;
				if (!x.empty()) {

					ft >> f->numFlight;
					ft >> f->pointSrc;
					ft >> f->pointDst;
					ft >> f->dateFlight;
					ft >> f->timeUp;
					ft >> f->timeDown;
					ft >> f->typeAirplane;
					ft >> f->costTicket;
					ft >> f->countSeats;
					ff = f;
					allFlight[ff->numFlight] = *ff;
				}
			}
		}
		else
			cout << "empty" << endl;
		ft.close();
	}

};