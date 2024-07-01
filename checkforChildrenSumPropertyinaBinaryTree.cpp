/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool check(Node* root){
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        if(root->left==NULL){
            if(root->right->data!=root->data) return false;
            return check(root->right);
        } 
        if(root->right==NULL){
          if(root->left->data!=root->data) return false;
          return check(root->left);
        } 
        if(root->left->data+root->right->data != root->data) return false;
        bool a = check(root->left);
        bool b = check(root->right);
        return a&b;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     return check(root);
    }
};
