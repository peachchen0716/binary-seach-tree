//
// randbst.h
//
// Arthur C, Harry Z

#ifndef randbst
#define randbst

#include "bst.h"

class RandBST : public BST 
{
public:
	RandBST();
	virtual void insert(const string&);
	virtual void remove(const string&);
private:
	virtual void insert(TNode*&, const string&);
    virtual void remove(const string&, TNode*&);
    bool checkCount(Tnode*&);
};

#endif