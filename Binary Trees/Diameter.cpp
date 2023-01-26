class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int maxi = 0;
    int diameter(Node* root) {
        maxi = 0;
        height(root);
        return maxi+1;
    }
    int height(Node *root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
};