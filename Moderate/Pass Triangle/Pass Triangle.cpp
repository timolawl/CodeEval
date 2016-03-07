/* Pass Triangle.cpp
 *
 * Top-down recursion.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int largest_chain(const vector<vector<int> > &tri, const int &c, const int &r, const int &total_r);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string line, snum;
	int num, column, row, total_rows, total;
	istringstream isstream;
	vector<int> line_numbers;
	vector<vector<int> > triangle;

	ifilestream.open(argv[1]);

	row = 0;
	column = 0;
	total = 0;
	total_rows = 0;

	while(ifilestream.peek() != EOF) {
		getline(ifilestream, line);
		total_rows++;
		line_numbers.clear();

		//input the numbers into a vector.
		for(int i = 0; i < line.size(); i++) {
			if(isdigit(line.at(i))) {
				snum += line.at(i);
			}
			else if(!snum.empty()) {
				isstream.clear();
				isstream.str(snum);
				isstream >> num;
				line_numbers.push_back(num);
				snum.clear();
			}
		}

		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			line_numbers.push_back(num);
			snum.clear();
		}
		//then feed the numbers into an vector of vectors. make sure to remember the size for the recursive function
		triangle.push_back(line_numbers);
	}

	// once all the numbers have been fed, call a recursive function to go through the entire list and keep the highest number.
	total = largest_chain(triangle, column, row, total_rows);

	cout << total;
		
	ifilestream.close();

	return 0;
}

int largest_chain(const vector<vector<int> > &tri, const int &c, const int &r, const int &total_r) { 
	int sum, sum1, sum2;

	//add current value
	sum = (tri.at(r)).at(c);

//	cout << r << " " << total_r << " " << tri.at(r).at(c) << endl;


	//simple case ending
	if(r == total_r - 1) {
		return sum;
	}
	//propagate if it's not the last row
	sum1 = sum + largest_chain(tri, c, r + 1, total_r);
	sum2 = sum + largest_chain(tri, c + 1, r + 1, total_r);

	//cout << sum1 << " " << sum2 << endl;

	if(sum1 > sum2) {
		return sum1;
	}
	else return sum2;

}