/* Mth to the last element.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

const int ASCII_CONV = 48;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	vector<char> letters;
	char character;
	int m;
	bool first = true;

	ifilestream.open(argv[1]);

	while(ifilestream.peek() != EOF) {
		letters.clear();

		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {
			if(isalpha(ifilestream.peek())) {
				character = ifilestream.get();
				letters.push_back(character);
			}
			else if(isdigit(ifilestream.peek())) {
				character = ifilestream.get();
				m = character - ASCII_CONV;
			}
			else ifilestream.ignore(1);
		}

		if(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}
		if(m <= letters.size()) {
			if(first) {
				cout << letters.at(letters.size() - m);
				first = false;
			}
			else cout << endl << letters.at(letters.size() - m);
		}
	}
	ifilestream.close();

	return 0;
}