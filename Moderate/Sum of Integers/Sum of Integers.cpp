/* Sum of Integers.cpp
 *
 * Write a program to determine the largest sum of contiguous integers in a list.
 *
 * Input sample:
 *
 *	 	-10, 2, 3, -2, 0, 5, -15
 *		2,3,-2,-1,10
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snumbers, snumber;
	vector<int> numbers, subset;
	vector< vector<int> > list;
	int num, largest_sum, sum, a;
	bool first = true;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		snumbers.clear();
		numbers.clear();
		subset.clear();
		list.clear();

		getline(ifilestream, snumbers);

		for(int i = 0 ; i < snumbers.size(); i++) {
			if(!isspace(snumbers.at(i)) && snumbers.at(i) != ',') {
				snumber += snumbers.at(i);
			}
			else if(!snumber.empty()) { //else makes it so that the condition isn't even checked if the first one follows through - efficiency.
				istringstream isstream(snumber);
				isstream >> num;
				numbers.push_back(num);
				snumber.clear();
			}
		}
		if(!snumber.empty()) { 	// still need this so that you get the last piece of data considered.
			istringstream isstream(snumber);
			isstream >> num;
			numbers.push_back(num);
			snumber.clear();
		}

		//largest sum of CONTIGUOUS integers. Not largest sum overall. so basically all possible combinations of arrays (vectors are better)
		list.push_back(numbers);
		subset.clear();
		for(int j = 0; j < numbers.size(); j++) {
			for(int k = j; k < numbers.size(); k++) {
				a = j;
				while(a <= k) {
					subset.push_back(numbers.at(a));
					a++;
				}
				list.push_back(subset);
				subset.clear();
			}
		}
		largest_sum = 0;

		//go through the list of all arrays (vectors) and sum up each vector - keep the largest sum.
		for(int m = 0; m < list.size(); m++) {
			sum = 0;
			for(int n = 0; n < (list.at(m)).size(); n++) {
				sum += (list.at(m)).at(n);
			}
			if(largest_sum < sum) {
				largest_sum = sum;
			}
		}

		//output
		if(first) {
			cout << largest_sum;
			first = false;
		}
		else cout << endl << largest_sum;
	}

	ifilestream.close();

	return 0;
}