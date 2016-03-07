/* method - dotget.cpp
 *
 *
 * Take in characters from testfile of String Rotation.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	char character;
	string word;
	vector<string> words;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		words.clear();
		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {
			if(isalpha(character = ifilestream.get())) {
				word += character;
			}
			else if(!word.empty()) {
				words.push_back(word);
				word.clear();
			}
		}
		if(!word.empty()) {
			words.push_back(word);
			word.clear();
		}
		if(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}
		for(int i = 0; i < words.size(); i++) {
			cout << words.at(i) << " ";
		}
	}
	ifilestream.close();
	return 0;
}