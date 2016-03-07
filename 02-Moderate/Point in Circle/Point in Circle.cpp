/* Point in Circle.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> store_numbers(const string &pt);

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	string s_center, s_radius, s_point;
	vector<double> center, radius, point;
	double distance;
	bool first = true;

	while(ifs.peek() != EOF) {
		//retrieve strings
		getline(ifs, s_center, ';');
		getline(ifs, s_radius, ';');
		getline(ifs, s_point);

		//retrieve numeric data and store in vectors

		//for center and point:
		center = store_numbers(s_center);
		point = store_numbers(s_point);
		radius = store_numbers(s_radius);
		
		distance = sqrt(pow(point.at(0) - center.at(0), 2) + pow(point.at(1) - center.at(1), 2));
		if(distance > radius.at(0)) {
			if(first) {
				first = false;
				cout << "false";
			}
			else cout << endl << "false";
		}
		else if(first) {
			first = false;
			cout << "true";
		}
		else cout << endl << "true";
 
	}

	ifs.close();

	return 0;
}

vector<double> store_numbers(const string &pt) {
	string s_number;
	int number;
	vector<double> number_pair;

	s_number.clear();

	for(int i = 0; i < pt.size(); i++) {
		if(isdigit(pt.at(i)) || pt.at(i) == '.' || pt.at(i) == '-') {
			s_number += pt.at(i);
		}
		else if(!s_number.empty()) {
			istringstream iss(s_number);
			iss >> number;
			number_pair.push_back(number);
			s_number.clear();
		}
	}
	//in case the string ends on a wanted value.
	if(!s_number.empty()) {
		istringstream iss(s_number);
		iss >> number;
		number_pair.push_back(number);
		s_number.clear();
	}

	return number_pair;
}