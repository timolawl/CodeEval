/* Sudoku.cpp
 *
 * See sudoku regular for notes.
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sN, smatrix, snum;
	int N, num, count, a, b, sum;
	bool first = true, condition;
	set<int> elements, set_of_N, test;
	vector<vector<int> > matrix;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		condition = true;
		//get data
		getline(ifilestream, sN, ';');
		getline(ifilestream, smatrix);

		//convert data into numeric form
		istringstream isstream(sN);
		isstream >> N;
		//declaring the matrix once N is known.
//		int matrix[N][N];

		a = 0, b = 0;

		set_of_N.clear();
		for(int i = 0; i < N; i++) {
			set_of_N.insert(i+1);
		}

		snum.clear();

		while(!smatrix.empty()) {
			//keep track of matrix position
			if(b > N - 1) {
				b = 0;
				a++;
			}
			if(isdigit(smatrix.at(0))) {
				snum += smatrix.at(0);
			}
			else if(!snum.empty()) {
				isstream.clear();
				isstream.str(snum);
				isstream >> num;
				snum.clear();
				(matrix.at(a)).push_back(num);
					cout << "testing" << endl;
				b++;
			}
			smatrix.erase(0, 1);
		}
		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			snum.clear();
			(matrix.at(a)).push_back(num);
			b++;
		}	

		//3 conditions for sudoku solution:
		//all the numbers add up to the same value. / test row.
		for(int i = 0; i < N; i++) {
			sum = 0;
			for(int j = 0; j < N; j++) {
				sum += (matrix.at(i)).at(j);
			}
			if(sum != N*(N+1)/2) {
				condition = false;
				break;
			}
		}

		// column
		for(int k = 0; k < N; k++) {
			sum = 0;
			for(int l = 0; l < N; l++) {
				sum += (matrix.at(l)).at(k);
			}
			if(sum != N*(N+1)/2) {
				condition = false;
				break;
			}
		}

		//all numbers in a row or col are unique (or the sum of the squares are equal to the above as well)
		if(condition) {
			for(int i = 0; i < N; i++) {
				elements.clear();
				test.clear();
				for(int j = 0; j < N; j++) {
					elements.insert((matrix.at(i)).at(j));
				}
				set_difference(set_of_N.begin(), set_of_N.end(), elements.begin(), elements.end(), inserter(test, test.begin()));
				if(!test.empty()) {
					condition = false;
					break;
				}

			}
		}
		//all numbers must be less than or equal to N.
		if(condition) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if((matrix.at(i)).at(j) < 1 || (matrix.at(i)).at(j) > N) {
						condition = false;
						break;
					}
				}
				if(!condition) break;
			}
		}

		if(first) {
			first = false;
			if(condition) {
				cout << "True";
			}
			else cout << "False";
		}
		else if(condition) {
			cout << endl << "True";
		}
		else cout << endl << "False";

	}

	ifilestream.close();

	return 0;
}