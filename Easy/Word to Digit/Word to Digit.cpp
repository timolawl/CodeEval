/* Word to Digit.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	vector<string> s_numbers;
	vector<int> whole_number;
	string s_number, line;
	bool first = true;
	map<string, int> convert;

	convert["zero"] = 0;
	convert["one"] = 1;
	convert["two"] = 2;
	convert["three"] = 3;
	convert["four"] = 4;
	convert["five"] = 5;
	convert["six"] = 6;
	convert["seven"] = 7;
	convert["eight"] = 8;
	convert["nine"] = 9;

	while(ifilestream.peek() != EOF) {

	//	while(ifilestream.peek() == '\n')
	//		ifilestream.ignore(1);

		stringstream iss;
		s_numbers.clear();
	//	while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {

	//		cout << "testing";

			s_number.clear();
			getline(ifilestream, line);
			iss << line;
			while(getline(iss, s_number, ';')) {
				s_numbers.push_back(s_number);
			}
	//		iss.clear();
			
	//	}
		whole_number.clear();

		for(int i = 0; i < s_numbers.size(); i++) {
			map<string, int>::iterator it;
			for(it = convert.begin(); it != convert.end(); it++) {
				if(s_numbers.at(i) == it->first) {
					whole_number.push_back(it->second);
				}
			}
		}

		if(first) {
			first = false;
			for(int i = 0; i < whole_number.size(); i++) {
				cout << whole_number.at(i);
			}
		}
		else {
			cout << endl;
			for(int i = 0; i < whole_number.size(); i++) {
				cout << whole_number.at(i);
			}
		}
	}

	ifilestream.close();

	return 0;

}