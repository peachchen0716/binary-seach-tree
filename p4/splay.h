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
	virtual void remove(int);
	virtual bool search(int);

private:
	void insert(TNode*&, int);
  void remove(TNode*&, int);
  void normalRemove(TNode*&);
  bool search(TNode*&, int);

};


#endif
