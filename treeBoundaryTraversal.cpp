/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
// logic - add all left nodes , then all leaf nodes and lastly 
// add all right nodes in reverse order


// logic for leftNodes =
// go to left , if not leaf node, add in ans vector 
// go to left again repeat, if left not available , only
// then go to right and add.

    void leftNodes(Node* root , vector<int>& ans){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur))ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur = cur->right;
        }
    }
    
    
// logic for RightNodes =
// go to right , if not leaf node, add in temp vector 
// go to right again repeat, if right not available , only
// then go to left and add. Reverse and add in ans vector

    void rightNodes(Node* root , vector<int>& ans){
        Node* cur = root->right;
        vector<int>tmp;
        while(cur){
            if(!isLeaf(cur))tmp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur = cur->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            ans.push_back(tmp[i]);
        }
    }
    
// logic for LeafNodes=
// Do simple inorder , add if leaf node (base condition)
    
    void leafNodes(Node* root, vector<int>&ans){
        if(!root) return;
        // simple inorder
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    
    bool isLeaf(Node* root){
        return (root != nullptr && root->left == nullptr && root->right == nullptr);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        // first add left nodes, then leaf nodes and lastly right nodes;
        leftNodes(root,ans);
        leafNodes(root,ans);
        rightNodes(root,ans);
        return ans;
    }
};
