/* Lowercase.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	string sentence, newsentence;
	bool first = true;

	while(ifilestream) {
		newsentence.clear();
		getline(ifilestream, sentence);
		for(int i = 0; i < sentence.size(); i++) {
			if(isupper(sentence.at(i))) 					// how come isalpha preceeding this messed up the program and was unable to fetch the rest of the sentence?
				newsentence += tolower(sentence.at(i));
			else newsentence += sentence.at(i);
		}
		if(first) {
			cout << newsentence;
			first = false;
		} else cout << endl << newsentence;
	}

	ifilestream.close();

	return 0;
}