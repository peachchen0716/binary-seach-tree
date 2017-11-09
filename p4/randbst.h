//
// randbst.h
//
// Arthur C, Harry Z

#ifndef randbst
#define randbst

#include "bst.h"

class RandomizedBST : public BST
{
public:
	RandomizedBST();
	virtual void insert(int);
	virtual void remove(int);
private:
	void randInsert(int, TNode*&);
  bool randRemove(int&, TNode*&);
  TNode* randZip(TNode*, TNode*);
  void fixCount(TNode*);
};

#endif
