/* Pascals Triangle.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int pascalnum(int row, int col);
void pascalrow(int r, bool &f);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN;
	int N;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sN);
		istringstream isstream(sN);
		isstream >> N;

		pascalrow(N, first);

	}

	ifilestream.close();
}

int pascalnum(int row, int col) {
	if(row == 0 || row == 1 || col == 0 || col == row) {
		return 1;
	}
	else {
		return pascalnum(row - 1, col - 1) + pascalnum(row - 1, col);
	}
}

void pascalrow(int r, bool &f) {
	for(int i = 0; i < r; i++) {
		if(i == 0) {
			if(f) {
				f = false;
				cout << pascalnum(0,0);
			}
			else cout << endl << pascalnum(0,0);
		}
		else {
			for(int j = 0; j <= i; j++) {
				cout << " " << pascalnum(i, j);
			}
		}
	}
}