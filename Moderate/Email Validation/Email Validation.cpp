/* Email Validation.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

const string exclude = "!#$%^&*()=+[{]}|/?,<>;:'\"\\";

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	int atsign;
	string test;
	bool first = true, symbol;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {

		getline(ifilestream, test);

		symbol = false;
		atsign = 0;
		for(int i = 0; i < test.size(); i++) {
			if(test.at(i) - '@' == 0)
				atsign++;
		}

		if(atsign == 1 && test.find(".") != string::npos) {
			for(int j = 0; j < test.size(); j++) {
				for(int k = 0; k < exclude.size(); k++) {
					if(test.at(j) == exclude.at(k)) {
						symbol = true;
						break;
					}
				}
				if(symbol) break;
			}
			if(symbol) {
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
		else if(first) {
			first = false;
			cout << "false";
		}
		else if(!test.empty()) {
			cout << endl << "false";
		}
	}

	ifilestream.close();

	return 0;
}