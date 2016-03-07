/* Pangrams.cpp
 *
 * Pangrams = a sentence of phrase that has every letter in the alphabet.
 * Determine if pangram, and if not, return the letters it is missing in alphabetical order.
 *
 * TIL: <algorithm> 
 *			set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(difference (difference is a set), difference.begin()));
 *				- this will contain all the elements in s1 that are not in s2.
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sentence;
	set<char> alphabet, exclusion_set;
	set<char> difference;
	bool first = true;
	set<char>::iterator testit;


	//store the alphabet letters in the alphabet set.
	for(int i = 0; i < ALPHABET_SIZE; i++) {
		alphabet.insert(i + 'a');		// a = 97 in ascii.
	}

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		sentence.clear();
		difference.clear();
		exclusion_set.clear();

		getline(ifilestream, sentence);
		// enter in the sentence letters and add them to the exclusion set.
		for(int j = 0; j < sentence.size(); j++) {
			if(isalpha(sentence.at(j))) {
				exclusion_set.insert(tolower(sentence.at(j)));
			}
		}

		//compare alphabet to exclusion set.
		set_difference(alphabet.begin(), alphabet.end(), exclusion_set.begin(), exclusion_set.end(), inserter(difference, difference.begin()));	
																										// set_difference will contain all the elements in set1 but not in set2.
/*
		for(testit = difference.begin(); testit != difference.end(); testit++) {
			cout << *testit;
		}
*/
		//if first output
		if(first) {
			//if difference is empty, meaning that the sentence is a pangram
			if(difference.empty()) {
				cout << "NULL";
			}
			//else it isn't a pangram, and then output the letters it is missing
			else {
				for(set<char>::iterator it = difference.begin(); it != difference.end(); it++) {
					cout << *it; // should already output in alphabetical order.
				}
			}
			first = false;
		}
		else {
			if(difference.empty()) {
				cout << endl << "NULL";
			}
			//else it isn't a pangram, and then output the letters it is missing
			else {
				cout << endl;
				for(set<char>::iterator it = difference.begin(); it != difference.end(); it++) {
					cout << *it; // should already output in alphabetical order.
				}
			}
		}
	}

	ifilestream.close();

	return 0;
}