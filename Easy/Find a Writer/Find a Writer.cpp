/* Find a Writer.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	string coded_message, number_keys, current_key, decyphered_message, line;
	int numeric_key;
	bool first = true;

	while(ifilestream.peek() != EOF) {
		line.clear();


		while(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}

//		while(getline(ifilestream, line, '|')) {
//			if(line == "" || line == "\n") {
//				line.clear();
//				continue;
//			}

		decyphered_message.clear();
		coded_message.clear();
		number_keys.clear();
		current_key.clear();
		numeric_key = 0;

//		coded_message = line;

		
		getline(ifilestream, coded_message, '|');
		getline(ifilestream, number_keys);

//		cout << coded_message << endl;

		//go through the entire string of numbers to use all the keys up
		for(int i = 0; i < number_keys.size(); i++) {
			//if the current element is a space
			if(isspace(number_keys.at(i))) {
				//and if the current key is not empty
				if(!current_key.empty()) {
					//convert key to its numeric form and add the content
					//of the coded message at that number to the decyphered
					//message
					istringstream convert(current_key);
					convert >> numeric_key;
				//	cout << number_keys << " " << decyphered_message << endl;
					decyphered_message += coded_message.at(numeric_key - 1);
					current_key.clear();
					numeric_key = 0;
				}
			}
			else current_key += number_keys.at(i);
			
			// keep adding numbers until a space is reached or end.

			// convert the numbers from string to char?

			// at space, use the numbers, and reset the key
			// if next key is a space
		}

		if(!current_key.empty()) {
			istringstream convert(current_key);
			convert >> numeric_key;
			decyphered_message += coded_message.at(numeric_key - 1);
			current_key.clear();
			numeric_key = 0;
		}

		if(first) {
			cout << decyphered_message;
			first = false;
		}
		else cout << endl << decyphered_message;

	}

	ifilestream.close();

	return 0;
}