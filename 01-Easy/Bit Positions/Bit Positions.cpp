/* Bit Positions.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

const int MAX_BITSIZE = 16;
const int ASCII_CONV = 48;

int main(int argc, char *argv[]) {
	string snum, sp1, sp2;
	int num, p1, p2;
	bool round_one = true;
	bitset<MAX_BITSIZE> bit_form;
	ifstream ifilestream;
	char easyway;

	ifilestream.open(argv[1]);
	
	while(ifilestream.peek() != EOF) {
		num = 0, p1 = 0, p2 = 0, bit_form.reset();
		getline(ifilestream, snum, ',');
		istringstream isstream1(snum);
		isstream1 >> num;

		easyway = num;
		bit_form = easyway;
/*
		for(int i = 0; i < MAX_BITSIZE; i++) {
			if(num - pow(2, (MAX_BITSIZE - i - 1)) >= 0) {
				bit_form[MAX_BITSIZE - i - 1] = 1;
				num -= pow(2, (MAX_BITSIZE - i -1));
			}
		}
*/
		getline(ifilestream, sp1, ',');
		istringstream isstream2(sp1);
		isstream2 >> p1;
		p1 -= 1;							// to take into account that they are asking for absolute position, and not position based on c-style syntax.
		getline(ifilestream, sp2);
		istringstream isstream3(sp2);
		isstream3 >> p2;
		p2 -= 1;
		if(round_one) {
			if(bit_form[p1] == bit_form[p2]) {
				cout << "true";
				round_one = false;
			} else { 
				cout << "false";
				round_one = false;
			}
		} else {
			if(bit_form[p1] == bit_form[p2])
				cout << "\ntrue";
			else cout << "\nfalse";
		}
	}
	ifilestream.close();

	return 0;
}