/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
//   logic - next element check , agar kam toh left me insert(recursion);
// if element greater , then just return coz fir left me nhi lag satka or i==n
// (base condition) , for left call , ub = root->data, for right call same ub
// ub = upper bound
// 2nd option - sort preorder = inorder , by using in & preorder construct tree.  
    // Function that constructs BST from its preorder traversal.
    Node* bst(int pre[],int& i,int n,int ub){
        // base condition
        if(i==n||pre[i]>ub) return NULL;
        Node* root = newNode(pre[i++]);
        root->left = bst(pre,i,n,root->data);
        root->right = bst(pre,i,n,ub);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int i = 0;
        Node* root = bst(pre,i,size,INT_MAX);
        return root;
    }
};
