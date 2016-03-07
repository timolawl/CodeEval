/* Minimum Coins.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string stotal;
	int total, min;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		min = 0;
		getline(ifilestream, stotal);
		istringstream isstream (stotal);
		isstream >> total;

		while(total >= 5) {
			total -= 5;
			min++;
		}
		while(total >= 3) {
			total -= 3;
			min++;
		}
		while(total >= 1) {
			total -= 1;
			min++;
		}
		if(first) {
			first = false;
			cout << min;
		}
		else cout << endl << min;

	}

	ifilestream.close();

	return 0;
}