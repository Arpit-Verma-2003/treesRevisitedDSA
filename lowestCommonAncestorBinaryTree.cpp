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

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    // logic - if left and right me hai element , then lca = root
    // if left or right dono me nhi , so return null, yaha hai hi nhi lca
    // if data ==n1||n2 then return root, isse upar wale me kahi lca
    // left or right calculate
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL) return NULL;
       if(root->data==n1||root->data==n2) return root;
       Node* left = lca(root->left,n1,n2);
       Node* right = lca(root->right,n1,n2);
       if(left!=NULL&&right!=NULL) return root;
       if(left==NULL&&right==NULL) return NULL;
       if(left!=NULL) return left;
       return right;
    }
};
