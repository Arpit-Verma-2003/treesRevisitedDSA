/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int check(Node* root,bool& ans){
        if(root==NULL) return 0;
        int lh = check(root->left,ans);
        int rh = check(root->right,ans);
        if(lh-rh > 1 || rh-lh >1){
          ans = false;
        } 
        return max(lh,rh)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool ans = true;
        check(root,ans);
        return ans;
    }
};
