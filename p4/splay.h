//
// splay.h
//
// Arthur C, Harry Z

#ifndef splay
#define splay

#include "bst.h"

class SplayBST : public BST
{
public:
	SplayBST();
	virtual void insert(int);
	virtual bool search(int);

private:
	void insert(int, TNode*&);
	TNode* search(int, TNode*&);
};


#endif
