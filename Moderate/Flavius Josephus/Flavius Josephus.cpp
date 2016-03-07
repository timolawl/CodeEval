/* Flavius Josephus.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string sn, sm;
	int n, m, kill_off_position, left_over, m_counter;
	vector<int> people, kill_off_order;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		kill_off_order.clear();
		people.clear();
		//get variables
		getline(ifilestream, sn, ',');
		getline(ifilestream, sm);
		//convert variables into number form.
		istringstream isstream(sn);
		isstream >> n;
		isstream.clear();
		isstream.str(sm);
		isstream >> m;

		//populate vector
		for(int i = 0; i < n; i++) {
			people.push_back(i);
		}
		//Josephus
		kill_off_position = m - 1;
	
		while(!people.empty()) {
			kill_off_order.push_back(people.at(kill_off_position));
			people.erase(people.begin() + kill_off_position);
			if(people.empty()) break;
			if(m <= people.size()) {
				if(kill_off_position + m > people.size()) {
					left_over = people.size() - kill_off_position;
					kill_off_position = m - left_over - 1;
				}
				else kill_off_position += (m - 1); // to account for the erases.
			}
			else {
				m_counter = m; // takes into account the position
				kill_off_position -= 1; // takes into account the erases.
				while(m_counter > 0) {
					kill_off_position++;
					if(kill_off_position >= people.size()) { // takes into account erases.
						kill_off_position = 0;
					}
					m_counter--;
				}
			}
			
		}

		for(int j = 0; j < kill_off_order.size(); j++) {
			if(j == 0) {
				if(first) {
					first = false;
					cout << kill_off_order.at(j);
				}
				else cout << endl << kill_off_order.at(j);
			}
			else cout << " " << kill_off_order.at(j);
		}
	}

	ifilestream.close();

	return 0;
}