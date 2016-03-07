/* Sum to Zero.cpp
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int sum_to_zero(vector<int> sum_array, const vector<int> &array, set<int> used_positions, int position);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sarray, snum;
	int num, total, position;
	istringstream isstream;
	vector<int> array, sum_array;
	set<int> used_positions;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, sarray);

		array.clear();
		snum.clear();
		used_positions.clear();
		sum_array.clear();
		array.clear();

		//convert to integer form
		for(int i = 0; i < sarray.size(); i++) {
			if((sarray.at(i) != ',')) {
				snum += sarray.at(i);
			}
			else if(!snum.empty()) {
				isstream.clear();
				isstream.str(snum);
				isstream >> num;
				array.push_back(num);
				snum.clear();
			}
		}
		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			array.push_back(num);
			snum.clear();
		}

		//use recursion to block out numbers? or use for loops to block out numbers? block out and add the four remaining - if the four remaining equals 
		//recursion with a for loop to access different elements.
		//if it ends before 4 items, just return 0, if it ends with 4 elements, if the sum is 4, return 1, otherwise return 0, 
		position = 0;
		total = sum_to_zero(sum_array, array, used_positions, position);

		if(first) {
			first = false;
			cout << total;
		}
		else cout << endl << total;

	}

	ifilestream.close();

	return 0;
}

int sum_to_zero(vector<int> sum_array, const vector<int> &array, set<int> used_positions, int position) {
	//if the array size equals 4, add up the elements: if 0, return true, if not 0, return false.
	int total_combinations = 0, combinations = 0, sum = 0;
	if(sum_array.size() == 4) {
		for(int i = 0; i < sum_array.size(); i++) {
			sum += sum_array.at(i);
		}
		return (sum == 0) ? 1 : 0;
	}
	else {
		//add one element at a time and exclude from future use by the same chain.
		for(int i = position; i < array.size(); i++) {
			if(used_positions.find(i) == used_positions.end()) {
				sum_array.push_back(array.at(i));
				//excludes i in the future from this chain.
				used_positions.insert(i);
				combinations = sum_to_zero(sum_array, array, used_positions, i + 1);	// positions keeps out the counting of overlaps.
				//resets the chain and removes the used position so that the for loop can add in a different element
				sum_array.pop_back();
				used_positions.erase(i);
			}
			//sum up combinations here.
			total_combinations += combinations;
			
		}
	}

	return total_combinations;

}