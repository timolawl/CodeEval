/* Odd Numbers.cpp
 *
 *
 *
 */

#include <iostream>

int main() {
	bool first = true;

	for(int i = 1; i <= 99; i++) {
		if(i % 2 != 0) {
			if(first) {
				std::cout << i;
				first = false;
			} else std::cout << std::endl << i;
		}
	}

	return 0;
}