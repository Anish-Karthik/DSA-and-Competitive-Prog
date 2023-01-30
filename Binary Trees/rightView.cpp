/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // return bfsOp(root);
        vector<int> res;
        dfsOp(root,0,res);
        // map<int,int> d;
        // dfs(root,d);
        // vector<int> res(d.size());
        // int j = 0;
        // for (auto i : d) {
        //     res[j++]=i.second;
        // }
        return res;
    }
    void bfs(Node * root, map<int,int> &d) {
        //{node,ver}
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while (!q.empty()) {
            int n = q.size();
            int lvl;
            for(int i = 0;i < n; i++) {
                tie(root,lvl) = q.front(),q.pop();
    	        if(root->left) q.push({root->left,lvl+1});
    	        if(root->right) q.push({root->right,lvl+1});
    	        d[lvl]=(root->data);
            }
        }
    }
    void dfs(Node* root,map<int,int> &d,int lvl = 0) {
        if(!root) return;
        dfs(root->left,d,lvl+1);
        dfs(root->right,d,lvl+1);
        d[lvl] = root->data;
    }
    vector<int> bfsOp(Node * root) {
        vector<int> res;
        if(!root) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0;i < n; i++) {
                root = q.front(),q.pop();
    	        if(root->left) q.push(root->left);
    	        if(root->right) q.push(root->right);
            }
            res.push_back(root->data);
        }
        return res;
    }
    void dfsOp(Node* root,int lvl,vector<int> &res) {
        if(!root) return;
        if(lvl == res.size()) res.push_back(root->data);
        dfsOp(root->right,lvl+1,res);
        dfsOp(root->left,lvl+1,res);
    }
};