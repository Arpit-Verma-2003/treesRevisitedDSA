//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
    // logic = 
    // 2 steps
        // 1st step - find the inorder to get the sorted array
        // 2nd step - fill the tree with sorted array in preorder traversal
  public:
    void getInorder(Node* root,vector<int>&ans){
        if(root==NULL) return;
        getInorder(root->left,ans);
        ans.push_back(root->data);
        getInorder(root->right,ans);
    }
    void putPreorder(Node* root,vector<int>&ans,int &i){
        if(root==NULL) return;
        putPreorder(root->left,ans,i);
        putPreorder(root->right,ans,i);
        root->data = ans[i++];
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int> ans;
        int i = 0;
        getInorder(root,ans);
        putPreorder(root,ans,i);
    }    
};
