//
//
// Arthur C, Harry Zhou
//

#include "bst.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <string>
#include <queue>
#include <iomanip>

int main(){
	srand48(time(0));

	int num, num_search, num_remove;
	cout << "Number of keys to be inserted: ";
	cin >> num;
	string name;
	cout << "Name of the file: ";
	cin >> name;
	cout << "Number of removes to be performed: ";
	cin >> num_remove;
	cout << "Number of searches to be performed: ";
	cin >> num_search;

	BST tree;
	ifstream inc;
	inc.open(name.c_str());
	if (inc.fail()) {
		cerr << "Error: Cannot open " << name << endl;
		exit(1);
	}
	int temp;
	for (int i = 0; i < num; i++){
		inc >> temp;
		tree.insert(temp);
	}

	//remove a*N times even int from 2 to 2N for ordinary and randomized trees
	tree.report();
	return 0;
}
