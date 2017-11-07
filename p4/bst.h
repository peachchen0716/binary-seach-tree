//
//  bst.h
//  P4
//
//  Created by Zhou, Harry on 10/30/17.
//  Copyright © 2017 Zhou, Harry. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <cstddef>
#include <string>
using namespace std;

class BST {
public:
    BST() : root(NULL), searchHit(0.0), searchMiss(0.0), l(0),
     numNode(0) {}
    virtual ~BST();

    // Insert the item in the tree if it is not already there; increment
    // the item's counter if it is already there.
    virtual void insert(int);
    virtual bool search(const int);

    // Remove the item from the tree if it is there and return the value of
    // the counter stored with the item.  If the item is not there, return 0.
    virtual void remove(int);

    void report() const;

    // Print the items and counts stored in the tree in order.
    friend ostream& operator << (ostream&, const BST&);

protected:
    class TNode {
    public:
        int num;
        int count;
        TNode* left;
        TNode* right;
        TNode(int w) : num(w), count(1), left(0), right(0) {}
    };

    TNode* root;

    double searchHit;
    double searchMiss;
    int l;
    int numNode;

   void rootInsert(int, TNode*&);
   void rotateLeft(TNode*&);
   void rotateRight(TNode*&);

   TNode* removeSmallest(TNode*&);

private:
// Ask him if we need to put TNode into protected.

    // void rootInsert(int, TNode*&);
    // void rotateLeft(TNode*&);
    // void rotateRight(TNode*&);

    // Private member functions implementing recursive traversals or searches.
    void insert(TNode*&, int);
    void remove(int, TNode*&);
    bool search(TNode*&, const int);
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
