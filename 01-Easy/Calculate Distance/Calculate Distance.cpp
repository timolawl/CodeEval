/* Calculate Distance.cpp
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

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);

	string s_number, line;
	int number, distance;
	vector<int> point1, point2;
	bool first = true;

	while(ifilestream.peek() != EOF) {
		point1.clear();
		point2.clear();
		number = 0;

		getline(ifilestream, line);
		for(int i = 0; i < line.size(); i++) {
			number = 0;
			if(line.at(i) == ',') {
				istringstream convert(s_number);
				convert >> number;
				s_number.clear();
				if(point1.empty()) {
					point1.push_back(number);
				}
				else point2.push_back(number);
			}
			else if(line.at(i) == ')') {
				istringstream convert(s_number);
				convert >> number;
				s_number.clear();
				if(point1.size() < 2) {
					point1.push_back(number);
				}
				else point2.push_back(number);
			}
			else if(isdigit(line.at(i)) || line.at(i) == '-') {
				s_number += line.at(i);
			}
		}

		distance = sqrt(pow(point1.at(0) - point2.at(0), 2) + pow(point1.at(1) - point2.at(1), 2));

//		cout << point1.at(0) << "," << point1.at(1) << endl;
//		cout << point2.at(0) << "," << point2.at(1) << endl;

		if(first) {
			cout << distance;
			first = false;
		}
		else cout << endl << distance;

	}

	ifilestream.close();


	return 0;
}
