/* Simple Sorting.cpp
 *
 * 
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include <iomanip>

using namespace std;

void simple_sort(vector<double> &numbers, bool &first);

int main(int argc, char *argv[]) {
	
	ifstream ifilestream;
	string unsorted, snum;
	vector<double> numbers;
	double num = 0;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		numbers.clear();
		snum.clear();

		getline(ifilestream, unsorted);
		for(int i = 0; i < unsorted.size(); i++) {
			if(!isspace(unsorted.at(i)))
				snum += unsorted.at(i);
			else {
				istringstream isstream;
				isstream.str(snum);
				isstream >> num;
				numbers.push_back(num);
				snum.clear();
				num = 0;
			}
			if(i == unsorted.size() - 1) {
				istringstream isstream;
				isstream.str(snum);
				isstream >> num;
				numbers.push_back(num);
				snum.clear();
				num = 0;
			}

		}
/*
		while(ifilestream.peek() != '\n') {
			getline(ifilestream, snum, ' ');
			istringstream isstream;
			isstream.str(snum);
			isstream >> num;
			numbers.push_back(num);
		}
*/

		simple_sort(numbers, first);
	}

	ifilestream.close();

	return 0;
}

void simple_sort(vector<double> &numbers, bool &first) {
	bool first_num = true;
	double temp = 0;

	cout.setf(ios::fixed, ios::floatfield);			// this sets the cout floatfield to fixed instead of scientific. (ie., fixed number of digits after radix point.)
	cout.precision(3);							

	for(int i = 0; i < numbers.size(); i++) {
		for(int j = i + 1; j < numbers.size(); j++) {
			if(numbers.at(i) > numbers.at(j)) {
				temp = numbers.at(i);
				numbers.at(i) = numbers.at(j);
				numbers.at(j) = temp;
			}
		}
	}
	if(first) {
		for(int k = 0; k < numbers.size(); k++) {
			if(first_num) {
				cout << numbers.at(k);
				first_num = false;
			} else {
				cout << " " << numbers.at(k);
			}
		}
		first = false;
	} 
	else { 
		for(int l = 0; l < numbers.size(); l++) {
			if(first_num) {
				cout << endl << numbers.at(l);
				first_num = false;
			} else cout << " " << numbers.at(l);
		}
		
	}
}