/* Reverse and Add.cpp
 *
 * The program is as follows: choose a number, reverse its digits and add it to the original. If the sum is not a palindrome
 * (which means, it is not the same number from left to right and right to left), repeat this procedure
 *
 * 195 (initial number) + 591 (reverse of initial number) = 786
 * 
 * 786 + 687 = 1473
 *
 * 1473 + 3741 = 5214
 * 
 * 5214 + 4125 = 9339 (palindrome)
 *
 * In this particular case the palindrome 9339 appeared after the 4th addition. This method leads to palindromes in a few step for almost all of the integers.
 * But there are interesting exceptions. 196 is the first number for which no palindrome has been found. It is not proven though, that there is not such a palindrome.
 *
 * Input sample:
 *
 * Your program should accept as its first argument a path to a filename. Each line in this file is one test case. Each test case will contain an integer < 4,294,967,295.
 * Assume each test case will always have an answer and that it is computable with less than 1000 iterations (additions).
 *
 * Ouput sample:
 *
 * 4 9339 (for each line)
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string find_palindrome(string snumber, int &additions);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snum, palindrome;
	int additions;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		additions = 0;
		getline(ifilestream, snum);
	
		palindrome = find_palindrome(snum, additions);
		if(first) {
			first = false;
			cout << additions << " " << palindrome;
		}
		else cout << endl << additions << " " << palindrome;
	}

	ifilestream.close();

	return 0;
}

string find_palindrome(string snumber, int &additions) {
//start with a string
	//create reverse string
	string rsnumber, ssum;
	unsigned int number, rnumber, sum;

	rsnumber.clear();
	for(int i = 0 ; i < snumber.size(); i++) {
		rsnumber += snumber.at(snumber.size() - 1 - i);
	}

	// convert both to numbers
	istringstream isstream(snumber);
	isstream >> number;
	isstream.clear();
	isstream.str(rsnumber);
	isstream >> rnumber;

	// add numbers up
	sum = number + rnumber;
	additions++;

	//convert back to string
	ostringstream osstream;					//can't put the value into parenthesis, that's istringstream style.
	osstream << sum;
	ssum = osstream.str();
	//test for palindrome
	for(int j = 0; j < ssum.size()/2; j++) {			// sum.size()/2 because you only need up to compare to the middle value. if size is odd, it doesn't compare the middle value (doesn't need to).
		if(ssum.at(j) != ssum.at(ssum.size() - 1 - j)) {
			ssum = find_palindrome(ssum, additions);
			break;
		}
	}

	return ssum;
	//union it? can't because the zeroes will mess it up - already seems like more work
}