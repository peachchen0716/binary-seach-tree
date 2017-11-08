/*
 * Methods for splay insertion.
 * M. J. Mossinghoff
 * CSC 321 Fall 2017
 */

// Public
// Precondition: k is not in the tree.
void SplayBST::insert(int k) {
    insert(k, root);
    num++;
}

void SplayBST::remove(int k) {
	remove(k, root);
}

bool SplayBST::search(int k){
	search(k, root);
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

void SplayBST::remove(int k, TNode*& p) {
	if (!p) {
		return;
	}
	if (k < p->key) {
		TNode*& q = p->left;
		if (!q) {
			return;
		} if (k < q->key) {
			remove(k, q->left);
			rotateRight(p);  // zig-zig
		} else if (k > q->key){
			remove(k, q->right);
			rotateLeft(q);   // zig-zag
			normalRemove(q);
		}
		rotateRight(p);
	} else if (k > p->key){
		TNode*& q = p->right;
		if (!q) {
			return;
		}
		if (k > q->key) {
			remove(k, q->right);
			rotateLeft(p);   // zag-zag
		} else if (k < q->key){
			remove(k, q->left);
			rotateRight(q);  // zag-zig
		} else{
			normalRemove(q);
		}
		rotateLeft(p);
	}else{
		 normalRemove(p);
	}
}

void SplayBST::normalRemove(TNode*& p){
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
	delete q;
}

bool SplayBST::search(int k, TNode*& p) {
	if (!p) {
		return false;
	}
	if (k < p->key) {
		TNode*& q = p->left;
		if (!q) {
			return false;
		} if (k < q->key) {
			search(k, q->left);
			rotateRight(p);  // zig-zig
		} else if (k > q->key){
			search(k, q->right);
			rotateLeft(q);   // zig-zag
		} else{
			return true;
		}
		rotateRight(p);
	} else if (k > p->key){
		TNode*& q = p->right;
		if (!q) {
			return;
		}
		if (k > q->key) {
			remove(k, q->right);
			rotateLeft(p);   // zag-zag
		} else if (k < q->key){
			remove(k, q->left);
			rotateRight(q);  // zag-zig
		} else{
			return true;
		}
		rotateLeft(p);
	} else{
		return true;
	}
}