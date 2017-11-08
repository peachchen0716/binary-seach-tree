/*
 * Methods for randomized removal.
 * M. J. Mossinghoff, A. Chen, H. Zhou
 * CSC 321 Fall 2017
 */
#include "randbst.h"

RandomizedBST::RandomizedBST() : BST(){}

// Public
void RandomizedBST::insert(int k){
    randInsert(root, k);
}

// Public
bool RandomizedBST::remove(int k) {
    return remove(k, root);
}

// Private
void RandomizedBST::randInsert(int k, TNode*& p){
    if (!p){
        p = new TNode(k);
    }else if(drand48() * (p->count + 1) < 1){
        rootInsert(p, k);
    }else if(k < p->word){
        randInsert(p->left, word);
        p->count++;
    }else{
        randInsert(p->right, word);
        p->count++;
    }
}

// Private
bool RandomizedBST::remove(int k, TNode*& p) {
    bool b = true;
    if (!p) {
        b = false;
    } else if (k < p->key) {
        b = remove(k, p->left);
        if (b) p->n--;
    } else if (k > p->key) {
        b = remove(k, p->right);
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
