/* Following Integer (redone).cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

inline const std::vector<int> create_digit_map(const std::string &s_digits);

int main(int argc, char * argv[]) {
	std::ifstream ifs;
	std::string line;
	int number, max = 999999;
	std::vector<int> N_digit_map, j_digit_map;	// 10 elements, all set to zero.
	bool first = true;

	ifs.open(argv[1]);

	while(ifs.peek() != EOF) {
		line.clear();
		N_digit_map.clear();

		getline(ifs, line);

		std::istringstream iss(line);
		iss >> number;

		//for each number in N, put those numbers into a vector<int> that keeps track of how many of each.
		N_digit_map = create_digit_map(line);
		//generate the set of numbers that it potentially can be? // so generate all potential combinations?
		//generate the set by verifying the number with the vector<int> profile of the number. if it fits, then add it to the set.
		for(int j = number + 1; j < max; j++) {
			j_digit_map.clear();
			std::ostringstream oss;
			oss << j;
			j_digit_map = create_digit_map(oss.str());
			if(j_digit_map == N_digit_map) {
				if(first) {
					first = false;
					std::cout << j;
				}
				else std::cout << std::endl << j;
				break;
			}
		}
		//how to check? 
	}
}


inline const std::vector<int> create_digit_map(const std::string &s_digits) {
	std::vector<int> digit_count (9, 0);

	for(int i = 0; i < s_digits.size(); i++) {
		switch(s_digits.at(i)) {
			case '1':
				digit_count.at(0)++;
				break;
			case '2':
				digit_count.at(1)++;
				break;
			case '3':
				digit_count.at(2)++;
				break;
			case '4':
				digit_count.at(3)++;
				break;
			case '5':
				digit_count.at(4)++;
				break;
			case '6':
				digit_count.at(5)++;
				break;
			case '7':
				digit_count.at(6)++;
				break;
			case '8':
				digit_count.at(7)++;
				break;
			case '9':
				digit_count.at(8)++;
				break;
		}
	}

	return digit_count;
}