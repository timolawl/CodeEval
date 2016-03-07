/* Balanced Smileys.cpp
 *
 * TIL: erase-remove/remove_if idiom: remove elements from a container.
 		in a for loop with i:
 *		.erase(remove/remove_if(::begin, ::end, criterion (delims[i]) or bool fcn taking in i), ::end);
 *
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

bool test_conditions(string test);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string test_case;
	bool first = true, condition;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, test_case);
		condition = test_conditions(test_case);
		if(first) {
			first = false;
			condition ? cout << "YES" : cout << "NO";
		}
		else condition ? cout << endl << "YES" : cout << endl << "NO";
	}

	ifilestream.close();

	return 0;
}

bool test_conditions(string test) {
	char chars[] = " abcdefghijklmnopqrstuvwxyz";
	//when is it false?
	//if the ( and ) do not match. unless they are smileys. for smileys :) :( ): or (:     so colons must either preceed it or follow it immediately. but then again 
	// if ) at the beginning before a ( and ( at the end before a ), and no attached colons, then it is invalid.
	// you have to test for the case when it is ambiguous and you want the colon to go to the correct parenthesis.

	string original, original_open, original_close;
	int open_position, open_count, close_position, close_count;

	//get rid of the simple conditions first
	if(test.empty()) {
		return true;
	}
	
	// what about ambiguous cases such as (:) ) or ):(?
	// i think the idea is that if there are more ( than ) then you want to assume the smiley is of (: type.

	//count the number of open and close parenthesis:
	open_count = 0;
	for(int i = 0; i < test.size(); i++) {
		if(test.at(i) == '(') {
			open_count++;
		}
	}

	close_count = 0;
	for(int j = 0; j < test.size(); j++) {
		if(test.at(j) == ')') {
			close_count++;
		}
	}

	//if there are more open than close parenthesis, disambiguate the smileys to the open form smileys. but keep a running count. if equal, disengage.
	while(open_count > close_count) {
		original_open = test;
		for(int i = 0; i < test.size(); i++) {
			if(test.at(i) == '(') {
				if(i - 1 >= 0) {
					if(test.at(i - 1) == ':') {
						test.erase(i - 1, 2);
						open_count--;
						break;
					}
				}
				else {
					if(test.size() > i + 1) {
						if(test.at(i + 1) == ':') {
							test.erase(i, 2);
							open_count--;
							break;
						}
					}
				} 	
			}
		}
		if(original_open.size() == test.size()) break;
	}

	//if there are more close than open parenthesis, disambiguate the smileys to the close form smileys.
	while(open_count < close_count) {
		original_close = test;
		for(int i = 0; i < test.size(); i++) {
			if(test.at(i) == ')') {
				if(i - 1 >= 0) {
					if(test.at(i - 1) == ':') {
						test.erase(i - 1, 2);
						close_count--;
						break;
					}
				}
				else {
					if(test.size() > i + 1) {
						if(test.at(i + 1) == ':') {
							test.erase(i, 2);
							close_count--;
							break;
						}
					}					
				} 
			}
		
		}
		if(original_close.size() == test.size()) break;
	}

	//at this point, check if the two are equal. if not then it can't be a balanced smiley.
	if(open_count != close_count) {
		return false;
	}

	//get rid of everything except for parenthesis and colons
	for(unsigned int i = 0; i < strlen(chars); i++) {		// <cstring> lib for strlen.
		test.erase(remove(test.begin(), test.end(), chars[i]), test.end()); // so remove_if has similar structure but instead of delims, it uses a bool function to act on the number i.
	}

	//get rid of simple (). actually you can't because of :. it's possible that it's like (asdf:(). that can be interpreted as (: and () or :() in (). asdfaf:().
	while(test.find("()") != string::npos) {
		test.erase(test.find("()"), 2);
	}
	
	//check beginning and end for parenthesis consistency.

	unsigned first_open = test.find("(");
	unsigned first_close = test.find(")");
	unsigned last_open = test.rfind("(");
	unsigned last_close = test.rfind(")");

	do{
		original = test;

		//but be sure that these aren't smileys. if they are, get rid of them.
		if(first_open > first_close) {
			if(first_close >= 1) {				// dont perform operations on a value when you can compare it without math involved. the value looped to 400m when -1.
				if(test.at(first_close - 1) == ':') {
					test.erase(first_close - 1, 2);
					first_close = test.find(")");
				}
			}
			else {
				if(test.size() > first_close + 1) {
					if(test.at(first_close + 1) == ':') {
						test.erase(first_close, 2);
						first_close = test.find(")");
					}
				}
			}
		}
		else if(last_open > last_close) {
			if(last_open >= 1) {
				if(test.at(last_open - 1) == ':') {
					test.erase(last_open - 1, 2);
					last_open = test.find("(");
				}
			}
			else {
				if(test.size() > last_open + 1) { 
					if(test.at(last_open + 1) == ':') {
						test.erase(last_open, 2);
						last_open = test.find("(");
					}
				}
			}
		}
		//repeat the process until there are no more smileys to get rid of.
		if(original.size() == test.size()) {
			if(first_open > first_close || last_open > last_close) {
				return false;
			}
			break;
		}
	} while(first_open > first_close || last_open > last_close);
	
	return true;
}