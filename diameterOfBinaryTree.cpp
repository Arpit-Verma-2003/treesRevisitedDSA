struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
//   pehele leftheight nikal lo (left subtree ki) + rightheight(right "")
// add, at each node find , jiske through max , 1+ return;
    // Function to return the diameter of a Binary Tree.
    int maxDia(Node* root,int& maxi){
        if(root==NULL) return 0;
        int lh = maxDia(root->left,maxi);
        int rh = maxDia(root->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1 + max(lh,rh);
    }
    int diameter(Node* root) {
        // Your code here
        int maxi = 0;
        maxDia(root,maxi);
        return maxi+1;
    }
};
