/* A binary tree node


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
    //Function to check if two trees are identical.
    bool isSame(Node *n1,Node *n2){
        if(n1==NULL && n2==NULL) return true;
        if(n1==NULL||n2==NULL) return false;
        if(n1->data!=n2->data) return false;
        bool a = isSame(n1->left,n2->left);
        bool b = isSame(n1->right,n2->right);
        return a&b;
    }
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        return isSame(r1,r2);
    }
};
