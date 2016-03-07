/* Array Absurdity.cpp 
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN, snumbers, snum;
	int num;
	set<int> exclusion_set;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {

		//ignore newlines
		while(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}

		exclusion_set.clear();

		//receive variables into strings one line at a time
		getline(ifilestream, sN, ';');
		getline(ifilestream, snumbers);


		//convert string numbers to int numbers
		snum.clear();
		while(!snumbers.empty()) {
			if(isdigit(snumbers.at(0))) {
				snum += snumbers.at(0);
			}
			else if(!snum.empty()) {
				istringstream isstream(snum);
				isstream >> num;
				snum.clear();
				//add to new numbers to exclusion set; if the number is in exclusion set, that is the desired number.
				if(exclusion_set.find(num) == exclusion_set.end()) {
					exclusion_set.insert(num);
				}
				else {
					if(first) {
						first = false;
						cout << num;
					}
					else cout << endl << num;
					break;
				}
			}
			snumbers.erase(0, 1);
		}
		if(!snum.empty()) {
			istringstream isstream(snum);
			isstream >> num;
			if(exclusion_set.find(num) == exclusion_set.end()) {
				exclusion_set.insert(num);
			}
			else {
				if(first) {
					first = false;
					cout << num;
				}
				else cout << endl << num;
			}
		}
	}

	ifilestream.close();

	return 0;
}