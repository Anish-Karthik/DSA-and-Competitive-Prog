class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return height(root)==-1?0:1;
    }
    int height(Node *node){
        if(!node) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        if(abs(lh-rh)>1 or lh==-1 or rh == -1) return -1;
        return 1 + max(lh,rh);
    }
};