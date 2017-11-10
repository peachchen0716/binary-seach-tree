//
//
// Arthur C, Harry Zhou
//

#include "bst.h"
#include "randbst.h"
#include "splay.h"

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

	int N, num_search, num_remove;

	cout << "Number of keys to be inserted: ";
	cin >> N;
	string name;
	cout << "Name of the file: ";
	cin >> name;
	cout << "Number of removes to be performed: ";
	cin >> num_remove;
	cout << "Number of searches to be performed: ";
	cin >> num_search;

	BST ordinary;
	RandomizedBST random;
	SplayBST splaybst;

	ifstream inc;
	inc.open(name.c_str());
	if (inc.fail()) {
		cerr << "Error: Cannot open " << name << endl;
		exit(1);
	}

	int recent[N/10];

	int temp;
	for (int i = 0; i < N; i++){
		inc >> temp;
		if (i >= 9*N/10){
			recent[i-9*N/10] = temp;
		}
		ordinary.insert(temp);
		random.insert(temp);
		splaybst.insert(temp);
		//cout<<temp<<endl;
	}

	//search for the most recent nodes
	//for (int i=0; i < N/10; i++){
		//ordinary.search(recent[i]);
	//}

	ordinary.report();
	random.report();
	splaybst.report();
	//remove a*N times even int from 2 to 2N for ordinary and randomized trees

	cout << "\nAfter removing a*N times even int" << endl;
	for (int i=0; i < num_remove*N; i++){
		ordinary.remove(drand48()*2*(N-1)+2);
		random.remove(drand48()*2*(N-1)+2);
	}
	ordinary.report();
	random.report();

	//search
	for (int i=0; i < num_search; i++){
		//ordinary.search(drand48()*2*(N-1)+2);
	}
	//ordinary.report();
	return 0;
}
