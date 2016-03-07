/* Decimal to Binary.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;

const int MAX_BITS = 16;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	bitset<MAX_BITS> binary;
	string snum, sbinary;
	int num, pos;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		binary.reset();						// reset instead of clear for bitset.
		snum.clear();

		getline(ifilestream, snum);
		istringstream isstream(snum);
		isstream >> num;
		//easy conversion to binary.
		binary = num;

		sbinary = binary.to_string();
		pos = 0;
		while(sbinary.at(pos) == '0') {
			sbinary.erase(0,1);	// don't use substr as that generates and returns a NEW string.
		}

		if(first) {
			cout << sbinary;
			first = false;
		}
		else cout << endl << sbinary;
	}


	ifilestream.close();

	return 0;
}