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
    BST() : root(NULL), searchHit(0.0), searchRecent(0), searchCount(0), l(0),
     numNode(0) {}
    virtual ~BST();

    // Insert the item in the tree if it is not already there; increment
    // the item's counter if it is already there.
    virtual void insert(int);
    virtual bool search(const int);

    // Remove the item from the tree if it is there and return the value of
    // the counter stored with the item.  If the item is not there, return 0.
    virtual void remove(int);

    void report(string, bool);

    // Print the items and counts stored in the tree in order.
    friend ostream& operator << (ostream&, const BST&);


protected:
    class TNode {
    public:
        int key;
        int n;
        TNode* left;
        TNode* right;
        bool red;
        TNode(int k) : key(k), n(1), left(0), right(0), red(true) {}
        TNode(int k, TNode* p, TNode* q) : key(k), n(1), left(p), right(q), red(true) {}
    };

    TNode* root;

    double searchHit;
    int searchRecent;
    int searchCount;
    int l;
    int numNode;

   void rootInsert(int, TNode*&);
   virtual void rotateLeft(TNode*&);
   virtual void rotateRight(TNode*&);
   void inorderTraverse();
   void inorder(TNode*&, int);

   TNode* removeSmallest(TNode*&);

private:

    // Private member functions implementing recursive traversals or searches.
    void insert(TNode*&, int);
    void remove(int, TNode*&);
    bool search(TNode*&, const int);
    int count(TNode*) const;
    void kill(TNode*);
    void print(ostream&, TNode*) const;

    template<typename T> void printElement(T, const int&);

    // Static auxilliary methods.
    static void sort(TNode**, int, int);

    // Disable copy constructor and assignment operator.
    BST(const BST&);
    BST& operator=(const BST&);
};


#endif /* bst_h */
