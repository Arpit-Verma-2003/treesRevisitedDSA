/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

// logic - 
// 2 methods - 
// 1 -
// either find inorder (ascending order) , nd then traverse inorder
// swap elements which aren't following the order
// 2 - (better space complexity as we don't store inorder)
// maintain a prev_ptr , first_ptr(first violated element) , second_ptr(
// second violated element) , middle element(if second not found so agla hi)
// if at any time prev > curr , then store first/middle/second & at last swap
// middle used for case for ex - 1,5.8(first),7(middle),9,12,34.

class Solution {
    private:
    // initialize pointers.
        Node* first;
        Node* middle;
        Node* second;
        Node* prev;
  public:
    void inOrder(Node* root){
        // base condition
        if(!root) return;
        // go left
        inOrder(root->left);
        // if curr<prev
        if(root->data<prev->data){
            // set first & middle if not set yet
            if(first==NULL){
                first = prev; 
                middle = root;
            } 
            // else set second
            else {
                second = root;
            }
        }
        // update previous
        prev = root;
        // go to right
        inOrder(root->right);
    }
    
    void correctBST( struct Node* root )
    {
        // add code here.
        // set all ptrs to NULL initially
        first=middle=second=NULL;
        // intialize prev to min node
        prev = new Node(INT_MIN);
        inOrder(root);
        // if first & second violate found 
        if(first&&second) swap(first->data,second->data);
        // if second not found than swap with middle 
        else swap(first->data,middle->data);
        
    }
};
