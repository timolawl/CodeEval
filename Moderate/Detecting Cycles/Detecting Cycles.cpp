/* Detecting Cycles.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void getCycle(vector<int> numbers, bool &first);
vector<int> lowestLCDCycle(vector<int> cycle);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snums, n;
	int num;
	vector<int> numbers;
	bool first = true;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
	//	cout << ifilestream.rdbuf();
	//	break;
		snums.clear();
		getline(ifilestream, snums);
		n.clear();
		numbers.clear();

		for(int i = 0; i < snums.size(); i++) {
			if(!isspace(snums.at(i))) {
				n += snums.at(i);
			}
			else {
				istringstream isstream(n);
				isstream >> num;
				numbers.push_back(num);
				n.clear();
			//	isstream.clear();
			//	cout << num << endl;
			}
			if(i == snums.size() - 1) {
				istringstream isstream(n);
				isstream >> num;
				numbers.push_back(num);
				n.clear();
			//	isstream.clear();
			}
		}

/*		for(int x = 0; x < numbers.size(); x++) {
			cout << numbers.at(x) << endl;
		}
*/
		getCycle(numbers, first);
	}

	ifilestream.close();

	return 0;
}

void getCycle(vector<int> numbers, bool &first) {
	int a = 0, b = 0; // initialize the int variables.
	vector< vector<int> > cycles;
	vector<int> cycle, smallest;
//	vector< vector<int> >::iterator it;

	// set up the comparison loops
	for(int i = 0; i < numbers.size(); i++) {
		for(int j = i + 1; j < numbers.size(); j++) {
			// find matching numbers, as these are the start of cycles.
			if(numbers.at(i) == numbers.at(j)) {
				a = i;
				b = j;
				// read down the chain until the first discrepancy between the two positions.
				while(b < numbers.size()) {
					if(numbers.at(a) == numbers.at(b))
						a++, b++;
				}
				// if the value at the end of the read for the left position is the same as its initial position, then there is a cycle.
				if(a == j) {
					// read all the numbers of the cycle and add it to cycle.
		//			cout << numbers.at(a) << "  " << numbers.at(i) << endl;
					for(int k = a; k < b; k++) {
						cycle.push_back(numbers.at(k));
			//			cout << numbers.at(k) << endl;
					}	
					// get the smallest repeated cycle
					cycle = lowestLCDCycle(cycle);
					for(int c = 0; c < cycle.size(); c++) {
			//			cout << cycle.at(c) << endl;
					}
					// read the cycle into a larger cycles vector of int vectors. // but you dont want the longest cycle, you want the shortest cycle right?
					cycles.push_back(cycle);

					cycle.clear();
				}
			//	if(i == j) {
					// if i == j, it has made a complete cycle.
			//		for(int l = )
			//	}
			}
	//		cout << i << "  " <<  j << endl;
		}
		//cout << i << endl;
	}

//	cout << "testing" << endl;
	//find the smallest cycle within cycles:
	smallest.clear();
//	cout << cycles.size() << endl;
	for(int z = 0; z < cycles.size(); z++) {
		smallest = cycles.at(0);
		if(smallest.size() > (cycles.at(z)).size())
			smallest = cycles.at(z);
	}

	if(first) {
		for(int y = 0; y < smallest.size(); y++) {
			if(y == 0)
				cout << smallest.at(y);
			else cout << " " << smallest.at(y);
		}
		first = false;
	} 
	else {
		for(int y = 0; y < smallest.size(); y++) {
			if(y == 0)
				cout << endl << smallest.at(y);
			else cout << " " << smallest.at(y);
		}
	}
}

vector<int> lowestLCDCycle(vector<int> cycle) {
	int a = 0, b = 0; // initialize the int variables.
	vector< vector<int> > cycles;
	vector<int> LCDcycle;

	LCDcycle.clear();

	// set up the comparison loops
	for(int i = 0; i < cycle.size(); i++) {
		for(int j = i + 1; j < cycle.size(); j++) {
			// find matching numbers, as these are the start of cycles.
			if(cycle.at(i) == cycle.at(j)) {
				a = i;
				b = j;
				// read down the chain until the first discrepancy between the two positions.
				while(cycle.at(a) == cycle.at(b)) {
					a++, b++;
				}
				// if the value at the end of the read for the left position is the same as its initial position, then there is a cycle.
				if(a == i) {
					// read all the numbers of the cycle and add it to cycle.
					for(int k = a; k < b; k++) {
						LCDcycle.push_back(cycle.at(k));
					}
				}
			}
		}
	}

	if(LCDcycle.empty())
		return cycle;
	else return lowestLCDCycle(LCDcycle);	
}