vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
    queue<Node*> q;
    q.push(node);
    vector<vector<int>> res;
    while(!q.empty()) {
        int n = q.size();
        vector<int> tmp(n,0);
        for(int i = 0; i < n; i++) {
            node = q.front(),q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            tmp[i] = node->data;
        }
        res.push_back(tmp);
    }
    return res;
}