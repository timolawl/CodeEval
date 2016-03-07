/* Pass Triangle.cpp
 *
 * Bottom-Up iteration
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string line, snum;
	int num, total_rows, return_value, total;
	istringstream isstream;
	vector<int> line_numbers;
	vector<vector<int> > triangle;

	ifilestream.open(argv[1]);

	total = 0;
	total_rows = 0;
	return_value = 0;

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
		//then feed the numbers into an vector of vectors.
		triangle.push_back(line_numbers);
	}

	// iterate each row starting from the last row.
	for(int current_row = total_rows - 1; current_row > 0; current_row--) {
		for(int current_col = current_row; current_col > 0; current_col--) {
			//whichever value is bigger...
			return_value = triangle.at(current_row).at(current_col - 1) > triangle.at(current_row).at(current_col) ? triangle.at(current_row).at(current_col - 1) : triangle.at(current_row).at(current_col);

			//have the parent element absorb the larger value.
			triangle.at(current_row - 1).at(current_col - 1) += return_value;
		}
	}
	total = triangle.at(0).at(0);
	cout << total;
		
	ifilestream.close();

	return 0;
}
