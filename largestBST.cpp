/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class BstNode{
    public:
    int maxNode,minNode,maxSize;
    BstNode(int minNode,int maxNode,int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        }
};
// logic - to find the largest bst 
// create a bst node class with integers minNode,maxNode,maxSize
// for left subtree we want the max value to be less than the current
// root value , and for the left subtree min value to be more than
// the current value . for the leaf node, we return INT_MIN,INT_MAX
// so that easily accepted as an bst
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    BstNode solve(Node* root){
        if(!root) return BstNode(INT_MAX,INT_MIN,0);    
        auto left = solve(root->left);
        auto right = solve(root->right);
        if(left.maxNode<root->data&&right.minNode>root->data){
            return BstNode(min(left.minNode,root->data),
            max(right.maxNode,root->data),left.maxSize+right.maxSize+1);
        }
        else return BstNode(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root).maxSize;
    }
};
