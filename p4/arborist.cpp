//
//
// Arthur C, Harry Zhou
//

#include "bst.h"
#include "randbst.h"
#include "splay.h"
#include "redblack.h"

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

	int N;
	string fileName;
	double b, a;

	cout << "Number of keys to be inserted: ";
	cin >> N;
	cout << "Name of the file: ";
	cin >> fileName;
	cout << "Number of removes to be performed: ";
	cin >> a;
	cout << "Number of searches to be performed: ";
	cin >> b;

	BST ordinary;
	RandomizedBST random;
	SplayBST splaybst;
	RedBlackBST redblackbst;

	ifstream inc;
	inc.open(fileName.c_str());
	if (inc.fail()) {
		cerr << "Error: Cannot open " << fileName << endl;
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
		//redblackbst.insert(temp);
	}

	//search for the most recent nodes
	for (int i=0; i < N/10; i++){
		ordinary.search(recent[i]);
		random.search(recent[i]);
		splaybst.BST::search(recent[i]);
		//redblackbst.BST::search(recent[i]);
	}
	cout << "  After " << N << " insertions from file " << fileName << ":" << endl;
	const int width = 8;
	cout << "    " << left << setw(width) << "Type";
	cout << left << setw(width) << "Hits";
	cout << left << setw(width) << "Misses";
	cout << left << setw(width) << "Recent";
	cout << endl;
	ordinary.report("Leaf", true);
	random.report("Rand", true);
	splaybst.report("Splay", true);
	//redblackbst.report("RedBl", true);

	//remove a*N times even int from 2 to 2N for ordinary and randomized trees
	cout << "\n  After removing a*N times even int" << endl;
	for (int i=1; i < a*N; i++){
		int temp = 2*(int)(drand48()*(i-1))+2;
		ordinary.remove(temp);
		random.remove(temp);
	}
	cout << "    " << left << setw(width) << "Type";
	cout << left << setw(width) << "Hits";
	cout << left << setw(width) << "Misses";
	cout << endl;
	ordinary.report("Leaf", false);
	random.report("Rand", false);

	//search
	int search_success = 0;
	for (int i=1; i < b*N; i++){
		int temp = drand48()*(2*i-1)+1;
		cout << temp << endl;
		if (splaybst.search(temp))	search_success++;
	}
	cout << endl;
	cout << "  After " << b*N << " searches (" << search_success <<
	" successful):" << endl;
	cout << "    " << left << setw(width) << "Type";
	cout << left << setw(width) << "Hits";
	cout << left << setw(width) << "Misses";
	cout << endl;
	splaybst.report("Splay", false);
	return 0;
}
