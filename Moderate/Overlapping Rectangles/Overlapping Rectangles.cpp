/* Overlapping Rectangles.cpp
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool test_overlap(vector<int> &p);

int main(int argc, char *argv[]) {
	ifstream ifilestream;
	string saxl, sayl, saxr, sayr, sbxl, sbyl, sbxr, sbyr;
	int axl, ayl, axr, ayr, bxl, byl, bxr, byr;
	vector<int> points;
	bool first = true;

	ifilestream.open(argv[1]);
	while(ifilestream.peek() != EOF) {
		points.clear();
		//get a coordinates
		getline(ifilestream, saxl, ',');
		istringstream isstream(saxl);
		isstream >> axl;
		points.push_back(axl);
		isstream.clear();
		getline(ifilestream, sayl, ',');
		isstream.str(sayl);
		isstream >> ayl;
		points.push_back(ayl);
		isstream.clear();
		getline(ifilestream, saxr, ',');
		isstream.str(saxr);
		isstream >> axr;
		points.push_back(axr);
		isstream.clear();
		getline(ifilestream, sayr, ',');
		isstream.str(sayr);
		isstream >> ayr;
		points.push_back(ayr);
		isstream.clear();
		//get b coordinates
		getline(ifilestream, sbxl, ',');
		isstream.str(sbxl);
		isstream >> bxl;
		points.push_back(bxl);
		isstream.clear();
		getline(ifilestream, sbyl, ',');
		isstream.str(sbyl);
		isstream >> byl;
		points.push_back(byl);
		isstream.clear();
		getline(ifilestream, sbxr, ',');
		isstream.str(sbxr);
		isstream >> bxr;
		points.push_back(bxr);
		isstream.clear();
		getline(ifilestream, sbyr);
		isstream.str(sbyr);
		isstream >> byr;
		points.push_back(byr);
		isstream.clear();
/*
		for(int i = 0; i < points.size(); i++) {
			cout << points.at(i) << " ";
		}
*/
		if(first) {
			first = false;
			if (test_overlap(points)) {
				cout << "True";
			}
			else cout << "False";
		}
		else {
			if(test_overlap(points)) {
				cout << endl << "True";
			}
			else cout << endl << "False";
		}
	}

	ifilestream.close();

	return 0;
}

bool test_overlap(vector<int> &p) {
	//test if top left corner of A is in B
	if(p.at(0) >= p.at(4) && p.at(0) <= p.at(6) && p.at(1) <= p.at(5) && p.at(1) >= p.at(7)) {
		return true;
	}
	//test if top right corner of A is in B
	else if(p.at(2) >= p.at(4) && p.at(2) <= p.at(6) && p.at(1) <= p.at(5) && p.at(1) >= p.at(7)) {
		return true;
	}
	//test if bottom left corner of A is in B
	else if(p.at(0) >= p.at(4) && p.at(0) <= p.at(6) && p.at(3) <= p.at(5) && p.at(3) >= p.at(7)) {
		return true;
	}
	//test if botton right corner of A is in B
	else if(p.at(2) >= p.at(4) && p.at(2) <= p.at(6) && p.at(3) <= p.at(5) && p.at(3) >= p.at(7)) {
		return true;
	}
	else return false;
	//return false otherwise.
}