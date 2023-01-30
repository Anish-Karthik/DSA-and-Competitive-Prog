/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* cur) {
        // Your code here
        vector<int> res;
        while(cur) {
            if(!cur->left) {
                res.push_back(cur->data);
                cur = cur->right;
            }else {
                Node* prev = cur->left;
                while(prev->right and prev->right!=cur) {
                    prev =prev->right;
                    
                }
                if(prev->right!=cur) {
                    prev->right = cur;
                    cur = cur->left;
                }else {
                    prev->right = NULL;
                    res.push_back(cur->data);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};