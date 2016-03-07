/* Multiplication Tables.cpp
 *
 *
 *
 */

#include <iostream>
#include <iomanip> // for setw().

using namespace std;

const int MAX_SIZE = 12;

int main() {

	for(int row = 1; row <= MAX_SIZE; row++)
		for(int col = 1; col <= MAX_SIZE; col++) {
			if(col == MAX_SIZE && row != MAX_SIZE)
				cout << setw(4) << row * col << endl;
			else cout << setw(4) << row * col;
		}


	return 0;
}