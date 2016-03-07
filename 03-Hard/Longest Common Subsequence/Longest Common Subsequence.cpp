/* Longest Common Subsequence.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string lcs(const string &l1, const string &l2, const int &p1, const int &p2);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string line1, line2, test, longest;
	bool first = true;
	vector<string> matching;


	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, line1, ';');
		getline(ifilestream, line2);

		matching.clear();
		test.clear();

		longest = lcs(line1, line2, 0, 0);
/*
		for(int i = 0; i < line1.size(); i++) {
			for(int j = 0; j < line2.size(); j++) {
				if(line1.at(i) == line2.at(j)) {
					// at this point what you want to do is seek down the string (doesn't matter which one really) and find if they possess the next character in string 1
					test += line1.at(i);
				}
				else if(!test.empty()) {
					matching.push_back(test);
					test.clear();
				}
			}
			if(!test.empty()) {
				matching.push_back(test);
				test.clear();
			}
		}
		if(!test.empty()) {
			matching.push_back(test);
			test.clear();
		}

		//iterate through matching to find the longest string.
		longest = matching.at(0);
		for(int k = 0; k < matching.size(); k++){
			if(matching.at(k).size() > longest.size()) {
				longest = matching.at(k);
			}
		}
*/
		if(first) {
			first = false;
			cout << longest;
		}
		else cout << endl << longest;
	}


	ifilestream.close();

	return 0;
}

//recursive function to return matching characters

//nested for loop to find a matching character each time, except the starting location is following both found members in both strings.
//what do i need, you need the starting position for the string1 and starting position for string2

string lcs(const string &l1, const string &l2, const int &p1, const int &p2) {
	string common = "", longest = "";
	vector<string> subsequences;

	subsequences.clear();

	for(int i = p1; i < l1.size(); i++) {
		for(int j = p2; j < l2.size(); j++) {
			if(l1.at(i) == l2.at(j)) {
				common = l1.at(i);
				common += lcs(l1, l2, i + 1, j + 1);
				subsequences.push_back(common);
				common.clear();
			}
		}
	}

	if(!subsequences.empty()) {
		//use the largest subsequence
		longest = subsequences.at(0);
		for(int k = 0; k < subsequences.size(); k++) {
			if(longest.size() < subsequences.at(k).size()) {
				longest = subsequences.at(k);
			}
		}
	}

	return longest;
}