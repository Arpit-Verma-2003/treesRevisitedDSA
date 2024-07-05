/*Complete the function below
Node is as follows
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
    // logic - find inorder (in sorted order)
    // we got sorted array , simple 2 sum problem
    // 2 pointer , add if found return true.
    void inOrder(Node* root,vector<int>&inorder){
        if(root==NULL) return;
        inOrder(root->left,inorder);
        inorder.push_back(root->data);
        inOrder(root->right,inorder);
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
        vector<int> inorder;
        inOrder(root,inorder);
        int i = 0;
        int j = inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]==target) return true;
            if(inorder[i]+inorder[j]>target) j--;
            else i++;
        }
        return false;
    }
};
