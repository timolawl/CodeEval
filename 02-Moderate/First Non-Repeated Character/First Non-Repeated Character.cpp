/* First Non-Repeated Character.cpp
 *
 *	set::find() will return setvar.end() if not found.
 *
 */

#include <iostream>
#include <fstream>
#include <set>
//#include <string> don't need this? LCA didn't use it.

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string word;
	set<char> exclude;
	bool first = true, found;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		word.clear();
		found = false;
		exclude.clear();

		getline(ifilestream, word);
		for(int i = 0; i < word.size(); i++) {
			for(int j = i + 1; j < word.size(); j++) {
				if(word.at(i) == word.at(j) || exclude.find(word.at(i)) != exclude.end()) {
					exclude.insert(word.at(i));
					break;
				}
				if(j == word.size() - 1) {
					if(first) {
						cout << word.at(i);
						first = false;
						found = true;
						break;
					}
					else {
						cout << endl << word.at(i);
						found = true;
						break;
					}
				}
			}
			if(i == word.size() - 1) {
				if(exclude.find(word.at(i)) == exclude.end()) {
					if(first) {
						cout << word.at(i);
						first = false;
						found = true;
						break;
					}
					else {
						cout << endl << word.at(i);
						found = true;
						break;
					}
				}
			}
			if(found == true)
				break;
		}
	}

	ifilestream.close();

	return 0;
}