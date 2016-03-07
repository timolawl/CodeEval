/* Lowest Unique Number.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

const int UNIQUE = 1;
const int NOT_UNIQUE = 2;

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	ifilestream.open(argv[1]);
	map<int, vector<int> > tabulated_numbers;
	vector<int> uniqueness_and_position;
	int lowest_unique, value, position, unique_position;
	char c_value;
	bool first = true, uniqueness;



	while(ifilestream.peek() != EOF) {
		//skip empty lines and new lines
		while(ifilestream.peek() == '\n')
			ifilestream.ignore(1);

		tabulated_numbers.clear();
		position = 0;

		while(ifilestream.peek() != '\n' && ifilestream.peek() != EOF) {
			c_value = ifilestream.get();
			//skip spaces and null values
			if(c_value == 32 || c_value == 0) // 32 is space.
				continue;

			//convert the number in character form to integer form
			value = c_value - '0';
			position++;
			uniqueness_and_position.clear();

			uniqueness = true;
			map<int, vector<int> >::iterator it;
			//seek out if the value exists in the map already, if so, mark it as not unique in the map.
			for(it = tabulated_numbers.begin(); it != tabulated_numbers.end(); it++) {
				if(value == it->first) {
					tabulated_numbers[value].at(0) = NOT_UNIQUE;
					uniqueness = false;
					break;
				}
			}
			//if it is not in the map, then add it to the map, marking it unique
			if(uniqueness) {
				uniqueness_and_position.push_back(UNIQUE);
				uniqueness_and_position.push_back(position);
				tabulated_numbers[value] = uniqueness_and_position;
			}
		}

		lowest_unique = 10;

		map<int, vector<int> >::iterator it;
		for(it = tabulated_numbers.begin(); it != tabulated_numbers.end(); it++) {
			//if the number is unique, and it is lower than the current unique, make the lowest unique equal to this number.
			if(it->second.at(0) == UNIQUE) {
				if(lowest_unique > it->first) {
					lowest_unique = it->first;
					unique_position = it->second.at(1);
				}
			}
		}
		if(lowest_unique == 10) {
			if(first) {
				first = false;
				cout << "0";
			}
			else cout << endl << "0";
		}
		else if(first) {
			first = false;
			cout << unique_position;
		}
		else cout << endl << unique_position;

	}
	ifilestream.close();

	return 0;
}