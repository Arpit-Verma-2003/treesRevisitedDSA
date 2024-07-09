//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* sortedListToBST(LNode *head) {
        //code here\
        // base conditions
        if(!head) return NULL;
        if(!head->next) return new TNode(head->data);
        // slow and fast pointer for getting middle element
        LNode* slow = head;
        LNode* fast = head;
        // slowprev pointer to break the list by setting slowPrev->next = NULL;
        LNode* slowPrev = NULL;
        while(fast!=NULL&&fast->next!=NULL){
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow would be at mid;
        TNode* root = new TNode(slow->data);
        slowPrev->next = NULL;
        // left & right sublist call
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        // return the root
        return root;
    }
};
