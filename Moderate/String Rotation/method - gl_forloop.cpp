/* method - glforloop.cpp
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
	string word, test_word;
	vector<string> words;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, word, ',');
		getline(ifilestream, test_word);
		words.clear();
		words.push_back(word);
		words.push_back(test_word);
		for(int i = 0; i < words.size(); i++) {
			cout << words.at(i) << " ";
		}
	}
	ifilestream.close();
	return 0;
}