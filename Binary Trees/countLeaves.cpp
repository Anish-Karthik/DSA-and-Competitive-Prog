int countLeaves(Node* root)
{
  // Your code here
    if(root){
        if(!root->right&&!root->left)
            return 1;
        return countLeaves(root->left)+countLeaves(root->right);
    }
    return 0;
}