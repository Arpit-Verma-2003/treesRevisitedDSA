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

// logic - 
// if root = null ,then maximum path sum = 0
// if root = leaf node, then max path sum = leaf value
// if root's left and right exists then update max = left+right+node (full path)
// and return node value + max(left , right) coz ek hi max hoga upar se linked
// if only right or left child but not root node, hence just return coz its not
// special node , nor a node through which path can be generated ,just in the way

class Solution {
public:
    int solve(Node* root,int& maxi){
        // base conditions - 
        // null node then return 0
        if(!root) return 0;
        // leaf node then return node
        if(!root->left&&!root->right) return root->data;
        // calculate for left and right
        int left = solve(root->left,maxi);
        int right = solve(root->right,maxi);
        // if both left and right exist , then set maxi & return
        if(root->left&&root->right){
            maxi = max(maxi,root->data+left+right);
            return root->data+max(left,right);
        }
        // if only left or right exist.
        if(root->left){
            return root->data+left;
        }
        if(root->right){
            return root->data+right;
        }
        
    }
    int maxPathSum(Node* root)
    {
        // code here
        int maxi = INT_MIN;
        int ans = solve(root,maxi);
        if(root->left&&root->right) return maxi;
        // special case - if root's child is only either left or right, 
        // then it is also special node , so consider ans too if max , coz vo
        // root tak ki value dega add krke but maxi would not as update nhi hua hoga
        // vo for the case of only left or right child existing.
        return max(ans,maxi);
    }
};
