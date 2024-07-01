/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool symmetric(struct Node* n1,struct Node* n2){
        if(n1==NULL&&n2==NULL) return true;
        if(n1==NULL||n2==NULL) return false;
        if(n1->data!=n2->data) return false;
        bool a = symmetric(n1->left,n2->right);
        bool b = symmetric(n1->right,n2->left);
        return a&b;
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
	    return symmetric(root->left,root->right);
	    
    }
};
