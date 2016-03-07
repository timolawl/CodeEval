/* String Permutations.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<string> generate_permutations(const string &characters);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string original;
	set<string> permutations;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, original);
	
		permutations.clear();

		permutations = generate_permutations(original);

		if(first) {
			first = false;
			for(set<string>::iterator it = permutations.begin(); it != permutations.end(); it++) {
				if(it == permutations.begin()) {
					cout << *it;
				}
				else cout << "," << *it; 
			}
		}
		else {
			for(set<string>::iterator it = permutations.begin(); it != permutations.end(); it++) {
				if(it == permutations.begin()) {
					cout << endl << *it;
				}
				else cout << "," << *it;
			}
		}
	}


	ifilestream.close();

	return 0;
}


set<string> generate_permutations(const string &characters) {
	set<string> current, new_set;
	string current_string, element, new_element;

	new_set.clear();

	if(!characters.empty()) {

		//take an element from characters through a loop
		for(int i = 0; i < characters.size(); i++) {
			element = characters.at(i);
			current_string = characters;
			current_string.erase(i, 1);
			current = generate_permutations(current_string);
			if(!current.empty()) {
				for(set<string>::iterator it = current.begin(); it != current.end(); it++) {
					new_element = element + *it;
					new_set.insert(new_element);
				}
			}
			else {
				new_element = element;
				new_set.insert(new_element);
			}
		}
	}

	return new_set;
}