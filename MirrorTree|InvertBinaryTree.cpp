/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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
    // Function to convert a binary tree into its mirror tree.
    void mirroring(Node* node){
        if(node==NULL) return;
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirroring(node->left);
        mirroring(node->right);
    }
    void mirror(Node* node) {
        // code here
        mirroring(node);
        
    }
};
