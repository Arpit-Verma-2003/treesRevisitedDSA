/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        // check left and right child if singlevalued subtree or not;
        bool left = isUnivalTree(root->left);
        bool right = isUnivalTree(root->right);
        // conditions
        // if even child false, return false
        if(left==false||right==false) return false;
        // 1st root ka left child hai but same nhi return false;
        if(root->left&&root->left->val!=root->val) return false;
        // 1st root ka right child hai but same nhi return false;
        if(root->right&&root->right->val!=root->val) return false;
        // if childs same or leaft , then just return true while
        // increasing the count;
        return true;
    }
};
