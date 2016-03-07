/* Number Pairs.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sarray, sX, snum;
	int num, X, smallest;
	vector<int> array, pair;
	vector<vector<int> > pairs;
	set<int> exclusion_set;
	bool first = true, firstp;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {

		firstp = true;
		sarray.clear();
		sX.clear();

		//ignore newlines.
		while(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}

		getline(ifilestream, sarray, ';');
		getline(ifilestream, sX);

		//convert the strings to number form.
		istringstream isstream(sX);
		isstream >> X;

		snum.clear();
		array.clear();
		while(!sarray.empty()) {
			if(isdigit(sarray.at(0))) {
				snum += sarray.at(0);
				sarray.erase(0, 1);
			}
			else if(!snum.empty()) {
				isstream.clear();
				isstream.str(snum);
				isstream >> num;
				array.push_back(num);
				snum.clear();
				sarray.erase(0, 1);
			}
		}
		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			array.push_back(num);
		}

		pairs.clear();
		exclusion_set.clear();

		//determine/find pairs that equal to X.
		for(int j = 0; j < array.size(); j++) {
			//prevents the use of the same number,if not duplicated.
			for(int k = j + 1; k < array.size(); k++) {
				if(array.at(j) + array.at(k) == X) {

					//test variables against exclusion set, if not excluded, add to found pairs and then exclude.
					if(exclusion_set.find(array.at(j)) == exclusion_set.end()) {
						if(array.at(j) <= array.at(k)) {
							pair.push_back(array.at(j));
							pair.push_back(array.at(k));
						}
						else {
							pair.push_back(array.at(k));
							pair.push_back(array.at(j));
						}
						pairs.push_back(pair);
						pair.clear();
						exclusion_set.insert(array.at(j));
						exclusion_set.insert(array.at(k));
					}
				}
			}
		}

	
		// if no pairs are found.
		if(pairs.size() == 0) {
			if(first) {
				first = false;
				cout << "NULL";
			}
			else cout << endl << "NULL";
		}

		// now with all pairs found, present in ascending order according to the first number of each pair.
		while(pairs.size() > 0) {
			//find smallest

			smallest = (pairs.at(0)).at(0);

			for(int a = 0; a < pairs.size(); a++) {
				if(smallest >= (pairs.at(a)).at(0))
					smallest = (pairs.at(a)).at(0);
			}

			//delete smallest

			for(int b = 0; b < pairs.size(); b++) {
				if(smallest == (pairs.at(b)).at(0)) {
				//	(pairs.at(b)).clear();
					pairs.erase(pairs.begin()+b);	// so don't use clear to remove a vector within a vector when you can use .erase on the larger item. they're different.
					break;
				}
			}

			//print smallest pair
			if(first) {
				first = false;
				if(firstp) {
					firstp = false;
					if(pairs.size() > 0) {
						cout << smallest << "," << X - smallest << ";";
					}
					else cout << smallest << "," << X - smallest;
				}
			}
			else { 
				if(firstp) {
					firstp = false;
					if(pairs.size() > 0) {
						cout << endl << smallest << "," << X - smallest << ";";
					}
					else cout << endl << smallest << "," << X - smallest;
				}
				else {
					if(pairs.size() > 0) {
						cout << smallest << "," << X - smallest << ";";
					}
					else cout << smallest << "," << X - smallest;
				}
			}
		}
	}

	ifilestream.close();

	return 0;
}