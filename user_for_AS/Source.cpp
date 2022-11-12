#include <iostream>
#include "Oper.h"
#include "User.h"
#include "Citys.h"

using namespace std;
void OutCity() {};
void InCity() {};
void OutInCity() {};
void Booking() {};

int main() {
	flight f;
	city c;
	ticket t;
	int n;
	do {
		cout << "You can chose: " << endl;
		cout << "1 - Out city and date / timerange " << endl;
		cout << "2 - In city and date / timerange" << endl;
		cout << "3 - Out & In city and date / timerange" << endl;
		cout << "4 - Booking ticket" << endl;
		cout << "0 - exit" << endl;
		cout << ">>>>";
		cin >> n;
		switch (n) {
		case 1:
			OutCity();
			break;
		case 2:
			InCity();
			break;
		case 3:
			OutInCity();
			break;
		case 4:
			Booking();
		}
	} while (n != 0);



	return 0;
}