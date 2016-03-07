/* Trailing String.cpp
 *
 * You are given two strings 'A' and 'B'. Print out a 1 if string 'B' occurs at the end of string 'A'. Else a zero.
 *
 * Input sample:
 *
 * 	Hello World,World
 *	Hello CodeEval,CodeEval
 *	San Francisco,San Jose
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string A, B;
	bool first = true;

	ifilestream.open(argv[1]);

	while(ifilestream.peek() != EOF) {
		A.clear();
		B.clear();

		// for in the event there are random newlines.
		while(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}

		getline(ifilestream, A, ',');
		getline(ifilestream, B);

		//cut off spaces that CodeEval decides to randomly put at the end of their text documents..
		while(A.at(A.size() - 1) == ' ') {					// cannot use iterator style simply for position.
			A.erase(A.end() - 1, A.end());					// erase must be used with iterator style.
		}
		while(B.at(B.size() - 1) == ' ') {
			B.erase(B.end() - 1, B.end());
		}

		//if string B occurs at the end of string A.
		for(int i = B.size() - 1, j = A.size() - 1; i >= 0, j >= 0; i--, j--) {	// remember how declarations are made. anything after the comma still is defined as that type.
			// in the event that letters do not match, immediately break from the loop.
			if(B.at(i) != A.at(j)) {
				if(first) {
					cout << "0";
					first = false;
					break;
				}
				else {
					cout << endl << "0";
					break;
				}
			}
			// in the event that all the letters match and B < A. Therefore, a match is found.
			if(i == 0) {
				if(first) {
					cout << "1";
					first = false;
					break;
				}
				else {
					cout << endl << "1";
					break;
				}
			}
			// in the event that B is longer than A, but the numbers still match up to that point.
			if(j == 0 && B.size() > A.size()) {
				if(first) {
					cout << "0";
					first = false;
					break;
				}
				else {
					cout << endl << "0";
					break;
				}
			}
		}
	}


	ifilestream.close();

	return 0;
}