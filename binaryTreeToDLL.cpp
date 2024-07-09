/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
// logic - do inorder traversal , maintain a prev ptr
// set head = root if prev = NULL. 
// else set root->left = prev (root se pehele wala inorder me set left)
// & set prev->right = root (prev ke next = right of it);
class Solution
{
    public: 
    // Function to convert binary tree to doubly linked list and return it.
    // set head & prev to NULL inititially
    Node* head = NULL;
    Node* prev = NULL;
    Node * bToDLL(Node *root)
    {
        // your code here
        // base condition if root null
        if(root==NULL) return NULL;
        // inorder , go left
        bToDLL(root->left);
        // if prev null hence it is head(first node) 
        if(prev==NULL) head = root;
        // else set prev's right to root & root's left to prev
        else{
            prev->right = root;
            root->left = prev;
        }
        // update prev to root
        prev = root;
        // inorder , go right
        bToDLL(root->right);
        // return the head
        return head;
    }
};
