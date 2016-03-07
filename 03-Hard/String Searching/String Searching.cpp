/* String Searching.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sentence, subsentence, fragment;
	vector<string> elements;
	bool first = true, condition;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sentence, ',');
		getline(ifilestream, subsentence);

		condition = true;
		elements.clear();

		//split the subsentence into fragments separated by * (don't forget that \* means that * needs to be included into the entirety of the subelement.)
		for(int i = 0; i < subsentence.size(); i++) {
			if(subsentence.at(i) == '*') {
				if(i > 0) {
					if(subsentence.at(i - 1) == '\\') {
						fragment += subsentence.at(i);
					}
					else {
						elements.push_back(fragment);
						fragment.clear();
					}
				}
			}
			else {
				fragment += subsentence.at(i);
			}
		}

		if(!fragment.empty()) {
			elements.push_back(fragment);
			fragment.clear();
		}

		// if each element is found in the sentence and they are in correct order, then it is true
		for(int j = 0; j < elements.size(); j++) {
			if(sentence.find(elements.at(j)) == string::npos) {			// manually doing something that is already provided...rather not reinvent the wheel.
				condition = false;
				break;
			}
		}

		if(first) {
			first = false;
			if(condition) {
				cout << "true";
			}
			else cout << "false";
		}
		else if(condition) {
			cout << endl << "true";
		}
		else cout << endl << "false";



	}

	ifilestream.close();

	return 0;
}