/*struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
    // logic - first go into subtrees , now check if data<lb
    // then return right child, or if data>ub return left child
    // or else simple return root if all well
    public:
    Node* solve(Node* root,int lb , int ub){
        if(root==NULL) return NULL;
        root->left = solve(root->left,lb,ub);
        root->right = solve(root->right,lb,ub);
        if(root->data<lb){
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        } 
        if(root->data>ub){
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }
        return root;
    }
    Node* removekeys(Node* root, int l, int r) {
        // code here
        Node* node = solve(root,l,r);
        return node;
    }
};
