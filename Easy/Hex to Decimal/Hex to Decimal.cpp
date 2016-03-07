/* Hex to Decimal.cpp
 *
 * TIL: So far:
 * 		1. insertion of streams to convert numbers from different bases require a base decimal value before converting to hex and oct.
 *				example: the int number must already be in decimal form before converting to hex or oct via cout << hex << number; cout << oct << number;
 *				furthermore, using << hex or << oct sets the stream to take on values in this form. You must << dec to switch it back to read and put out decimal numbers.
 *		2. extraction of a stream, the number can be in any base, but if you want the decimal form, you have to redo the base
 *				example: isstream has a hex number -> isstream >> hex >> number; will turn the hex number into a decimal number.
 *		3. Summary:
 *				Extraction from a stream -> is >> any base >> base_type >> number variable
 *					Converts the number from base -> dec_base;
 *				Insertion to a stream -> os << base_type << number variable
 *					Converts the number from decimal to the base_type.
 *		4. What does showbase do?
 *	
 *		ONLY THE CASE because .setf() for the stream (in this case, cout) has it's ios::base set to decimal. If you change this base, then you can input hex as hex and convert it to another base
 *			without going through decimal.
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	int hex_num, number;
	string shex_num;
	ifstream ifilestream;
	istringstream isstream;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		isstream.clear();
		getline(ifilestream, shex_num);
		isstream.str(shex_num);
		isstream >> hex >> hex_num; 		// why does this conver the hex format to decimal? 
		if(first) {
			cout << hex_num;
			first = false;
		} else cout << endl << hex_num;
	}

	ifilestream.close();

	return 0;
}