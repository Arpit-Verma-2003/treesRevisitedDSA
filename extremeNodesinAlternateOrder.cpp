/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    
    // logic = we need to print leftmost nd rightmost inversely
    // since we want level order , we use queue, now
    // if we use flag for odd and even level check.
    // if flag = odd , then we want the last element 
    // hence , we keep decreasing n , nd if n==queuesize-1
    // and flag odd, then add to ans since first child node
    // for the even level , we want the last , so we keep 
    // decreasing the n until it becomes 0 , then the curr element
    // is pusheed into the answer vector.
    
  public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> ExtremeNodes(Node* root)
    {
        // Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        bool f = 0;
        while(!q.empty()){
            int qSize = q.size();
            int n = qSize;
            while(n--){
                // deque all current elements
                // and enque all child elements of current elements
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                // check if odd level pick first element
                if(f&&n==qSize-1) ans.push_back(curr->data);
                // check if even level pick last element
                if(!f&&n==0) ans.push_back(curr->data);
            }
            // change flag each time
            f= !f;
        }
        return ans;
    }
};
