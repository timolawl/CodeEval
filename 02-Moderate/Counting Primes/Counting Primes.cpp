/* Counting Primes.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN, sM;
	int N, M, pnum;
	bool prime = true, first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sN, ',');
		getline(ifilestream, sM);

		istringstream isstream(sN);
		isstream >> N;
		isstream.clear();
		isstream.str(sM);
		isstream >> M;

		pnum = 0;
		for(int i = N; i <= M; i++) {
			prime = true;
			for(int j = 2; j < i; j++) {
				if(i % j == 0) {
					prime = false;
				}
			}
			if(prime) {
				pnum++;
			}
		}
		if(first) {
			first = false;
			cout << pnum;
		}
		else cout << endl << pnum;
	}

	ifilestream.close();

	return 0;
}