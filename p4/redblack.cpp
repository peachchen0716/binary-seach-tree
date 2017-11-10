/*
 * Partially complete methods for red-black insertion.
 * M. J. Mossinghoff
 * CSC 321 Fall 2017
 */

RedBlackBST::RedBlackBST() : public BST() {} 

// Public
void RedBlackBST::insert(int k) {
    redBlackInsert(k, root, false);
    root->red = false;
    if (red(root->left) && red(root->right)){
    	root->left->red = false;
    	root->right->red = false;
    }
}

// Private
// right is true if the link just taken to get to p was a right link.
void RedBlackBST::redBlackInsert(int k, TNode*& p, bool right) {
    if (!p) {
        // Make a new node and set p to this address.
    	p = new TNode(k);
        return;
    }
    // Add code here to color flip on the way down.
    if (red(p->left) && red(p->right) && !red(p)){
    	p->red = true;
    	p->left->red = false;
    	p->right->red = false;
    }
    if (k < p->key) {
        redBlackInsert(k, p->left, false);
        // Case 4: Rotation 1
        if (red(p) && red(p->left) && right) // rotate some way
        	rotateRight(p);
        // Case 3 and Case 4: Rotation 2
        if (red(p->left) && red(p->left->left)) {
            // rotate some way
        	rotateLeft(p);
            p->red = false;
            p->right->red = true;
        }
    } else {
        // Symmetric cases
    	redBlackInsert(k, p->left, true);
    	// Case 4: Rotation 1
    	if (red(p) && red(p->right) && !right) // rotate some way
    		rotateLeft(p);
    	// Case 3 and Case 4: Rotation 2
    	if (red(p->right) && red(p->right->right)) {
    		// rotate some way
    		rotateRight(p);
    		p->red = true;
    		p->left->red = false;
    }
}

bool RedBlackBST::red(TNode*& p){
	if (!p)	return false;
	return p->red;
}
