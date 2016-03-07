/* N Mod M.cpp
 *
 * TIL: Alternative instead of remaking an istringstream everytime. Think about the opposite of ostringstream. Instead of using .str() at the end for ostringstream,
 *		use .str() at the beginning for istringstream. Just declare the variable first, istringstream isstream; then isstream.str() what you want. Then .clear() it to reuse.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string N, M;
	int nN, nM;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		nN = 0; nM = 0;
		getline(ifilestream, N, ',');
		getline(ifilestream, M);
		istringstream isstream;								// LVL UP! Found a new way to stream in strings and convert them to int.
		isstream.str(N);
		//istringstream isstream1(N);
		isstream >> nN;
		//istringstream isstream2(M);
		isstream.clear();
		isstream.str(M);
		isstream >> nM;
		while(nN >= nM) {
			nN -= nM;
		}	
		if(first) {
			cout << nN;
			first = false;
		} else cout << endl << nN;

	}

	ifilestream.close();
	// easy, just keep subtracting the N by M until the value becomes negative, return the previous.

	return 0;
}