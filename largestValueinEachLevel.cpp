class Solution
{
    public:
    void solve(Node*root,vector<int>&ans,int lvl){
        if(root==NULL) return;
        if(lvl==ans.size()){
            ans.push_back(root->data);
        }
        else{
            if(ans[lvl]<root->data) ans[lvl] = root->data;
        }
        solve(root->left,ans,lvl+1);
        solve(root->right,ans,lvl+1);
    }
    vector<int> largestValues(Node* root)
    {
        //code here
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};
