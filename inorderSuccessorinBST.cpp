class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    // logic - keep going right until node->data<=x->data coz right me hi
    // hoga successor, jab equal se aage nikle right me
    // then go max left coz vohi successor , nd each time save successor 
    // agar by chance null nikla toh pehele wala hi
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        if(root==NULL||x==NULL) return NULL;
        Node* succ = NULL;
        while(root){
            if(root->data<=x->data){
                root = root->right;
            }
            else{
                succ = root;
                root=root->left;
            }
        }
        return succ;
    }
};
