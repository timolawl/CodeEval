/* Sum of Digits.cpp
 *
 *
 *  - Don't bother with the stream itself as while, it is not consistent. Use stream.peek() != EOF or string::npos.
 *  - If you want to stream a single character, just use .get().
 *	- If you need to convert a character number to its actual integer number representation, just subtract 48.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int ASCII_CONV = 48;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
//	istringstream isstream;
	string snumber;
	int digit, number;
	bool first = true;

	ifilestream.open(argv[1]);

	while(ifilestream.peek() != EOF) { 									
		number = 0;
		digit = 0;
		getline(ifilestream, snumber);
		istringstream isstream(snumber);
		while(isstream.peek() != string::npos) {
			digit = isstream.get() - ASCII_CONV;						// you can stream a single character like this?
			number += digit;
		}
		if(first) {
			cout << number;
			first = false;
		} else cout << endl << number;
	}

	ifilestream.close();

	return 0;
}