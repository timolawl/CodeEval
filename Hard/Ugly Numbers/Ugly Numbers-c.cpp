/* Ugly Numbers-c.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

//can't use map because what will be the key? the product? there's going to be multiple since 
//when am i going to anneal?
//make a class with string and position, which you'll be inserting into a set.


int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string numbers;
	

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, numbers);
	}

	ifilestream.close();

	return 0;
}