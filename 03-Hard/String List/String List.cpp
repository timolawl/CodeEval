/* String List.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

set<string> make_list(set<string> old_set, set<string> subset, int N, int size);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN, S, temp;
	set<string> character_set, list;
	int N;
	bool first;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sN, ',');
		getline(ifilestream, S);
		istringstream isstream(sN);
		isstream >> N;

		character_set.clear();

		//add the characters of S to a set.
		for(int i = 0; i < S.size(); i++) {
			temp = S.at(i);
			character_set.insert(temp);
		}

		//make N sized items from the set.
		list = make_list(character_set, character_set, N, 1);

		if(first) {
			first = false;
			for(set<string>::iterator it = list.begin(); it != list.end(); it++) {
				if(it == list.begin()) {
					cout << *it;
				}
				else cout << "," << *it;
			}
		}
		else {
			for(set<string>::iterator it = list.begin(); it != list.end(); it++) {
				if(it == list.begin()) {
					cout << endl << *it;
				}
				else cout << "," << *it;
			}
		}
	}

	ifilestream.close();

	return 0;
}

set<string> make_list(set<string> old_set, set<string> subset, int N, int size) {
	//basic condition
	//once N is reached, return the set.
	string characters, item;
	set<string> new_set, final_set;

	if(size == N) {
		return subset;
	}

	if(size == 1) {
		old_set = subset;
	}

	//elemental decomposition
	for(set<string>::iterator it = subset.begin(); it != subset.end(); it++) {
		//take an element from the set and set it as the first character in the final set. what you need to do is add too sets together.
		for(set<string>::iterator it2 = old_set.begin(); it2 != old_set.end(); it2++) {
			item = *it2 + *it;
			new_set.insert(item);
		}
	}	

	final_set = make_list(old_set, new_set, N, size + 1);

	return final_set;
}