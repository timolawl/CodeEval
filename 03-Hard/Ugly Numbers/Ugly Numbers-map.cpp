/* Ugly Numbers.cpp
 *
 * string::insert inserts before the position, not after.
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
//#include <ctime>
//#include <cstdlib>

using namespace std;

map<string, int> generateMap(const string &nums, const map<string, int> &source_map, const int &operations);
int determineUgliness(const map<string, int> &expressions);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string numbers;
	map<string, int> operator_applied_map, final_map;
	int results;
	bool first = true;
	//time_t begin;
	//double seconds;

//	time(&begin);
//	begin = now;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, numbers);
		
		if(numbers.size() >= 12) break;

		operator_applied_map.clear();

		//first case
		operator_applied_map[numbers] = 1;	// 1 meaning that the first point of insertion is at position 1.
		
		//generate map of all operator-applied strings.
		final_map = generateMap(numbers, operator_applied_map, 0);	// 0 meaning zero operations applied so far.
		
		//apply operations in numeric form
		results = determineUgliness(final_map);

		if(first) {
			first = false;
			cout << results;
		}
		else cout << endl << results;
	}

	ifilestream.close();

	return 0;
}

//create a map with operators applied to the number.
map<string, int> generateMap(const string &nums, const map<string, int> &source_map, const int &operations) {
	string unapplied;
	map<string, int> target_map, final_map;

//	clock_t new_time;

	//simple case
	if(operations == nums.size() - 1) {
		return source_map;
	}

	//develop cases
	for(map<string, int>::const_iterator it = source_map.begin(); it != source_map.end(); it++) {
		
		//apply plus
		unapplied = it->first;
		unapplied.insert(it->second, "+");					// don't use mapvar[key] notation for value. simply use it->second.
		target_map[unapplied] = it->second + 2;

		//apply minus
		unapplied.clear();
		unapplied = it->first;
		unapplied.insert(it->second, "-");
		target_map[unapplied] = it->second + 2;
		
		//apply anneal
		target_map[it->first] = it->second + 1;
	}
	
	final_map = generateMap(nums, target_map, operations + 1);
/*
	new_time = clock() - t;

	if(new_time/CLOCKS_PER_SEC >= 2.0) {
		exit(EXIT_FAILURE);
	}*/
//	cout << new_time/CLOCKS_PER_SEC << endl; 


	return final_map;
}

//calculate result from expression and determine ugliness of number.
int determineUgliness(const map<string, int> &expressions) {
	queue<int> numbers;
	queue<char> operators;
	string test_string, snum;
	int num, result, num2, ugly;
	char op;
	istringstream isstream;
	double seconds;
	//time_t now;
	//time(&now);

	ugly = 0;

//	seconds = difftime(now, begin);

	for(map<string, int>::const_iterator it = expressions.begin(); it != expressions.end(); it++) {
		test_string = it->first;

		//put numbers and operators into their respective queues
		for(int i = 0; i < test_string.size(); i++) {
			if(isdigit(test_string.at(i))) {
				snum += test_string.at(i);
			}
			else {
				if(!snum.empty()) {
					isstream.clear();
					isstream.str(snum);
					isstream >> num;
					numbers.push(num);
					snum.clear();
				}
				op = test_string.at(i);
				operators.push(op);
			}
		}
		if(!snum.empty()) {
			isstream.clear();
			isstream.str(snum);
			isstream >> num;
			numbers.push(num);
			snum.clear();
		}

		//apply operations in the expression. (assuming there is more than one number).
		result = numbers.front();
		numbers.pop();
		while(!numbers.empty()) {
			num2 = numbers.front();
			numbers.pop();

			//apply the operators.
			op = operators.front();
			operators.pop();
			if(op == '+') {
				result += num2;
			}
			else if(op == '-') {
				result -= num2;
			}
		}

		//determine ugliness:
		if(result % 2 == 0 || result % 3 == 0 || result % 5 == 0 || result % 7 == 0) {
			ugly++;
		}
	
	}

	return ugly;
}