//User function Template for C++

class Solution{
    public:
    // logic - traverse whole tree while adding root
    // value to dist , when leaf node , check if
    // maxValue is less then dist , so update.
    // return maxValue
    void maxPath(Node* root,int& mdist,int dist){
        if(root==NULL){
            return;
        }
        dist += root->data;
        if(root->left==NULL&&root->right==NULL){
            if(mdist<dist) mdist = dist;
        }
        maxPath(root->left,mdist,dist);
        maxPath(root->right,mdist,dist);
        return;
    }
    int maxPathSum(Node* root)
    {
        //code here
        int mdist = INT_MIN;
        maxPath(root,mdist,0);
        return mdist;
    }
};
