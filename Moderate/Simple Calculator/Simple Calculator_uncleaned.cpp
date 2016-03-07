/* Simple Calculator.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

string evaluate_parentheses(string expr);
string operate(string expr);

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	
	string expression, s_answer;
	float answer;
	bool first = true;
	
	while(ifs.peek() != EOF) {
		getline(ifs, expression);
		//it has to be a recursive function to do order of evaluation.
		expression = evaluate_parentheses(expression);
	//	cout << expression << endl;
		s_answer = operate(expression);
		
	//	cout << s_answer << endl;

		istringstream iss(s_answer);
		iss >> answer;
		
		if(first) {
			first = false;
			cout << answer;
		}
		else cout << endl << answer;
		
	}

	ifs.close();
	
	return 0;
}

string evaluate_parentheses(string expr) {
	int left_parenthesis_position, right_parenthesis_position;
	string inside_expression, answer, entire_expression;
	//search the string for '('. if found, seek the last ')'	// can't do this because if there are two parentheses sets, then this messes up.
	//must find right-most '(' and then pair it with the first ')' found after.
	// once this is evaluated and resubstituted back into the original equation do the same thing.
	// once there are no more parenthesis..evaluate the expression.
	
	//recursively call this function again with the inside of this section.
	left_parenthesis_position = expr.find_last_of('(');
	right_parenthesis_position = expr.find_first_of(')', left_parenthesis_position);

	//cout << left_parenthesis_position << " " << right_parenthesis_position << endl;

	if(left_parenthesis_position != string::npos && right_parenthesis_position != string::npos) {
		//cout << "testing" << endl;
		inside_expression = evaluate_parentheses(expr.substr(left_parenthesis_position + 1, right_parenthesis_position - left_parenthesis_position - 1));	
		
		expr.replace(expr.begin() + left_parenthesis_position, expr.begin() + right_parenthesis_position + 1, inside_expression);	
	//	cout << expr << endl;
	}
	else {
		//cout << expr << endl;
		answer = operate(expr);
		return answer;
	}

	return expr;
}

string operate(string expr) {
	//collect numbers into a stack or queue? neither, the operation could be in the middle.
	//so you'll need basically an array...vector for both numbers and operators.



	int exponent_counter;
	float answer, number;
	string s_number, s_answer;
	char op;
	vector<float> numbers;
	vector<char> ops;
	string extracted_expression;

	extracted_expression = expr;

	bool level1_considered, level2_considered, level3_considered;

	s_number.clear();
	s_answer.clear();
	numbers.clear();
	ops.clear();

//	cout << extracted_expression << endl;

	//place numbers and operators into vector arrays.
	for(int i = 0; i < extracted_expression.size(); i++) {
	//	cout << "testing" << endl;
	//	cout << extracted_expression.size() << endl;

		//if first item is a minus sign or a digit, add to number.
		if((i == 0 && extracted_expression.at(i) == '-') || isdigit(extracted_expression.at(i)) || extracted_expression.at(i) == '.') {
			s_number += extracted_expression.at(i);
		//	cout << extracted_expression.at(i) << endl;

		}
		//if space, ignore
		else if(isspace(extracted_expression.at(i))) {
			if(!s_number.empty()) {
				istringstream iss(s_number);
				iss >> number;
				numbers.push_back(number);
				s_number.clear();
			}
		}
		//if an operator, add to operator section
		else if(extracted_expression.at(i) != '-' || (extracted_expression.at(i) == '-' && isspace(extracted_expression.at(i + 1)))) {
			ops.push_back(extracted_expression.at(i));

	//		cout << extracted_expression.at(i) << endl;
			if(!s_number.empty()) {
				istringstream iss(s_number);
				iss >> number;
			//	cout << "testing" << endl;
		//		cout << number << endl;
				numbers.push_back(number);
				s_number.clear();
			}
		}
		//it's a unary minus
		else {
			s_number += extracted_expression.at(i);
		}
	}
	if(!s_number.empty()) {
		istringstream iss(s_number);
			iss >> number;
			numbers.push_back(number);
			s_number.clear();

		//	cout << number << endl;

	}

	//cout << "testing" << endl;

	level1_considered = false;
	level2_considered = false;
	level3_considered = false;

	//apply operations:
	while(!ops.empty()) {
		//cout << endl << ops.size() << " " << numbers.size() << endl;

	//	for(int i = 0; i < ops.size(); i++) {
	//		cout << numbers.at(i) << " " << ops.at(i) << " ";
	//	}
	//		cout << numbers.at(numbers.size() - 1) << endl;

		for(int i = 0; i < ops.size(); i++) {
			if(level1_considered && i != 0)
					i--;

		//	cout << ops.at(i) << endl;

			if(ops.at(i) == '^') {
				level1_considered = true;
				exponent_counter = numbers.at(i + 1);
				if(exponent_counter > 0) {
					answer = 1;
					while(exponent_counter > 0) {
						answer *= numbers.at(i);
						exponent_counter--;
					//	cout << answer << " " << numbers.at(i) << " " << exponent_counter << endl;
					}
					numbers.at(i) = answer;
					numbers.erase(numbers.begin() + i + 1);
				}
				else {
					exponent_counter *= -1;
				//	cout << numbers.at(i) << " " << exponent_counter << " " << numbers.at(i + 1) << endl;
					while(exponent_counter > 0) {
						answer = 1;
						answer *= numbers.at(i);
						exponent_counter--;
					}
					numbers.at(i) = 1 / answer;
					//cout << numbers.at(i) << " " << answer << endl;
					numbers.erase(numbers.begin() + i + 1);
				}
				ops.erase(ops.begin() + i);
			//	cout << numbers.at(i) << endl;
			}
		}
		// * and /
		for(int i = 0; i < ops.size(); i++) {
			if(level2_considered && i != 0)
					i--;

			if(ops.at(i) == '*') {
				level2_considered = true;
		//		answer = numbers.at(i - 1);
				numbers.at(i) *= numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			//	cout << numbers.at(i) << endl;

			}	
			else if(ops.at(i) == '/') {
			//	cout << "testing" << endl;
				level2_considered = true;
				numbers.at(i) /= numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}

		}
		for(int i = 0; i < ops.size(); i++) {
			if(level3_considered && i != 0)
					i--;

		//	cout << "testing" << endl;

			if(ops.at(i) == '+') {
				level3_considered = true;
				numbers.at(i) += numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}
			else if(ops.at(i) == '-') {
				level3_considered = true;
				numbers.at(i) -= numbers.at(i + 1);
				numbers.erase(numbers.begin() + i + 1);
				ops.erase(ops.begin() + i);
			}
		}
	}

//	cout << "testing" << endl;

	answer = floor(numbers.at(0) * 100000 + 0.5) / 100000;

	ostringstream oss;
	oss << answer;
	s_answer = oss.str();

//	cout << s_answer << endl;

	return s_answer;
}