//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

// logic - to count the no. of turns 
// step 1 - find the lca (to know path)
// step 2 - if lca is not any of element , total turns
// = 1+ turns in left & right
// to check direction maintain a boolean , if direction change
// add 1 to count stating direction change

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    Node* findLca(Node* root,int first,int second){
        if(!root) return NULL;
        if(root->data==first||root->data==second) return root;
        Node* left = findLca(root->left,first,second);
        Node* right = findLca(root->right,first,second);
        // 3 conditions - 
        // 1 - if both right & left present , then root is lca
        if(left&&right) return root;
        // 2 - if none present then return null
        // if(!left&&!right) return NULL;
        // 3 - if either left or right present 
        if(left) return left;
        else return right;
    }
    
    bool countTurns(Node* root,int element,bool flag , int& count){
        if(!root) return false;
        if(root->data==element) return true;
        if(flag){
            if(countTurns(root->left,element,flag,count)) return true;
            if(countTurns(root->right,element,!flag,count)){
                count++;
                return true;
            }
        }
        else{
            if(countTurns(root->right,element,flag,count)) return true;
            if(countTurns(root->left,element,!flag,count)){
                count++;
                return true;
            } 
        }
        return false;
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
    //   find lca
      Node* lca = findLca(root,first,second);
    //   if lca not present return -1 since no path
      if(!lca) return -1;
      int count = 0; // intialize counter
    //   if lca is except first & second element , 
    // go for countTurns for left & right direction for both elements.
      if(lca->data!=first&&lca->data!=second){
          if(countTurns(lca->left,first,true,count)
          ||countTurns(lca->right,first,false,count));
          
          if(countTurns(lca->left,second,true,count)
          ||countTurns(lca->right,second,false,count));
          return count+1;
      }
      if(lca->data==first){
          if(countTurns(lca->left,second,true,count)
          ||countTurns(lca->right,second,false,count));
        //   no need to add 1 since no turn at root level
          return count;
      }
      else{
          if(countTurns(lca->left,first,true,count)
          ||countTurns(lca->right,first,false,count));
          return count;
      }
    }
};
