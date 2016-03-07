/* Jolly Jumpers.cpp 
 *
 * A sequence of n > 0 integers is called a jolly jumper if the absolute values of the differences between successive elements take on all possible values 1 through n - 1. eg. 
 * 1 4 2 3 is a jolly jumper, because the absolute differences are 3, 2, and 1, respectively. The definition implies that any sequence of a single integer is a jolly jumper.
 * Write a program to determine whether each of a number of sequences is a jolly jumper.
 *
 * Input sample:
 *
 * Your program should accept as its first argument a path to a filename, Each line in this file is one test case. Each test case will contain an integer n < 3000 followed
 * by n integers representing the sequence. The integers are space delimited.
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	char character;
	string snum;
	int num, N, difference;
	vector<int> sample;
	set<int> jolly_list, list, leftover;
	bool first = true, out_of_bounds;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {

		//gets rid of newlines and reads pass newlines when needed.
		while(ifilestream.peek() == '\n') {
			ifilestream.ignore(1);
		}

		//retrieve numbers and conver to integer form; store in vector array.
		sample.clear();
		out_of_bounds = false;
		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {
			if(!isspace(character = ifilestream.get())) {			// can't base it off digit because there can be negative numbers.
				snum += character;
			}
			else if(!snum.empty()) {
				istringstream isstream(snum);
				isstream >> num;
				sample.push_back(num);
				snum.clear();
			}		
		}
		if(!snum.empty()) {
			istringstream isstream(snum);
			isstream >> num;
			sample.push_back(num);
			snum.clear();
		}
	//compute jolly
		//determine N
		N = sample.size();

		if(N > 1) {

			//set up jolly list to be all possible values between 1, n-1; 
			jolly_list.clear();
			for(int i = 1; i < N; i++) {
				jolly_list.insert(i);
			}

			//create list of values from sample.
			list.clear();
			//(don't forget to include the first value, which by definition is a jolly number to be tested)
			list.insert(sample.at(0));
			for(int j = 0; j < sample.size() - 1; j++) {
				difference = abs(sample.at(j) - sample.at(j + 1)); 		
				if(N < difference) {
					out_of_bounds = true;
					if(first) {
						first = false;
						cout << "Not jolly";
					}
					else cout << endl << "Not jolly";
					break;
				}
				else {
					list.insert(difference);
				}
			}
			if(!out_of_bounds) {
				//compare sets
				leftover.clear();
				set_difference(jolly_list.begin(), jolly_list.end(), list.begin(), list.end(), inserter(leftover, leftover.begin()));

				if(!leftover.empty()) {
					if(first) {
						first = false;
						cout << "Not jolly";
					}
					else cout << endl << "Not jolly";
				}
				else if(first) {
					first = false;
					cout << "Jolly";
				}
				else cout << endl << "Jolly";
			}
		}

		else if(N == 1) {
			if(first) {
				first = false;
				cout << "Jolly";
			}
			else cout << endl << "Jolly";
		}
	}

	ifilestream.close();

	return 0;
}