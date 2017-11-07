//
//  bst.cpp
//  P4
//
//  Created by Zhou, Harry on 10/30/17.
//  Copyright © 2017 Zhou, Harry. All rights reserved.
//

#include "bst.h"

#include <iostream>
#include <cstddef>
#include <cstdlib>
using namespace std;

BST::~BST() {
    // Call a private function to delete the entire tree.
    if (root) kill(root);
}

void BST::insert(int w) {
    // Call a private function to do the insertion, starting at the root.
    insert(root, w);
}

void BST::insert(TNode*& p, int w) {
    if (p == NULL) {
        // The node is not in the tree: make a new node.
        l++;
        numNode++;
        p = new TNode(w);
    } else if (w == p->num) {
        // The node is in the tree already: increment its counter.
    } else if (w < p->num) {
        // Given w is too small, so search the left subtree.
        l++;
        insert(p->left, w);
    } else {  // w > p->word
        // Given w is too big, so search the right subtree.
        l++;
        insert(p->right, w);
    }
}

void BST::remove(int w) {
    remove(w, root);
}

void BST::remove(int w, TNode*& p) {
    // If there is nothing in the subtree, the element is not in the tree.
    if (p == NULL) return;
    if (w < p->num){
      l--;
      remove(w, p->left);
    }
    if (w > p->num){
      l--;
      remove(w, p->right);
    }
    // At this point, we know that w equals p->word.
    TNode* q = p;
    if (p->right == NULL) {
        // Either p is a leaf, or p has a left child but no right child.
        p = p->left;
    } else if (p->left == NULL) {
        // p has a right child but no right child.
        p = p->right;
    } else {
        // p has both a left and a right child.  Use improved "copy"
        // strategy.
        // Delete the node that p points to and replace it in the tree
        // with the successor node.
        p = removeSmallest(p->right);
        p->left = q->left;
        p->right = q->right;
    }
    l--;
    delete q;
}

// Return the address of the node with the smallest key in the tree pointed
// to by p, and remove this node from the tree.
BST::TNode* BST::removeSmallest(TNode*& p) {
    // Go left while there is a smaller element in the tree.
    if (p->left) return removeSmallest(p->left);
    // No left child, so there is no smaller element in the tree.
    TNode* ans = p;
    p = p->right;    // Required since p is a reference.
    return ans;
}

bool BST::search(const int k){
    search(root, k);
}

bool BST::search(TNode*& p, const int k){
    if (p == NULL) {
        // The node is not in the tree: make a new node.
        return false;
    } else if (k == p->num) {
        // The node is in the tree
    	return true;
    } else if (k < p->num) {
    	// Given k is too small, so search the left subtree.
    	if(search(p->left, k)){
    		return true;
    	}else{
    		return false;
    	}
    } else {  // k > p->word
    	// Given k is too big, so search the right subtree.
    	if(search(p->right, k)){
    		return true;
    	}else{
    		return false;
    	}
    }
}


void BST::rootInsert(int k, TNode*& p){
	if (!p){
		p = new TNode(k);
	}else if (k < p->num){
		rootInsert(k, p->right);
		rotateRight(p);
	}else{
		rootInsert(k, p->left);
		rotateLeft(p);
	}
}

void BST::rotateLeft(TNode*& p){
	TNode* q = p->right;
	p->right = q->left;
	q->left = p;
	p = q;
}

void BST::rotateRight(TNode*& p){
	TNode* q = p->left;
	p->left = q->right;
	q->right = p;
	p = q;
}


// Postorder traversal
void BST::kill(TNode* p) {
    if (p->left) kill(p->left);          // Delete nodes in the left subtree.
    if (p->right) kill(p->right);        // Delete nodes in the right subtree.
    delete p;                            // Delete current node.
}

// Inorder traversal
void BST::print(ostream& out, TNode* p) const {
    if (p->left) print(out, p->left);          // Print smaller words// Print current word
    if (p->right) print(out, p->right);        // Print larger words
}

void BST::report() const{
    cout << "Total hit: " << l << endl;
    cout << "Number of nodes: " << numNode << endl;
    cout << "Search hit: " << (double)l/numNode << endl;
    cout << "Search miss: " << (double)l/numNode+1 << endl;
}

// Friend output operator.
ostream& operator<<(ostream& out, const BST& wt) {
    // Call a private function to do the printing, starting at the root.
    if (wt.root) wt.print(out, wt.root);
    return out;
}
