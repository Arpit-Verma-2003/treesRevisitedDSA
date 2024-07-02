class Solution
{
    // logic - check the left and right child , if both subtree of
    // single valued then check if both have equal value to parent 
    // or even exist , if all conditions satisfy then increase count
    // and return true
    public:
    bool solve(Node* root , int& cnt){
        if(root==NULL) return true;
        // check left and right child if singlevalued subtree or not;
        bool left = solve(root->left,cnt);
        bool right = solve(root->right,cnt);
        // conditions
        // if even child false, return false
        if(left==false||right==false) return false;
        // 1st root ka left child hai but same nhi return false;
        if(root->left&&root->left->data!=root->data) return false;
        // 1st root ka right child hai but same nhi return false;
        if(root->right&&root->right->data!=root->data) return false;
        // if childs same or leaft , then just return true while
        // increasing the count;
        cnt++;
        return true;
    }
    int singlevalued(Node *root)
    {
        //code here
        int ans =0;
        solve(root,ans);
        return ans;
    }
    
};
