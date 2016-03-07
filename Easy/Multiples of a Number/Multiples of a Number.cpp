/* Multiples of a Number.cpp 
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <cmath> // pow(b, e)
#include <climits> // INT_MAX
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int num1, num2, num, compare = 0;
	string snum1, snum2;
	ifstream input_stream; // input FROM the stream. for output, it is output INTO the stream. Reference is action onto the stream. Same for extraction and insertion operators.
	vector<int> answer_store;

	input_stream.open(argv[1]); // so this works apparently.

	while(input_stream) {
		num1 = 0, num2 = 0, num = 0, compare = 0;

		getline(input_stream, snum1, ',');		// getline places the content of the stream in strings in this getline form.
		istringstream isstream1(snum1);
		isstream1 >> num1;
	//	isstream1.clear();						// I don't think this is needed actually, since it only clears error states.
		getline(input_stream, snum2, '\n');
		istringstream isstream2(snum2);
		isstream2 >> num2;
	//	isstream2.clear();
		num = (num1 > num2) ? num1 : num2;
		for(int i = 0; i < INT_MAX; i++) {		// INT_MAX requires climits
			compare = pow(2, i);
			if(compare > num) {
				answer_store.push_back(compare);
				break;
			}
		}
	}

	for(int j = 0; j < answer_store.size(); j++)
		cout << answer_store.at(j) << endl;

	input_stream.close();

	return 0;
}