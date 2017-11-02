//
// randbst.cpp
//
// Arthur C, Harry Z

#include <stdlib.h>
#include "randbst.h"

RandBST::RandBST() : BST(){}

void RandBST::insert(const string& s){
	randInsert(root, s);
}

void RandBST::remove(const string& s){
	randRemove(root, s);
}

void RandBST::randInsert(TNode*& p, const string& s){
	if (!p){
		p = new TNode(s);
	}else if(drand48() * (p->count + 1) < 1){
		rootInsert(p, s);
	}else if(s < p->word){
		randInsert(p->left, word);
		p->count++;
	}else{
		randInsert(p->right, word);
		p->count++;
	}
}

void RandBST::randRemove(TNode*& p, const string& s){
	if (s < p->word){
		randRemove(s, p->left);
		p->count--;
	}else if(s > p->word){
		randRemove(s, p->right);
		p->count--;
	}else{
		TNode* q = p;
		p = randZip(p->left, p->right);
		delete q;
	}
}

TNode randZip(TNode* a, TNode* b){
	if (!a) return b;
	if (!b) return a;
	if (drand48() * (a->count + b->count) < a->count){
		a->right = randZip(a->right, b);
		fixCount(a);
		return a;
	}
	b->left = randZip(a, b->left);
	fixCount(b);
	return b;
}

bool RandBST::fixCount(Tnode*& p){
	p->count = 1;
	if (p->left) p->count += p->left->count;
	if (p->right) p->count += p->right->count;
}