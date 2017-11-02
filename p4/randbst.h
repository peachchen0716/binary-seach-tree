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
	void randInsert(TNode*&, const string&);
    void randRemove(TNode*&, const string&);
    TNode randZip(TNode*, TNode*);
    bool fixCount(Tnode*&);

};

#endif