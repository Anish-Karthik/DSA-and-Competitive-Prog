class Solution {
private:
    bool isLeaf(Node* root) {
        return root and !root->left and !root->right;
    }
    void addLeft(Node* root,vector<int> &res) {
        root = root->left;
        while (root and !isLeaf(root)) {
            res.push_back(root->data);
            if (root->left) root = root->left;
            else root = root->right;
        }
    }
    void addRight(Node* root,vector<int> &res) {
        stack<int> s;
        root = root->right;
        while (root and !isLeaf(root)) {
            s.push(root->data);
            if (root->right) root = root->right;
            else root = root->left;
        }
        while(!s.empty()) {
            res.push_back(s.top()),s.pop();
        }
    }
    void addLeaf(Node* root,vector<int> &res) {
        if(!root) return;
        addLeaf(root->left,res);
        addLeaf(root->right,res);
        if(isLeaf(root)) res.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeft(root,res);
        addLeaf(root,res);
        addRight(root,res);
        return res;
    }
};