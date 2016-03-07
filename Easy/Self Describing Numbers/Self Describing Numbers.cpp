/* Self Describing Numbers.cpp
 *
 * TIL: Remember what is a char number and what is the equivalent number number.
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ASCII_CONV = 48;
const int MAX_DIGITS = 10;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	int digit[MAX_DIGITS];
	string number;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {

		for(int k = 0; k < MAX_DIGITS; k++) {			// way of clearing arrays.
			digit[k] = 0;
		}

		getline(ifilestream, number);

		for(int i = 0; i < number.size(); i++) {		
			digit[number.at(i) - ASCII_CONV]++ ; 		// OMG.. it was because I needed to convert the ascii number to its actual number. It went out of bounds and nothing happened.
		}

		for(int j = 0; j < number.size(); j++) {
			if((number.at(j) - ASCII_CONV) != digit[j]) {
				if(first) {
					cout << '0';
					first = false;
				} else cout << endl << '0';
				break;
			}
			else if(j == number.size() - 1) {
					if(first) {
						cout << '1';
						first = false;
		    	 	} else cout << endl << '1';
			} 
		}
	}
	ifilestream.close();

	return 0;
}