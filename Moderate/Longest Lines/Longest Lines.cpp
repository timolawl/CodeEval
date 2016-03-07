/* Longest Lines.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>	// for remove_if()
#include <vector>
//#include <sstream>

using namespace std;

const int ASCII_CONV = 48;

//bool isLongest(string line, string longest);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string line, longest_line;
	char N;
	//string N;
	int num, longest, output = 0;
	vector<string> lines;
	vector<string>::iterator it;
	bool first = true;

	ifilestream.open(argv[1]);
	// get N
	N = ifilestream.get();			// so I can use .get() to just grab one char, though I still haven't tested whether the next getline will get nothing.
	num = N - ASCII_CONV;

//	getline(ifilestream, test);		// so it actually does pick up the new line. .get() didn't pick it up, which makes sense.
/*
	getline(ifilestream, N);
	istringstream isstream(N);
	isstream >> num;
*/
	// get each line and feed it into a vector of strings
	while(ifilestream.peek() != EOF) {
		line.clear();
		getline(ifilestream, line);
		if(!line.empty()) {
			lines.push_back(line);
		}
	}
	//while the number you want
	// for loop the print of the highest and remove
	while(output < num) {
		longest = 0;
		longest_line.clear();
		for(int i = 0; i < lines.size(); i++) {
			if(longest < (lines.at(i)).size()) {
				longest = (lines.at(i)).size();
				longest_line = lines.at(i);
			}
		} 
		if(first) {
			cout << longest_line;
			first = false;
		}
		else cout << endl << longest_line;
// 		it = remove_if(lines.begin(), lines.end(), isLongest); 			// can't use this method since the bool function can only take one parameter.
		output++;

		for(it = lines.begin(); it != lines.end(); it++) {
			if(*it == longest_line) {
				it = lines.erase(it);						// so this works? You can use .erase() on the address itself?
				break;
			}
		}
	}
	ifilestream.close();

	return 0;
}
/*
bool isLongest(string line, string longest) {
	return (line == longest);
}
*/