/* Find a Square.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);

	vector<vector<int> > points;
	vector<int> point;
	vector<double> distances;
	map<double, int> lengths;
	string s_input;
	char c_input;
	int point_counter, input;
	bool first = true, equal_sides, equal_diagonals;

	while(ifs.peek() != EOF) {

		if(ifs.peek() == '\n') {
			ifs.ignore(1);
			continue;
		}

		points.clear();
		point.clear();
		distances.clear();
		lengths.clear();

		s_input.clear();
		
		equal_sides = false;
		equal_diagonals = false;

		point_counter = 0;

		//read and store numbers in vector pairs
		while(ifs.peek() != EOF && ifs.peek() != '\n') {
			c_input = ifs.get();
			//upon digit, nothing assigned -> assign the digit
			if(isdigit(c_input)) {
				if(s_input.empty())
					s_input = c_input;
				else s_input += c_input;
			}
			else if(!s_input.empty()) {

				istringstream iss(s_input);
				iss >> input;
				s_input.clear();

				if(point_counter == 0) {
					point.push_back(input);
				}
				else if(point_counter == 1) {
					point.push_back(input);
					points.push_back(point);
					point.clear();
				}

				if(point_counter == 0) {
					point_counter++;
				}
				else if(point_counter == 1) {
					point_counter = 0;
				}
			}
		}
		//each point should have two points to which the same distance are obtained.
		//get distances between each number. there's a total of 6 distances that need to be measured.
		
		distances.push_back(sqrt(pow(points.at(0).at(0) - points.at(1).at(0), 2) + pow(points.at(0).at(1) - points.at(1).at(1), 2)));
		distances.push_back(sqrt(pow(points.at(1).at(0) - points.at(2).at(0), 2) + pow(points.at(1).at(1) - points.at(2).at(1), 2)));
		distances.push_back(sqrt(pow(points.at(2).at(0) - points.at(3).at(0), 2) + pow(points.at(2).at(1) - points.at(3).at(1), 2)));
		distances.push_back(sqrt(pow(points.at(3).at(0) - points.at(0).at(0), 2) + pow(points.at(3).at(1) - points.at(0).at(1), 2)));
		distances.push_back(sqrt(pow(points.at(3).at(0) - points.at(1).at(0), 2) + pow(points.at(3).at(1) - points.at(1).at(1), 2)));
		distances.push_back(sqrt(pow(points.at(0).at(0) - points.at(2).at(0), 2) + pow(points.at(0).at(1) - points.at(2).at(1), 2)));
		
		//of the six, four of them need to be the same length, the other two must be of same length.
		//to compare, do it by percentage of the values - 
		//if these conditions are satisfied then it is a square.
		for(int i = 0; i < distances.size(); i++) {
//			cout << distances.at(i) << endl;
			lengths[distances.at(i)]++;
		}
		
		map<double, int>::iterator it;
		
		for(it = lengths.begin(); it != lengths.end(); it++) {
	//		cout << it->first << " " << it->second << endl;
			if(it->second == 4) {
				equal_sides = true;
			}
			if(it->second == 2) {
				equal_diagonals = true;
			}
		}
		
		if(equal_sides && equal_diagonals) {
			if(first) {
				first = false;
				cout << "true";
			}
			else cout << endl << "true";
		}
		else if(first) {
				first = false;
				cout << "false";
			}
			else cout << endl << "false";

	}

	ifs.close();

	return 0;
}