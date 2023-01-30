class Solution
{
    bool isLeaf(Node* root) {
        return root->left or root->right;
    }
    public:
    bool hasPathSum(Node *root, int S, int s=0) {
        if(!root) return false;
        bool left = hasPathSum(root->left,S,s+root->data);
        bool right = hasPathSum(root->right,S,s+root->data);
        if( left or right) return true;
        if(isLeaf(root) && s+root->data==S) return true;
        return false;
    // Your code here
    }
};
