class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //map<int,int> d;
        map<int,pair<int,int>> m;//dfs
        dfs(root,0,0,m);
        //bfs(root,d);
        vector<int> res(m.size());//dfs
        int j = 0;
        // for (auto i : d) {
        //     res[j++]=i.second;
        // }
        for (auto i : m) {
            res[j++]=i.second.second;
        }
        return res;
    }
    void dfs(Node* root,int lvl ,int ver ,map<int,pair<int,int>> &d) {
        if(!root) return;
        dfs(root->left,lvl+1,ver-1,d);
        if (d.find(ver) == d.end() || d[ver].first>lvl){
            d[ver]={lvl,root->data};
        }
        dfs(root->right,lvl+1,ver+1,d);
    }
    void bfs(Node * root, map<int,int> &d) {
        //{node,ver}
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while (!q.empty()) {
            int n = q.size();
            int ver;
            for(int i = 0;i < n; i++) {
                tie(root,ver) = q.front(),q.pop();
                if(root->left) q.push({root->left,ver-1});
                if(root->right) q.push({root->right,ver+1});
                if (d.find(ver) == d.end())
                    d[ver]=(root->data);
            }
        }
    }
};