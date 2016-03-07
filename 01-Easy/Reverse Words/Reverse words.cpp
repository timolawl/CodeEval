/* Reverse words.cpp
 *
 * Functions:
 *		store_words(): gets each word and stores it into a vector<string> by calling on getWords().
 *
 *		getWords(): gets a word in a sentence and returns that word. Sentence is shrunk.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

bool store_words(vector<string> &i, string &s);
string getWords(string &s);

int main(int argc, char *argv[]) {
	
	vector<string> input, output; // design: input in words, output in sentences
	ifstream infile;
	string text_file, sentence, reverse, temp;

//	getline(cin, text_file);													// getting text file
	text_file = argv[1];
	if(text_file.find(".txt") == string::npos)									// if it doesn't have the .txt extension, it is added on
		text_file += ".txt";
	infile.open(text_file.c_str());												// opening or setting the stream to the file to be read

	while(infile.good()) {														// while there is content in the stream
		getline(infile, sentence);												// read line by line
		if(store_words(input, sentence)) {										// stores words in the vector<string> input. The if checks to make sure that the line is not empty.

			for(int i = input.size() - 1; i >= 0; i--) {						// starting from the end of the vector
				if(i == 0) {													// a string is created based on the backward contents of vector<string> input.
					reverse += input.at(i);
					reverse += '\n';
				} else {
					reverse += input.at(i);
					reverse += " ";
				}
			}
			if(!reverse.empty())												// this is a check to check if the line is empty (e.g., a blank line). Probably don't need two.
				output.push_back(reverse);
			reverse.clear();													// have to clear the reverse string for the next instance of creating a backward string.
			input.clear();														// have to clear the input vector otherwise it keeps on adding words to itself.
		}
	}
	temp = output.at((output.size()-1));										// the next three lines are for getting rid of the newline character to ensure that there is no
	temp.erase(temp.size()-1, 1);												// space or newline character types at the end.
	output.at((output.size()-1)) = temp;

	for(int i = 0; i < output.size(); i++) {									// the next three lines generates the backward output.
		cout << output.at(i);
	}
	
	infile.close();																// close file
	
	return 0;
}

bool store_words(vector<string> &i, string &s) {
	if(s == "")																	// checks to see if the line is blank.
		return false;
	while(s != "")																// if not (kind of redundant), then add the words into the vector.
		i.push_back(getWords(s));

	return true;
}

string getWords(string &s) {
	string word = "";
	//locate beginning
	while(s != "") {																// this while loop is to locate the beginning of the word
		if(!isalpha(s.at(0)))
			s.erase(0, 1);
		else { 
			word += s.at(0);
			s.erase(0, 1);
			break;
		}
	}
	//elongate
	while(s != "") {																// this while loop extends the word
		if(isalpha(s.at(0))) {
			word += s.at(0);
			
			s.erase(0, 1);
		} else {
			s.erase(0, 1);
			break;
		}
	}
	
	return word;
}
