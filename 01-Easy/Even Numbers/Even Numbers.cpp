/* Even Numbers.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	char c_digit;
	int digit;
	bool first = true;


	while(ifilestream) {
		digit = 0;

		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {

			c_digit = '\0';
			c_digit = ifilestream.get();
		}
		digit = c_digit - '0';

		if(digit % 2 == 0) {
			if(first) {
				first = false;
				cout << "1";
			}
			else cout << endl << "1";
		}
		else {
			if(first) {
				first = false;
				cout << "0";
			}
			else cout << endl << "0";
		}

		ifilestream.ignore(1);
	}

	ifilestream.close();

	return 0;
}