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
    //Function to check if S is a subtree of tree T.
    bool solve2(Node*n1,Node*n2){
        if(n1==NULL&&n2==NULL) return true;
        if(n1==NULL||n2==NULL) return false;
        if(n1->data!=n2->data) return false;
        return solve2(n1->left,n2->left) && solve2(n1->right,n2->right);
    }
    bool solve(Node* n1 , Node* n2){
        if(n1==NULL) return false;
        if(solve2(n1,n2)) return true;
        return solve(n1->left,n2) || solve(n1->right,n2);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        return solve(T,S);
        
    }
};
