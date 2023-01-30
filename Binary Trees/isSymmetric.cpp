/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
        if(!root) return true;
	    return sameTree(root->left,root->right);
    }
    bool sameTree(Node* x, Node* y) {
        // if(!x and !y) return true;
        // if(x==NULL and y!=NULL or x!=NULL and y==NULL) return false;
        //this replaces above two statements
        if(!x or !y) return x==y;
        return 
            sameTree(x->left ,y->right) && 
            x->data == y->data && 
            sameTree(x->right,y->left);
    }
};