/* String Rotation.cpp
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
	string word, test_word, characters;
	bool first = true, rotated;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		rotated = true;
		getline(ifilestream, word, ',');
		getline(ifilestream, test_word);
		characters.clear();

		//if the word lengths are not the same, it cannot possibly be a rotated string.
		if(word.size() != test_word.size()) {
			if(first) {
				first = false;
				cout << "False";
			}
			else cout << endl << "False";
		}
		else {
			for(int i = 0; i < word.size(); i++) {
				characters += test_word.at(i);

				//find the matching beginning letters of test_word in word.
				if(word.find(characters) == string::npos) {
					characters.erase(characters.size() - 1, 1);
					break;
				}
			}

			//compare the characters at the beginning of word and at the end of test_word based off the size of the match produced above.
			for(int j = 0; j < word.size() - characters.size(); j++) {
				if(word.at(j) != test_word.at(characters.size() + j)) {
					rotated = false;
					if(first) {
						first = false;
						cout << "False";
					}
					else cout << endl << "False";
					break;
				}
			}

			//if all characters match, then it is indeed rotated. (if the characters did not all match, rotated would be false as assigned above.)
			if(rotated) {
				if(first) {
					first = false;
					cout << "True";
				}
				else cout << endl << "True";
			}
		}
	}
	ifilestream.close();
	return 0;
}