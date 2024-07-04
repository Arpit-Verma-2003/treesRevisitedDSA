/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  public:
//   logic - follow same logic as Lowest Common Ancestor
    // Function should return all the ancestor of the target node
    Node* ancestors(Node* root,int target,vector<int>&ans){
        if(root==NULL) return NULL;
        if(root->data==target) return root;
        Node* left = ancestors(root->left,target,ans);
        Node* right = ancestors(root->right,target,ans);
        if(left==NULL&&right==NULL) return NULL;
        if(left!=NULL||right!=NULL){
            ans.push_back(root->data);
            return root;
        }
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        if(root==NULL) return ans;
        ancestors(root,target,ans);
        return ans;
    }
};
