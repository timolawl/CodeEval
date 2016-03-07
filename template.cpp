/* 
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;

	ifilestream.open(argv[1]);

	ifilestream.close();

	return 0;
}