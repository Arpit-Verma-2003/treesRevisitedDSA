/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    // logic - firstly clone the tree simple without random pointer
    // store the original & copy node together in a map while creating
    // lastly use map to assign the random pointer
    // copy->random = mp[root->random];
       
    Node* newTree(Node* root,map<Node*,Node*>&mp){
        // base condition
        if(!root) return NULL;
        mp[root] = new Node(root->data);
        mp[root]->left = newTree(root->left,mp);
        mp[root]->right = newTree(root->right,mp);
        return mp[root];
    }
    
    void connectRand(Node* root,map<Node*,Node*>&mp){
        if(!root) return;
        mp[root]->random = mp[root->random];
        connectRand(root->left,mp);
        connectRand(root->right,mp);
    }
       
    Node* cloneTree(Node* tree)
    {
       //Your code here
       if(tree==NULL) return NULL;
       map<Node*,Node*>mp;
       Node* root = newTree(tree,mp);
       connectRand(tree,mp);
       return root;
    }
};
