/* Capitalize Words.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sentence, word;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		sentence.clear();
		getline(ifilestream, sentence);
		for(int i = 0; i < sentence.size(); i++) {
			if(islower(sentence.at(i))) {
				if(i == 0)
					sentence.at(i) -= 32;	
				else if(isspace(sentence.at(i - 1))) {
					sentence.at(i) -= 32;
				}
			}
		}
		if(first) {
			first = false;
			cout << sentence;
		}
		else cout << endl << sentence;

	}

	ifilestream.close();

	return 0;
}