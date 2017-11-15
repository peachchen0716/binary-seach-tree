/*
 * Methods for splay insertion.
 * M. J. Mossinghoff
 * CSC 321 Fall 2017
 */
#include "splay.h"

// Public
// Precondition: k is not in the tree.
SplayBST::SplayBST() : BST(){}

void SplayBST::insert(int k) {
    insert(k, root);
}

bool SplayBST::search(int k){
	return search(k, root);
}

// Private
void SplayBST::insert(int k, TNode*& p) {
    if (!p) {
        p = new TNode(k);
        return;
    }
    if (k < p->key) {
        TNode*& q = p->left;
        if (!q) {
            p = new TNode(k, 0, p);
            return;
        }
        if (k < q->key) {
            insert(k, q->left);
            rotateRight(p);  // zig-zig
        } else {
            insert(k, q->right);
            rotateLeft(q);   // zig-zag
        }
        rotateRight(p);
    } else {
        TNode*& q = p->right;
        if (!q) {
            p = new TNode(k, p, 0);
            return;
        }
        if (k > q->key) {
            insert(k, q->right);
            rotateLeft(p);   // zag-zag
        } else {
            insert(k, q->left);
            rotateRight(q);  // zag-zig
        }
        rotateLeft(p);
    }
}


bool SplayBST::search(int k, TNode*& p) {
	if (!p) {
		return false;
	}
  if (k == p->key)  return true;
	if (k < p->key) {
		TNode*& q = p->left;
		if (!q) {
			return false;
		}
    if (k < q->key) {
			if (search(k, q->left)){
        rotateRight(p);  // zig-zig
      } else  return false;
		} else if (k > q->key){
			if (search(k, q->right)){
        rotateLeft(q);   // zig-zag
      } else  return false;
		} else{
			return true;
		}
		rotateRight(p);
	} else {
		TNode*& q = p->right;
		if (!q) {
			return false;
		}
		if (k > q->key) {
			if (search(k, q->right))
			   rotateLeft(p);   // zag-zag
      else  return false;
		} else if (k < q->key){
			if (search(k, q->left))
			   rotateRight(q);  // zag-zig
      else  return false;
		} else{
			return true;
		}
		rotateLeft(p);
	}
  return true;
}
