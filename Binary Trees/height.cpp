class Solution{
    public:
    int height(struct Node* node){
        if(!node) return 0;
        return 1 + max(height(node->left),height(node->right));
    }
};