/* Double Squares.cpp
 *
 *	Credits: This challenge appeared in the Facebook Hacker Cup 2011.
 *
 *	A double-square number is an integer X which can be expressed as the sum of two perfect squares.
 *	For example, 10 is a double-square because 10 = 3^2 + 1^2. Your task in this problem is, given X,
 *	determine the number of ways in which it can be written as the sum of two squares. For example, 
 *	10 can only be written as 3^2 + 1^2 (we don't count 1^2 + 3^2 as being different). On the other
 *	hand, 25 can be written as 5^2 + 0^2 or as 4^2 + 3^2.
 *
 *	NOTE: Do NOT attempt a brute force approach. It will not work. The following constraints hold:
 *		0 <= X <= 2147483647
 *		1 <= N <= 100
 *	
 *	Input sample:
 *	You should first read an integer N, the number of test cases. The next N lines will contain N values of X.
 *
 * 	5
 *	10
 *	25
 *	3
 *	0
 *	1
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN, sX;
	int N, ds_count;
	double X;
	bool first = true;
	set<int> exclusion_set;

	ifilestream.open(argv[1]);
	getline(ifilestream, sN);
	istringstream isstream(sN);
	isstream >> N;

	while(ifilestream.peek() != EOF) {

//		sX.clear();
		getline(ifilestream, sX);

		exclusion_set.clear();

		isstream.clear();
		isstream.str(sX);
		isstream >> X;	//2147483647

		//if last number, then there can only be the leftover N left as the solution.
/*		if(ifilestream.peek() == EOF) {
			if(first) {
				cout << N;
				first = false;
			}
			else cout << endl << N;
			break;
		}
*/
		ds_count = 0;
		// setting the limit to largest_root
		for(int i = 0; i <= sqrt(X/2); i++) {

			// if this condition is satisified, then we have a double-square resulting in X.
			if(sqrt(X - i*i) == floor(sqrt(X - i*i)) && exclusion_set.find(i) == exclusion_set.end()) {
				ds_count++;
				exclusion_set.insert(i);
				exclusion_set.insert(sqrt(X - i*i));
		//		cout << "  " << ds_count << "  " << i << "  " << sqrt(X - i*i) << "  " << endl;
			}
		}
		//cout << endl;
		
		if(first) {
			cout << ds_count;
			first = false;
		}
		else {
			cout << endl << ds_count;
		}
		
		N -= ds_count;
	
	}

	ifilestream.close();

	return 0;
}