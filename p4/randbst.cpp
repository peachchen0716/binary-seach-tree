/*
 * Methods for randomized removal.
 * M. J. Mossinghoff, A. Chen, H. Zhou
 * CSC 321 Fall 2017
 */
#include "randbst.h"
#include <stdlib.h>
#include <iostream>

RandomizedBST::RandomizedBST() : BST(){}

// Public
void RandomizedBST::insert(int k){
    randInsert(k, root);
}

// Public
void RandomizedBST::remove(int k) {
    randRemove(k, root);
}

// Public
void RandomizedBST::checkError() {
    int error = 0;
    checkCount(root, error);
    cout << "Checking randomized BST: " << error << " errors." << endl;
}

// Protected
void RandomizedBST::rotateLeft(TNode*& p){
	TNode* q = p->right;
	p->right = q->left;

  p->n = 1;
  p->n += (p->left) ? p->left->n : 0;
  p->n += (p->right) ? p->right->n : 0;

  q->left = p;

  q->n = 1;
  q->n += (q->left) ? q->left->n : 0;
  q->n += (q->right) ? q->right->n : 0;

  p = q;
}

// Protected
void RandomizedBST::rotateRight(TNode*& p){
  int t = p->n;
  TNode* q = p->left;
	p->left = q->right;

  p->n = 1;
  p->n += (p->left) ? p->left->n : 0;
  p->n += (p->right) ? p->right->n : 0;

	q->right = p;

  q->n = 1;
  q->n += (q->left) ? q->left->n : 0;
  q->n += (q->right) ? q->right->n : 0;

	p = q;
}

// Private
void RandomizedBST::randInsert(int k, TNode*& p){
    if (!p){
        p = new TNode(k);
    }else if(drand48() * (p->n + 1) < 1){
        rootInsert(k, p);
    }else if(k < p->key){
        randInsert(k, p->left);
        p->n++;
    }else{
        randInsert(k, p->right);
        p->n++;
    }
}

// Private
bool RandomizedBST::randRemove(int& k, TNode*& p) {
    bool b = true;
    if (!p) {
        b = false;
    } else if (k < p->key) {
        b = randRemove(k, p->left);
        if (b) p->n--;
    } else if (k > p->key) {
        b = randRemove(k, p->right);
        if (b) p->n--;
    } else {
        TNode* q = p;
        p = randZip(p->left, p->right);
        delete q;
        if (p) fixCount(p);
    }
    return b;
}

// Private
BST::TNode* RandomizedBST::randZip(TNode* a, TNode* b) {
    if (!a) return b;
    if (!b) return a;
    if (drand48()*(a->n+b->n) < a->n) {
        a->right = randZip(a->right, b);
        fixCount(a);
        return a;
    }
    b->left = randZip(a, b->left);
    fixCount(b);
    return b;
}

// Private
void RandomizedBST::fixCount(TNode* p) {
    p->n = 1;
    if (p->left) p->n += p->left->n;
    if (p->right) p->n += p->right->n;
}

// Private
int RandomizedBST::checkCount(TNode* p, int& error) {
  if (!p) return 0;
  int count = checkCount(p->left, error) + checkCount(p->right, error)+1;
  if (p->n != count){
    error++;
  }
  return count;
}
