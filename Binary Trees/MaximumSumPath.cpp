class Solution {
public:
    int findMaxSum(Node* root)
    {
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
private :
    int solve(Node* root,int &maxi){
        if(root == NULL) return 0;
        int lh = max(solve(root->left,maxi),0);
        int rh = max(0,solve(root->right,maxi));
        maxi = max(maxi,(root->data + lh + rh));
        return root->data + max(lh,rh);
    }
};