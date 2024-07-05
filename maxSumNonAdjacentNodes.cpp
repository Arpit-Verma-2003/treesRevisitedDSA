//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    // logic = 
    // use dp logic , either take or not
    // if take (inc) then go add root->left childs & 
    // root->right childs , or else add root childs
    // compare and return max.
    // us map for dp less time complexity
    unordered_map<Node*,int> mp;
    int getMaxSum(Node *root) 
    {
        // Add your code here
        if(mp[root]) return mp[root];
        if(root==NULL) return 0;
        int inc = root->data;
        if(root->left){
            inc+= getMaxSum(root->left->left);
            inc+= getMaxSum(root->left->right);
        }
        if(root->right){
            inc+= getMaxSum(root->right->left);
            inc+= getMaxSum(root->right->right);
        }
        int exc = 0;
        exc+=getMaxSum(root->left);
        exc+=getMaxSum(root->right);
        return mp[root] = max(inc,exc);
    }
};
