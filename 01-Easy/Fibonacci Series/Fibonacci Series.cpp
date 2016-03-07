/* Fibonacci Series.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int fibonacci(int num);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	int number;
	string snumber;
	bool first = true;

	ifilestream.open(argv[1]);
	
	while(ifilestream.peek() != EOF) { // sometimes use .peek() != EOF, sometimes dont? Depends on the text file. If the text file ends exactly where it's supposed to, then just use the name itself. 
		getline(ifilestream, snumber);				// If it doesn't and there are more space-type characters for instance, you have to use .peek() != EOF, and not just that but it has to be at least two space
		istringstream isstream(snumber);			// type characters... think about how peek works.
		isstream >> number;
		if(first) {
			cout << fibonacci(number);
			first = false;
		} else cout << endl << fibonacci(number);
	}

	ifilestream.close();

	return 0;
}

int fibonacci(int num) {
	if(num == 0 || num == 1) return num;
	else return fibonacci(num - 1) + fibonacci(num - 2);
}
