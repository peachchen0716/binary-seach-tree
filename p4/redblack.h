//
// splay.h
//
// Arthur C, Harry Z

#ifndef redblack
#define redblack

#include "bst.h"

class RedBlackBST : public BST
{
public:
	RedBlackBST();
	virtual void insert(int);

private:
	void insert(int, TNode*&);
	bool red(TNode*&);
};


#endif
