/* Armstrong Numbers.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

const int ASCII_CONV = 48;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snum;
	int sum, compare;
	bool first = true;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		sum = 0;
		getline(ifilestream, snum);
		for(int i = 0; i < snum.size(); i++) {
			sum += pow(snum.at(i) - ASCII_CONV, snum.size());
		}
		istringstream isstream;
		isstream.str(snum);
		isstream >> compare;
		if(sum == compare) {
			if(first) {
				cout << "True";
				first = false;
			} else cout << endl << "True";
		} else if(first) {
					cout << "False";
					first = false;
			   } else cout << endl << "False"; 
		
	}

	return 0;
}