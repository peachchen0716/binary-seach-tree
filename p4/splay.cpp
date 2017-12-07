/*
* Methods for splay insertion.
* M. J. Mossinghoff
* CSC 321 Fall 2017
*/
#include "splay.h"
#include <iostream>

// Public
// Precondition: k is not in the tree.
SplayBST::SplayBST() : BST(){}

void SplayBST::insert(int k) {
  insert(k, root);
}

bool SplayBST::search(int k){
  TNode* r = search(k, root);
  return r->key == k;
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


BST::TNode* SplayBST::search(int k, TNode*& p) {
  if (!p || k == p->key) {
    return p;
  }
  if (k < p->key) {
    TNode*& q = p->left;
    if (!q) {
      return p;
    }
    if (k < q->key) {
      q->left = search(k, q->left);
      rotateRight(p);  // zig-zig
    } else if (k > q->key){
      q->right = search(k, q->right);
      if (q->right) rotateLeft(q);   // zig-zag
    }
    if (p->left)  rotateRight(p);
  } else {
    TNode*& q = p->right;
    if (!q) {
      return p;
    }
    if (k > q->key) {
      q->right = search(k, q->right);
      rotateLeft(p);   // zag-zag
    } else if (k < q->key){
      q->left = search(k, q->left);
      if (q->left) rotateRight(q);  // zag-zig
    }
    if (p->right) rotateLeft(p);
  }
  return p;
}
