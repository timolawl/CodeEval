/* Testprogram.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);

	while(ifs.peek() != EOF) {
		cout << ifs.rdbuf();
	}

	ifs.close();

	return 0;

}