vector<int> findSpiral(Node *node)
{
  //Your code here
    if(!node) return vector<int>();
    queue<Node*> q;
    q.push(node);
    vector<int> res;
    bool rev = true;
    while(!q.empty()) {
        int n = q.size();
        vector<int> tmp(n,0);
        for(int i = 0; i < n; i++) {
            node = q.front(),q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(rev)
                tmp[n-i-1] = node->data;
            else 
                tmp[i] = node->data;
        }
        rev = !rev;
        res.insert(res.end(),tmp.begin(),tmp.end());
    }
    return res;
}