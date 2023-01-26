class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        map<int,map<int,vector<int>>> d;
        //vo(root,0,0,d);
        BFS(root,d);
        vector<int> res;
        for (auto x : d) {
            for (auto i: x.second) {
                res.insert(res.end(),i.second.begin(),i.second.end());
            }
        }
        return res;
    }
    void vo(Node* root,int lvl ,int ver ,map<int,map<int,vector<int>>> &d) {
        if(!root) return;
        vo(root->left,lvl+1,ver-1,d);
        vo(root->right,lvl+1,ver+1,d);
        d[ver][lvl].push_back(root->data);
    }
    void BFS(Node * root, map<int,map<int,vector<int>>> &d) {
        // pair<Node*,pair<int,int>> p(root,pair<int,int>(0,0));
        //{node,{ver,lvl}}
        queue<pair<Node*,pair<int,int>>> q;
        int ver=0,lvl=0;
        q.push({root,{ver,lvl}});
        while (!q.empty()) {
            int n = q.size();
            for(int i = 0;i < n; i++) {
                root = q.front().first;
                tie(ver,lvl) = q.front().second;
                q.pop();
    	        if(root->left) q.push({root->left,{ver-1,lvl+1}});
    	        if(root->right) q.push({root->right,{ver+1,lvl+1}});
    	        d[ver][lvl].push_back(root->data);
            }
        }
    }
};