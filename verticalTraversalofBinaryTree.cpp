class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
//   logic - keep the count of vertical line and level together with the
// node in a map, insert all the nodes with vert , lvl in a map using 
// queue. In end insert the nodes into ans vector in order of vert & then
// lvl.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<Node*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        Node* troot = root;
        q.push({troot,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int vert = p.second.first;
            int lvl = p.second.second;
            nodes[vert][lvl].insert(node->data);
            if(node->left) q.push({node->left,{vert-1,lvl+1}});
            if(node->right) q.push({node->right,{vert+1,lvl+1}});
        }
        for(auto &p:nodes){
            for(auto &q:p.second){
                ans.insert(ans.end(),q.second.begin(),q.second.end());
            }
        }
        return ans;
    }
};
