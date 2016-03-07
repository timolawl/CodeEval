/* Number of Ones.cpp 
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

const int ASCII_CONV = 48;
const int MAX_BITS = 16;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	char character;
	string snum;
	int num, count;
	bitset<MAX_BITS> binary;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		snum.clear();
		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {
			character = ifilestream.get();
			snum += character;
		}
		if(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}
		if(!snum.empty()) {
			istringstream isstream(snum);
			isstream >> num;
			snum.clear();
		}
		binary = num;
		count = 0;
		for(int i = 0; i < binary.size(); i++) {
			if(binary[i] == 1)
				count++;
		}
		if(first) {
			cout << count;
			first = false;
		}
		else cout << endl << count;
	}
	ifilestream.close();

	return 0;
}