/* Reverse Groups.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> swapfcn(vector<int> l, int k);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string slist, sk, snum;
	int k, times, num;
	vector<int> list;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		getline(ifilestream, slist, ';');
		getline(ifilestream, sk);
		//turn into numeric form:
		list.clear();
		snum.clear();
		for(int i = 0; i < slist.size(); i++) {
			if(isdigit(slist.at(i))) {
				snum += slist.at(i);
			}
			else if(!snum.empty()) {
				istringstream isstream(snum);
				isstream >> num;
				list.push_back(num);
				snum.clear();
			}
		}
		if(!snum.empty()) {
			istringstream isstream(snum);
			isstream >> num;
			list.push_back(num);
			snum.clear();
		}
		istringstream isstream2(sk);
		isstream2 >> k;

		if(!(k >= list.size())) {	
			list = swapfcn(list, k);
		}
		for(int j = 0; j < list.size(); j++) {
			if(j == 0) {
				if(first) {
					first = false;
					cout << list.at(j);
				}
				else cout << endl << list.at(j);
			}
			else cout << "," << list.at(j);
		}

	}
	ifilestream.close();

	return 0;
}

vector<int> swapfcn(vector<int> l, int k) {
	int temp, n = 0;
	int times = l.size()/k;

	while(n < times) {
		for(int position = n*k; position < k/2 + n*k; position++) {
			temp = l.at(position);
			l.at(position) = l.at(k - 1 + position);
			l.at(k - 1 + position) = temp;
		}
		n++;
	}
	return l;
}