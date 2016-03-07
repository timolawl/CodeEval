/* Shortest Repetition.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check_repetition(const string &f, const string &s);

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	string line, fragment;
	bool repetition = false, first = true;

	while(ifs.peek() != EOF) {
		getline(ifs, line);
		repetition = false;
		for(int i = 1; i <= line.size(); i++) {
			//look through increasing size fragments of the original line.
			fragment = line.substr(0, i);
			repetition = check_repetition(fragment, line);
			if(repetition)
				break;
		}
			if(first) {
				first = false;
				cout << fragment.size();
			}
			else cout << endl << fragment.size();
	}

	ifs.close();

	return 0;
}

bool check_repetition(const string &f, const string &s) {

	for(int i = f.size(), j = 0; i < s.size(); i++) {

		if(s.at(i) != f.at(j)) {
			return false;
		}

		if(j == f.size() - 1) {
			j = 0;
		}
		else j++;

	}

	return true;
}