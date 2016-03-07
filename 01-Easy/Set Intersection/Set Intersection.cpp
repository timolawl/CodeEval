/* Set Intersection.cpp
 *
 * TIL: Iterating through maps vs the other STL containers differ because of the two parameters of maps.
 *		To iterate through maps, use it->first, it->second.
 *		For every other use, use *it.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

string turnUnique(const string &list);
string getNumber(const string &nums, int &pos);
string sort(const string &line);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string line1, line2, store, num1, num2;
	bool first;
	bool not_first_s = false;
	int position1, position2;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		first = true;
		store.clear();
		getline(ifilestream, line1, ';'); 				// I believe getline tosses out the delimited character. Yes it does - just like it does to '\n'
		getline(ifilestream, line2);
		position1 = 0;
		while(position1 < line1.size()) {
			num1 = getNumber(line1, position1);
			position2 = 0;
			while(position2 < line2.size()) {
				 num2 = getNumber(line2, position2);
				 if(num1 == num2) {
				 	if(first) {
						store += num1;
						first = false;
					} else {
						store += ',';
						store += num1;
					}			
				 }
			}
		}
		if(not_first_s) {
			cout << endl << turnUnique(sort(store));
		} else {
			cout << turnUnique(sort(store));
			not_first_s = true;
		}
	}
	ifilestream.close();

	return 0;
}

string sort(const string &line) {				// sort with the basic function of set.
	set<string> nums;
	set<string>::iterator it;
	string sorted_line;
	bool firstn = true;
	int position = 0;
	
	while(position < line.size()) {
		nums.insert(getNumber(line, position));
	}
	for(it = nums.begin(); it != nums.end(); it++) {					// iteration style through a set.			
		if(firstn) {
			sorted_line += *it; 						
			firstn = false;
		}
		else {
			sorted_line += ',';
			sorted_line += *it;
		}
	}
	return sorted_line;
}

string turnUnique(const string &numbers) {
	string lean, num1, num2;
	bool not_first;
	int position = 0;

	lean.clear();
	not_first = false;
		num1 = getNumber(numbers, position);
		num2 = getNumber(numbers, position);
		while(position < numbers.size()) {
			if(num1 == num2) {
				num2 = getNumber(numbers, position);
			} else {
				if(not_first)
					lean += ',';
				lean += num1;
				num1 = num2;
				num2 = getNumber(numbers, position);
				not_first = true;
			}
		} 
		if(not_first)					// have to check for the condition where the entire list is the same number.
			lean += ',';
		lean += num1;
		if(num1 != num2 && num2 != "") {
			lean += ',';
			lean += num2;
		}
	return lean;
}

string getNumber(const string &nums, int &pos) {				// much better way at getting numbers!
	string n = "";

	for(int i = pos; pos < nums.size(); i++) {
		pos++;
		if(isdigit(nums[i])) {
			n+= nums[i];
		} else break;
	}

	return n;
}