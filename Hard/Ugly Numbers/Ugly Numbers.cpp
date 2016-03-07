/* Ugly Numbers.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string numbers;
	set<string> combinations, finalset;
	int uglies;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, numbers);
		
		combinations.insert('+');
		combinations.insert('-');
		combinations.insert(' ');
		//generate the different combinations possible and store it based off the size of numbers.
		finalset = generateCombinations(combinations, combinations, numbers, 1);

		//apply the combinations to the number and produce the result.
		uglies = applyCombinations(finalset);
		//



	}


	ifilestream.close();

	return 0;
}

//recursive function

set<string> generateCombinations(set<string> initial, set<string> developing, string nums, int current_size) {
	string temp;
	set<string> new_set, final_set;

	if(current_size == nums.size() - 1) {
		return developing;
	}

	for(set<string>::iterator it1 = developing.begin(); it1 != developing.end(); it1++) {
		for(set<string>::iterator it2 = initial.begin(); it2 != initial.end(); it2++) {
			temp = *it1 + *it2;
			new_set.insert(temp);
		}	
	}

	final_set = generateCombinations(initial, new_set, nums, current_size + 1);

	return final_set;
}

//generate the different combinations possible and store it in a something (doesn't matter, i dont think)
// apply the combinations to the number and produce the result
//test the result for ugliness

int applyCombinations(set<string> combos, string nums) {
	string combo, combo_applied_nums, annealed;
	vector<int> numbers;

	//have to set up the entire thing first - generate string?
	for(set<string>::iterator it = combos.begin(); it != combos.end(); it++) {
		combo = *it;
		for(int i = 0; i < combo.size(); i++) {
			//numbers reduced by one.
			if(combo.at(i) == ' ') {
				annealed = nums.at(i) + nums.at(i + 1);
				combo_applied_nums
				i--;
			}
			else if(combo.at(i) == '+') {
				if(!annealed.empty()) {
					combo_applied_nums += annealed;
					combo_applied_nums += '+';
					annealed.clear();
				}
				else {
					combo_applied_nums += '+';
					combo_applied_nums += nums.at(i + 1);
				}
			}
			else if(combo.at(i) == '-') {
				combo_applied_nums += '-';
				if(!annealed.empty()) {
					combo_applied_nums += annealed;
					combo_applied_nums += '-';
					annealed.clear();
				}
				else {
					combo_applied_nums += '-';
					combo_applied_nums += nums.at(i + 1);
				}
			}
		}
	}

	//after set up, then interpret (first do anneals, then do the addition/subtraction)
	//anneal at position 0 means position 0 and position 1 annealed together

	// once all the anneals have been finished, separate the string into its (vector<int>) numbers and apply the operators from left to right.

}

//generate
	//as long as there is room between letters
	//you may apply some operation + - or anneal.

	//using each string in the set

use map?

	apply_plus, apply_minus, apply_anneal;
	tempp

position indicator // if position indicator is the end, or rather if the string has reached the end, return?
//these are the different strings with operations already applied
for(set<string>::iterator it = ) {
	//for each string, starting at the location following, (need to specify).
	temp = *it;	// don't need the for loop. unless you want to do all of it here. // so the only thing you need here is the position of where to apply. the next.
		//apply +
		temp_p = temp;
		temp_p.insert(position, "+");
		position += 2;
			//(application, and the position)
		//apply -

		//apply anneal

		//add each of these to a new set. 		//you have to take the changes into a new set and apply this set to operators. reason being, the old set does not offer enough of the strings to manipulate.
	}

}
//recursion, go through 

//read

// set up a class with a string and a position? and have a set of this class? i think this the best solution. 

//Map style.

