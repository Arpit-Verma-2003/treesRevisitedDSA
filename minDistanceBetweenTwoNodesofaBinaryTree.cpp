/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    // logic - to find the min. distance, 
    // path would always be from the LCA of a & b
    // hence find lca , then find d1 - path from lca to a
    // then find d2 - path from lca to b
    // total min distance = d1 + d2 return.
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    
    // find LCA
    // logic = visualize a tree, if root->data == a||b hogya , then return 
    // krdo root . abh agar aesa nhi hua toh left ka nikalo nd right
    // agar dono me mil gya , yaani ki root lca return
    // agar left mehi mila to left return kro , upar hoga and similarly 
    // for right
    Node* findLca(Node* root,int a, int b){
        if(root==NULL) return NULL;
        if(root->data == a || root->data == b) return root;
        Node* left = findLca(root->left,a,b);
        Node* right = findLca(root->right,a,b);
        if(left==NULL&&right==NULL) return NULL;
        if(left!=NULL&&right!=NULL) return root;
        if(left!=NULL) return left;
        return right;
    }
    // find min dist from LCA
    int minDist(Node* root,int dist,int a){
        if(root==NULL) return -1;
        if(root->data==a) return dist;
        int left = minDist(root->left,dist+1,a);
        if(left!=-1) return left;
        return minDist(root->right,dist+1,a);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = findLca(root,a,b);
        if(lca==NULL) return -1;
        int d1 = minDist(lca,0,a); 
        int d2 = minDist(lca,0,b);
        return d1+d2;
    }
};
