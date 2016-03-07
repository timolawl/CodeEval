/* Decode Numbers.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>


using namespace std;

int ways_to_decode(string &m, int &position);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string message;
	int number_of_ways, position;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, message);
		position = 0;
		number_of_ways = 0;
		
		number_of_ways = ways_to_decode(message, position);
		if(first) {
			first = false;
			cout << number_of_ways + 1;
		}
		else cout << endl << number_of_ways + 1;
	}

	ifilestream.close();
}

int ways_to_decode(string &m, int &position) {
	int ways = 0;

	for(int i = position; i < m.size(); i++) {
		if(m.at(i) <= '2' && i + 1 < m.size() && m.at(i + 1) < '7') {
			ways++;
			position += 2;
			ways += ways_to_decode(m, position);
		}
	}
	return ways;
}