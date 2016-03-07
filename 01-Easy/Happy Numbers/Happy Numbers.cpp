/* Happy Numbers.cpp
 *
 * TIL: More on iterators and .find() for a set. .find() will return set::end if item is not found in set.
 *		Therefore, exampleset.find(exampleitem) != exampleset.end() would be a good if statement.
 *		Can also do iterator approach by setting iterator equal to the end of the set: it != exampleset.end();
 *
 */

#include <iostream>
#include <fstream>
#include <set>		// for exclusion set.
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const int ASCII_CONV = 48;
const int ASCII_ONE = 49;

void happyNumber(string number, set<int> &exclusion, bool &first);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snum;
	int num;
	set<int> exclusion;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		exclusion.clear();
		getline(ifilestream, snum);

/*		

		istringstream isstream(snum);
		if(snum.size() == 1)
			num = isstream.get() - ASCII_CONV;
		else isstream >> num;
*/
		happyNumber(snum, exclusion, first);
	}

	ifilestream.close();

	return 0;
}

void happyNumber(string number, set<int> &exclusion, bool &first) {
	int sum = 0;
	ostringstream osstream;
	if(number.size() == 1) {
		if(number.at(0) == ASCII_ONE) {
			if(first) {
				cout << number;
				first = false;
				return;
			} else {
				cout << endl << number;
				return;
			}
		}
	}
	for(int i = 0; i < number.size(); i++) {
		sum += pow(number.at(i) - ASCII_CONV, 2);					// Converting single characters to int form requires a subtraction of the ASCII conversion of 48.
	}
//	set<int>::iterator it;											// for sets, .find() returns an iterator to the position set::end. 
//	it = exclusion.find(sum);										
	if(exclusion.find(sum) != exclusion.end()) {					// two ways of doing it. this way is easier.
		if(first) {
			cout << '0';
			first = false;
			return;
		} else {
			cout << endl << '0';
			return;
		}
	} else exclusion.insert(sum);

	osstream << sum;
	happyNumber(osstream.str(), exclusion, first);
	

}