/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this function*/
    // logic -  do level order traversal , keep mark
    // additional of level , if level == odd , add in 
    // odd variable or else to even. subtract&return.
    int getLevelDiff(Node *root)
    {
       //Your code here
       if(root==NULL) return 0;
       queue<pair<Node* , int>> q;
       int odd = 0 , even = 0;
       q.push({root,1});
       while(!q.empty()){
           Node* node = q.front().first;
           int level = q.front().second;
           q.pop();
           if(level==1) odd += node->data;
           else even += node->data;
           if(node->left&&level==1) q.push({node->left,0});
           if(node->left&&level==0) q.push({node->left,1});
           if(node->right&&level==1) q.push({node->right,0});
           if(node->right&&level==0) q.push({node->right,1});
       }
       return odd-even;
    }
};
