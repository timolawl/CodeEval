/* Endianness.cpp
 *
 * Big-endian = stores the most significant byte first, at the lowest byte address
 * Little-endian = stores the least significant byte first.
 */

#include <iostream>

using namespace std;

//const int BYTE = 8;

int main() {
//	unsigned int i = 1;
//	char *c = (char*)&i;
//	if(*c



	union {
		unsigned int number;
		char snum[4];
	} endian;

	endian.number = 0x01020304;
	//endian = {0x01020304};



	if(endian.snum[0] == 1)
		cout << "BigEndian";
	else cout << "LittleEndian";



	return 0;
}