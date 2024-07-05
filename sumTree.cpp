/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    // logic = go the leafs, if leaf = return root->data
    // or else compare left+right==root->data if not f=0 then return total
    // root+left+right upar nd keep comparing.
    public:
    int f=1;
    int solve(Node* root){
        if(f==0) return 0;
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return root->data;
        int left = solve(root->left);
        int right = solve(root->right);
        if(root->data!=left+right) f=0;
        return root->data+left+right;
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         f=1;
         solve(root);
         return f;
    }
};
