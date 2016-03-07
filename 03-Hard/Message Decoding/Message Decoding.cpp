/* Message Decoding.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

void generate_message(const std::map<std::string, char> &kc_map, std::string &nums, std::string &nascent_message);

int main(int argc, char *argv[]) {
	std::ifstream ifs;
	std::string line, characters, numbers, binary_string, message;
	std::map<std::string, char> key_character_map;
	int binary_value;
	bool last_binary, first = true;

	ifs.open(argv[1]);

	while(ifs.peek() != EOF) {
		
		characters.clear();
		numbers.clear();
		key_character_map.clear();
		message.clear();

		getline(ifs, line);
		//read all the non-numerics into a string.
		//read the numbers into another string
		for(int i = 0; i < line.size(); i++) {
			if(!isdigit(line.at(i))) {
				characters += line.at(i);
			}
			else numbers += line.at(i);
		}

		//map the numbers to the characters
		//considerations: size and binary sequence (convert the numeric to binary, put into string)
		binary_string = "0";
		
		for(int i = 0; i < characters.size(); i++) {
			//if the next binary is all 1's, add another digit and start from 0.
			//current size 1. (just change the last digit to 1, if it means the string is all 1's, then condition is satisfied)
			//restart the binary count when this happens.
			//assign binary number to character
			last_binary = true;

			key_character_map[binary_string] = characters.at(i);

			//check if it is the last binary by checking all prior digits except the last
			for(int j = 0; j < binary_string.size() - 1; j++) {
				if(binary_string.at(j) == '0') {
					last_binary = false;
					break;
				}
			}
			//if it is the last binary in the series, reset binary to zeros + an extra zero.
			if(last_binary) {
				for(int i = 0; i < binary_string.size(); i++) {
					binary_string.at(i) = '0';
				}
				binary_string += '0';
			}
			//else convert the number to binary, add one, and reconvert back to binary.
			else {
				binary_value = 0;
				for(int i = 0; i < binary_string.size(); i++) {
					if(binary_string.at(i) == '1') {
						binary_value += pow(2, binary_string.size() - i - 1);
					}
				}
				binary_value++;
				for(int i = 0; i < binary_string.size(); i++) {
					if(binary_value - pow(2, binary_string.size() - i - 1) >= 0) {
						binary_string.at(i) = '1';
						binary_value -= pow(2, binary_string.size() - i - 1);
					}
					else binary_string.at(i) = '0';
				}
			}
			//binary_string has been set to thr right value, for the next value.
			//running through the for loop should add the keys appropriately now.
		}

		generate_message(key_character_map, numbers, message);


		if(first) {
			first = false;
			std::cout << message;
		}
		else {
			std::cout << std::endl << message;
		}

	}

	ifs.close();

	return 0;
}

void generate_message(const std::map<std::string, char> &kc_map, std::string &nums, std::string &nascent_message) {
	int codon_size;
	std::string codon, stop_codon, message_terminator;
	bool stop_codon_reached;

	message_terminator = "000";

//read 3 digits and set codon size:
	codon_size = 0;
	for(int i = 0; i < 3; i++) {
		if(nums.at(i) == '1') {
			codon_size += pow(2, 2 - i);	// reading from left-to-right, therefore needed an adjustment.
		}
	}

	if(codon_size == 0) {
		return;
	}

	nums.erase(0, 3);	//erase the first 3 characters in the string

	//determine stop codon;
	stop_codon.clear();
	for(int i = 0; i < codon_size; i++) {
		stop_codon += '1';
	}


	//if stop codon is reached, go back above, otherwise keep reading.
	stop_codon_reached = false;
	
	while(!stop_codon_reached && !nums.empty()) {
		int i = 0;
		codon.clear();

		//check if terminator:
		if(nums.size() == 3) {
			if(nums == message_terminator) {
				return;
			}
		}

		codon += nums.at(i);
		while(codon.size() < codon_size) {
			i++;
			codon += nums.at(i);
		}

		//compare codon with stop codon
		if(codon == stop_codon) {
			stop_codon_reached = true;
		}
		else {
			//iterator to iterate through the map to find the string?
			std::map<std::string, char>::const_iterator iter;
			for(iter = kc_map.begin(); iter != kc_map.end(); iter++) {
				if(codon == iter->first) {
					nascent_message += iter->second;
					break;
				}
			}
		}
		nums.erase(0, codon_size);
	}

	if(stop_codon_reached) {
		generate_message(kc_map, nums, nascent_message);
	}
}