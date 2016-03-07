/* Sum of Integers from File.cpp
 *
 *	TIL: .peek() != EOF (for streams/files) or string::npos is a lot more effective than simply using the variable name itself in the while loop argument.
 * 
 *
 *		
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int ASCII_CONV = 48;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string snumber;
	int number, sum = 0;

	ifilestream.open(argv[1]);

	while(ifilestream.peek() != EOF) {
		number = 0;
		getline(ifilestream, snumber);
		istringstream isstream(snumber);
		while(isstream.peek() != string::npos) {				// so apparently you can't check if the stream itself is equal to npos, but you can use peek to do so. 
			isstream >> number;
// NOT TRUE..istringstream will work just fine converting strings of anysize, including string size of 1.
		/*	if(snumber.size() == 1)									// if it's a single char, converting a stringstream to it's int equivalent will turn the the character into the ascii number value.
				isstream >> number;
			//	number = isstream.get() - ASCII_CONV; 				// otherwise if it is more than a single character, that is a string of numbers, it will convert the numbers appropriately.
			else isstream >> number; */
			sum += number;
		}
	}
	cout << sum;

	ifilestream.close();

	return 0;
}


// NOT TRUE!!!
// TIL: Converting a istringstream to an int will do so correctly if the number is more than a single digit. If not, it will convert the single digit into its ascii digit.
// If so, you need to instead subtract the ASCII difference (48) to obtain the actual number.