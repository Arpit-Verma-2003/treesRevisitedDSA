/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// keep going down while adding nodes into a vector
// then start a loop to add all elements from last (since given downward dirn)
// if sum == k then count++
// then also pop_back to remove the added node for backtracking.

class Solution{
  public:
    void solve(Node *root,int k,vector<int>&v,int& count){
        // base case - if root null
        if(root==NULL) return;
        // add node in the vector
        v.push_back(root->data);
        // traverse right & left first
        solve(root->left,k,v,count);
        solve(root->right,k,v,count);
        // initialize sum
        int sum = 0;
        for(int i = v.size()-1;i>=0;i--){
            // add each node to sum
            sum+=v[i];
            // check each time if sum == k(we don't break here 
            // coz there could be ahead -ve value which adds 1 more path
            // with the same sum as k)
            // if yes then increase count
            if(sum==k) count++;
        }
        // pop back the element before backtracking
        v.pop_back();
        
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int>v;
        int cnt = 0;
        solve(root,k,v,cnt);
        return cnt;
    }
};
