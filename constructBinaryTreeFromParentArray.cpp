/* node structure  used in the program

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
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int,Node*> mp;
        for(int i=0;i<parent.size();i++){
            Node* node = new Node(i);
            mp[i] = node;
        }
        Node* root = NULL;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1){
                root = mp[i];
            }
            else{
                if(mp[parent[i]]->left==NULL) mp[parent[i]]->left = mp[i];
                else mp[parent[i]]->right = mp[i];
            }
        }
        return root;
    }
};
