/* Prime Numbers.cpp
 *
 * Print out the prime numberss less than a given number N. For bonus points your solution should run in
 * N*(log(N)) time or better. You may assume that N is always a positive integer.
 *
 * Input sample:
 *
 * Your program should accept as its first argument a path to a filename. Each line in this file is one test case.
 * Each test case will contain an integer n < 4,294,967,295.
 *
 * 10
 * 20
 * 100
 *
 * Output sample:
 * 
 * For each line of input, print out the prime numbers less than N, in ascending order, comma delimited.
 *
 * 2,3,5,7
 * 2,3,5,7,11,13,17,19
 * ...
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snum;
	unsigned int num;
	set<unsigned int> nonprimes;
	vector<unsigned int> primes;
	bool first = true, firstn;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, snum);
		istringstream isstream(snum);
		isstream >> num;
		nonprimes.clear();
		primes.clear();
		
		//getting primes.
		for(unsigned int i = 2; i <= num; i++) { //O(N)
			if(nonprimes.find(i) == nonprimes.end()) { //O(logN)?
				//start at the number itself, since everthing below is already in the set. it is a prime.
				for(unsigned int j = i; j <= num/i; j++) { //O(N)
					nonprimes.insert(j*i); // O(logN)?		//there's redundancy, but getting rid of the redundancy before hand is more work than just having the set check if it exists within the set.
				}
				primes.push_back(i);
			}
		}

		//printing portion
		firstn = true;
		if(first) {
			first = false;
			for(int j = 0; j < primes.size(); j++) {
				if(firstn) {
					firstn = false;
					cout << primes.at(j);
				}
				else cout << "," << primes.at(j);
			}
		}
		else {
			for(int j = 0; j < primes.size(); j++) {
				if(firstn) {
					firstn = false;
					cout << endl << primes.at(j);
				}
				else cout << "," << primes.at(j);
			}
		}
	}

	ifilestream.close();

	return 0;
}



// for loop to N
// add all multiples up to N to exclusion set...(this is another for loop on the scale of N/the number.) still N2...?

//for(int i = 1, i <= N, i++) {
//check if i is in set, if it is, then skip the next step (binary search - logN)
	//for loop all multiples of i up to N and add to exclusion set (N/i)
	//if it is not, add to prime, and.
// once this is all one, you have your list of primes.
//}