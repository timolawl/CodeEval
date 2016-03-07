/*  Remove Characters.cpp
 *
 * Why is the string library not needed for string uses?
 *
 */

#include <iostream>
#include <fstream>
#include <set>
//#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string phrase, exclude;
	set<char> exclusion_set;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		exclusion_set.clear();
		getline(ifilestream, phrase, ',');
		getline(ifilestream, exclude);

		//generate exclusion set.
		for(int i = 0; i < exclude.size(); i++) {
			if(!isspace(exclude.at(i)))
				exclusion_set.insert(exclude.at(i));
		}
		//for loop out the characters in the string.
		for(int j = 0; j < phrase.size(); j++) {
			if(exclusion_set.find(phrase.at(j)) != exclusion_set.end()) {
				phrase.erase(j, 1);
				j--;
			}
		}
		if(first) {
			cout << phrase;
			first = false;
		}
		else cout << endl << phrase;

	}

	ifilestream.close();

	return 0;
}