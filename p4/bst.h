//
//  bst.h
//  P4
//
//  Created by Zhou, Harry on 10/30/17.
//  Copyright © 2017 Zhou, Harry. All rights reserved.
//

#ifndef bst_hpp
#define bst_hpp

#include <stdio.h>
#include <cstddef>
#include <string>

class BST {
public:
    BST() : root(NULL), searchHit(0), searchMiss(0), totalHit(0), totalMiss(0) {}
    ~BST();
    
    // Insert the item in the tree if it is not already there; increment
    // the item's counter if it is already there.
    virtual void insert(const string&);
    
    virtual void search(const string&);
    
    // Remove the item from the tree if it is there and return the value of
    // the counter stored with the item.  If the item is not there, return 0.
    virtual void remove(const string&);
    
    // Print the items and counts stored in the tree in order.
    friend ostream& operator << (ostream&, const BST&);
    
protected:
    TNode* root;

    int searchHit;
    int searchMiss;
    int totalHit;
    int totalMiss;

    void rootInsert(const string&, TNode*&);
    void rotateLeft(TNode*&);
    void rotateRight(TNode*&);

private:
    
    class TNode {
    public:
        string word;
        int count;
        TNode* left;
        TNode* right;
        TNode(const string& w) : word(w), count(1), left(0), right(0) {}
    };
    
    // Private member functions implementing recursive traversals or searches.
    virtual void insert(TNode*&, const string&);
    virtual void remove(const string&, TNode*&);
    TNode* removeSmallest(TNode*&);
    int count(TNode*) const;
    void kill(TNode*);
    void print(ostream&, TNode*) const;

    
    // Static auxilliary methods.
    static void sort(TNode**, int, int);
    
    // Disable copy constructor and assignment operator.
    BST(const BST&);
    BST& operator=(const BST&);
};


#endif /* bst_h */
