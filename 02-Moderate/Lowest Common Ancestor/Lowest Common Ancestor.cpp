/* Lowest Common Ancestor.cpp
 *
 * Binary trees!
 *
 * Created a binary node class with forward and backward links.
 *		- Custom constructor that takes arguments.
 * 		- Located nodes recursively using backward links (or links that originate from the ancestor) 
 *		- Found the common ancestor using foward links (or links that converge to the ancestor).
 *		- Custom destructor that takes arguments.
 *
 * OOP - need to focus on how you want the objects to interact.
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class bNode {
public:
//	bNode();
//	~bNode();
	friend bNode * create_bNode(int, bNode*);
	friend void remove_bNodes(bNode*);
	friend int locate_common_ancestor(int[], bNode*);
	bNode * common(bNode*);			// don't think there was a reason to make it a member function.
private:
	int n;
	bNode * link, * blink1, * blink2;
	friend bNode * locate_bNode(int, bNode *);
};

bNode * create_bNode(int number, bNode *link) {
	bNode * p = new bNode;
	p->n = number;
	p->link = link;
	p->blink1 = NULL;
	p->blink2 = NULL;
	//if not the beginning node
	if(p->link != NULL) {
		if(p->link->blink1 == NULL)
			p->link->blink1 = p;
		else p->link->blink2 = p;
	}
	return p;
}

void remove_bNodes(bNode * root) {
	bNode * ptr1, * ptr2;

	ptr1 = root->blink1;
	ptr2 = root->blink2;
	delete root;

	if(ptr1 == NULL && ptr2 == NULL)
		return;

	remove_bNodes(ptr1);
	remove_bNodes(ptr2);
}

/*
bNode::~bNode(bNode * node) {

	//delete n;	// have to set it up to delete down the chain (everything downstream)
}
*/

int locate_common_ancestor(int nodes[], bNode * ori) {
	bNode * n1, * n2, * ancestor;

	//locate nodes
	n1 = locate_bNode(nodes[0], ori);
	n2 = locate_bNode(nodes[1], ori);

	//copy content over
	//bNode n1 = *p1;
	//bNode n2 = *p2;

	//look for common ancestor
	ancestor = n1->common(n2);

	if(ancestor == NULL) {
		cout << "No ancestor found.";
		return 0;
	}

	return ancestor->n;
}

bNode * locate_bNode(int n, bNode * ori) {
	// with forward links, you have to start from the 4 endpoints. if this was a huge function this would totally be a big inefficient practice
	// you would have to get backward pointers.
	//start from base:
	bNode * pt1, * pt2;

	//if the numbers match, node found.
	if(ori->n == n) {
		return ori;
	}
	//if both are NULL, (true at any endpoint) set ori to NULL and return it.
	else if(ori->blink1 == NULL && ori->blink2 == NULL) {
		ori = NULL;
		return ori;
	}
	//recusion by going one node deeper.
	else {
		pt1 = locate_bNode(n, ori->blink1);
		pt2 = locate_bNode(n, ori->blink2);
	}

	if(pt1 == NULL) return pt2;
	else return pt1;
	//if current base n value = n return this

	// if blink returns null stop.
	// if not found keep going
}

bNode * bNode::common(bNode * node) {
	//general comparison algorithm.
	for(bNode * pt = this; pt != NULL; pt = pt->link) {
		for(bNode * pt2 = node; pt2 != NULL; pt2 = pt2->link) {
			if(pt == pt2)
				return pt;
		}
		//if comparison object is a root
		if(node->link == NULL) {
			if(pt == node)
				return pt;
		}
	}
	//if current object is a root
	if(this->link == NULL) {
		for(bNode * pt3 = node; pt3 != NULL; pt3 = pt3->link) {
			if(this == pt3)
				return this;
		}
	}
	//if they're the same thing...
	if(this == node) {
		return this;
	}
	//if no common ancestor, return NULL.
	return NULL;
}


int main(int argc, char *argv[]) {
	ifstream ifilestream;
	bNode * ptr, * original;
	string nodes, snum;
	bool first = true;
	int node[2], count, number;

	//hardcoding the binary tree into the program.
	original = create_bNode(30, NULL);
	create_bNode(52, original);				//endpoint 1
	ptr = create_bNode(8, original);
	create_bNode(3, ptr);					//endpoint 2
	ptr = create_bNode(20, ptr);
	create_bNode(10, ptr);					//endpoint 3
	create_bNode(29, ptr);					//endpoint 4

	ifilestream.open(argv[1]);

	//get data
	while(ifilestream.peek() != EOF) {
		nodes.clear();
		count = 0;
		//get nodes one line at a time
		getline(ifilestream, nodes);
		for(int i = 0; i < nodes.size(); i++) {
			if(!isspace(nodes.at(i))) {
				snum += nodes.at(i);
			}
			else if(!snum.empty()) {
				istringstream isstream(snum);
				isstream >> node[count];
				snum.clear();
				count++;
			}
		}
		if(!snum.empty()) {
			istringstream isstream(snum);
			isstream >> node[count];
			snum.clear();
		}
		//locate ancestor
		number = locate_common_ancestor(node, original);	//pass the pointer by passing the address.

		if(first) {
			cout << number;
			first = false;
		}
		else cout << endl << number;
	}

	remove_bNodes(original);

	ifilestream.close();

	return 0;
}