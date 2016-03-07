/* File Size.cpp
 *
 * TIL: ifstream::tellg(); (once seekg or seekp(0, ifstream::end)) will give you the size of the text file.
 *
 */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	int length;
	std::ifstream ifilestream;

	ifilestream.open(argv[1]);
	ifilestream.seekg(0, ifilestream.end);
	length = ifilestream.tellg();

	std::cout << length;

	ifilestream.close();

	return 0;
}