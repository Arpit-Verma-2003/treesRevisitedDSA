/* struct Node
{
int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    
    // logic = 
    // do the level order traversal to get the right nodes
//  in the queue , then keep connecting the right nodes
// with q.front until next level. to check next level
// maintain n & qsize. keep decrementing n until 0 then
// next level. if n==0 , means at this lvel last element hence
// make null the nextRight element
    
    void connect(Node *root)
    {
       // Your Code Here
       if(root==NULL) return;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
            int qSize = q.size();
            int n = qSize;
            while(n--){
                Node* curr = q.front();
                q.pop();
                if(n==0) curr->nextRight = NULL;
                else curr->nextRight = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
           }
       }
       return ;
    }    
      
};
