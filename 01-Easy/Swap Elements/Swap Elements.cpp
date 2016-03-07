/*
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char * argv[]) {
	std::ifstream ifs;
	std::string line, s_swap_pairs, s_number, s_number1, s_number2;
	char c_num, c_num1, c_num2;
	int number, number1, number2, placeholder;
	std::vector<int> elements;
	std::vector<int> swap_pairs;
	bool first = true;

	ifs.open(argv[1]);

	while(ifs.peek() != EOF) {
		line.clear();
		elements.clear();

		getline(ifs, line);
		std::istringstream iss(line);
		while(iss.peek() != ':') {
			getline(iss, s_number, ' ');
			c_num = s_number.at(0);
			number = c_num - '0';
			elements.push_back(number);
		}

		//put in swap elements...		// damn it's my fault that i didn't prepare more. because i shot myself in the foot from the get go. i didn't want to prepare. i didnt' think i would succeed.
		// well man, you will.
		while(iss.peek() != EOF) {
			swap_pairs.clear();
			getline(iss, s_swap_pairs, ',');

			std::istringstream iss(s_swap_pairs);
			getline(iss, s_number1, '-');
			getline(iss, s_number2);
			c_num1 = s_number1.at(0);
			c_num2 = s_number2.at(0);
			number1 = c_num1 - '0';
			number2 = c_num2 - '0';
			swap_pairs.push_back(number1);
			swap_pairs.push_back(number2);
		}

		while(!swap_pairs.empty()) {
			placeholder = elements.at(swap_pairs.at(0));
			elements.at(swap_pairs.at(0)) = elements.at(swap_pairs.at(1));
			elements.at(swap_pairs.at(1)) = placeholder;
			swap_pairs.erase(swap_pairs.begin(), swap_pairs.begin() + 2);
		}

		if(first) {
			first = false;
			for(int i = 0; i < elements.size(); i++) {
				std::cout << elements.at(i) << " ";
			}
		}
		else {
			std::cout << std::endl;
			for(int i = 0; i < elements.size(); i++) {
				std::cout << elements.at(i) << " ";
			}
		}


	}

	ifs.close();
	return 0;
}