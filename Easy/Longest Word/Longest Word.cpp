/* Longest Word.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char *argv[]) {
	std::string line, word, longest_word;
	bool first_line = true;

	std::ifstream ifs;

	ifs.open(argv[1]);
	while(ifs.peek() != EOF) {
		getline(ifs, line);
		std::istringstream iss(line);
		longest_word.clear();

		while(iss) {
			getline(iss, word, ' ');
			if(longest_word.empty() || word.size() > longest_word.size()) {
				longest_word = word;
			}
		}
		if(first_line) {
			first_line = false;
			std::cout << longest_word;
		}
		else std::cout << std::endl << longest_word;
	}

	ifs.close();

	return 0;
}