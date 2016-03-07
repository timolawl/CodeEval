/* Penultimate Word.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string words, word;
	int wordcount;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		wordcount = 0;
		word.clear();
		words.clear();

		getline(ifilestream, words);
		for(int i = words.size() - 1; i >= 0; i--) {
			if(isalpha(words.at(i)))
				word = words.at(i) + word;
			else {
				wordcount++;
				if(wordcount == 2) {
					if(first) {
						cout << word;
						first = false;
					}
					else {
						cout << endl << word;	
						break;
					}
				}
				word.clear();
			}
			if(i == 0) {
				wordcount++;
				if(wordcount == 2) {
					if(first) {
						cout << word;
						first = false;	
					}
					else {
						cout << endl << word;
						break;
					}
				}
				word.clear();
			}

		}
	}

	ifilestream.close();
	
	return 0;
}