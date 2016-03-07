/* JSON menu IDs.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	string line, s_label_number;
	int marker_position, label_number, sum_of_labels;
	vector<int> marker_positions;
	bool first = true, position_empty = false;

	while(ifilestream.peek() != EOF) {
		while(ifilestream.peek() == '\n')
			ifilestream.ignore(1);

		position_empty = false;
		marker_positions.clear();
		marker_position = 0;
		sum_of_labels = 0;

		getline(ifilestream, line);

		//obtain the positions
		while(marker_position < line.size() - 1) {
			if(marker_position != 0) {
				marker_position = line.find("Label", marker_position+1);
				if(marker_position != string::npos) {
					marker_positions.push_back(marker_position);
				}
			}
			else {
				marker_position = line.find("Label");
				if(marker_position != string::npos) {
					marker_positions.push_back(marker_position);
				}
			}

			if(marker_positions.empty()) {
				position_empty = true;
				if(first) {
					first = false;
					cout << "0";
				}
				else cout << endl << "0";
				break;
			}
		}
		//obtain the numbers
		for(int i = 0; i < marker_positions.size(); i++) {
			s_label_number.clear();
			label_number = 0;
			int j = 0;

			while(line.at(marker_positions.at(i) + 5 + j) != '"') {
				if(isdigit(line.at(marker_positions.at(i) + 5 + j)))
					s_label_number += line.at(marker_positions.at(i) + 5 + j);
				j++;
			}
			
			istringstream convert(s_label_number);
			convert >> label_number;
			sum_of_labels += label_number;
		}

		if(!position_empty) {
			if(first) {
				first = false;
				cout << sum_of_labels;
			}
			else cout << endl << sum_of_labels;
		}
	}

	ifilestream.close();

	return 0;

}