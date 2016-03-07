/* Roman Numerals.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string convert_digit(const vector<int> &dig, const int &s);
char insert_correct_numeral(const int &s);

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	string s_digits, roman_numerals;
	int size, digit;
	vector<int> digits;
	bool first = true;

	while(ifs.peek() != EOF) {
		//string the numbers in first
		getline(ifs, s_digits);
		digits.clear();

		for(int i = 0; i < s_digits.size(); i++) {
			digit = s_digits.at(i) - '0';
			digits.push_back(digit);
		}

		//count digits - if three digits, consider hundreds, tens, ones.
		size = s_digits.size();
		roman_numerals = convert_digit(digits, size);

		if(first) {
			first = false;
			cout << roman_numerals;
		}
		else cout << endl << roman_numerals;

	}

	ifs.close();

	return 0;
}

string convert_digit(const vector<int> &dig, const int &s) {

	vector<int> shortened_digits;
	int shortened_size;
	string nascent_string, remaining_string_portion;
	nascent_string.clear();

//	cout << dig.at(0) << endl;

	//conditional on size, conditional on number.
	switch(dig.at(0)) {
		case 1:
		//	cout << "testing1" << endl;
			nascent_string += insert_correct_numeral(s);
			break;
		case 2:
			nascent_string += insert_correct_numeral(s);
			nascent_string += insert_correct_numeral(s);
			break;
		case 3:
			nascent_string += insert_correct_numeral(s);
			nascent_string += insert_correct_numeral(s);
			nascent_string += insert_correct_numeral(s);
			break;
		case 4:
			if(s == 3) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'D';
			}
			else if(s == 2) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'L';
			}
			else if(s == 1) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'V';
			}
			break;
		case 5:
			if(s == 3) {
				nascent_string += 'D';
			}
			else if(s == 2) {
				nascent_string += 'L';
			}
			else if(s == 1) {
				nascent_string += 'V';
			}
			break;
		case 6: 
			if(s == 3) {
				nascent_string += 'D';
				nascent_string += insert_correct_numeral(s);
			
			}
			else if(s == 2) {
				nascent_string += 'L';
				nascent_string += insert_correct_numeral(s);
			
			}
			else if(s == 1) {
				nascent_string += 'V';
				nascent_string += insert_correct_numeral(s);
			}
			break;
		case 7: 
			if(s == 3) {
				nascent_string += 'D';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			else if(s == 2) {
				nascent_string += 'L';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			else if(s == 1) {
				nascent_string += 'V';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			break;
		case 8: 
			if(s == 3) {
				nascent_string += 'D';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			else if(s == 2) {
				nascent_string += 'L';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			else if(s == 1) {
				nascent_string += 'V';
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
				nascent_string += insert_correct_numeral(s);
			}
			break;
		case 9:
			if(s == 3) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'M';
			}
			else if(s == 2) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'C';
			}
			else if(s == 1) {
				nascent_string += insert_correct_numeral(s);
				nascent_string += 'X';
			}
			break;
	}

	if(s > 1) {
		shortened_digits = dig;
		shortened_digits.erase(shortened_digits.begin());
		shortened_size = s - 1;

		remaining_string_portion = convert_digit(shortened_digits, shortened_size);
		nascent_string += remaining_string_portion;
	//	cout << nascent_string << endl;
	}

	return nascent_string;

}

char insert_correct_numeral(const int &s) {

//	cout << "testing" << endl;

	if(s == 4) {
		return 'M';
	}
	else if(s == 3) {
		return 'C';
	}
	else if(s == 2) {
		return 'X';
	}
	else if(s == 1) {
		return 'I';
	}
}