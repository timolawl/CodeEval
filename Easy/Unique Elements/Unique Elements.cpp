/* Unique Elements.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

string getNumber(string &nums);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string numbers, lean, num1, num2, num;
	char var1, var2, temp;
	bool not_first, first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		lean.clear();
		getline(ifilestream, numbers);
		not_first = false;
		num1 = getNumber(numbers);
		num2 = getNumber(numbers);
		while(numbers != "") {
			if(num1 == num2) {
				num2 = getNumber(numbers);
			} else {
				if(not_first)
					lean += ',';
				lean += num1;
				num1 = num2;
				num2 = getNumber(numbers);
				not_first = true;
			}
		} 
		if(not_first)					// have to check for the condition where the entire list is the same number.
			lean += ',';
		lean += num1;
		if(num1 != num2) {
			lean += ',';
			lean += num2;
		}

		if(first) {
			cout << lean;
			first = false;
		}
		else cout << endl << lean;
		// get two numbers.
		// if they are equal, get the next number and erase the previous #2 by setting it equal to var2.
		// if they are not the same, store var 1 and set num2 into var1.
	}
	ifilestream.close();

	return 0;
}

string getNumber(string &nums) {
	string n;

	while(nums != "") {
		if(isdigit(nums[0])) {
			n += nums[0];
			nums.erase(0, 1);
		} else {
			nums.erase(0, 1);
			break;
		}
	}
	return n;
}