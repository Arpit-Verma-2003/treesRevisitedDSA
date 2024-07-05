//User function Template for C++

/*struct Node
{
	int data;
	struct Node *left, *right;
};*/

class Solution
// logic = consider a BST , now current root value 
// would be addition of all right nodes, so go to right
// when reach right null , return , then return to rightmost
// node , update value to sum i.e 0 currently coz usse koi bada
// nhi , then add root value into sum ,then go to left , update
// left with value of sum , add sum with root value. fir vapis gye
// toh firse update value with sum nd root + sum = sum for others.
{
    public:
    void solve(Node* root,int& sum){
        // base condition
        if(root==NULL) return ;
        // first go right to calculate sum total right subtree
        solve(root->right,sum);
        // then update node data with sum
        int tsum = sum; 
        // add value to the sum
        sum+=root->data;
        root->data = tsum;
        // now go to left
        solve(root->left,sum);
        
    }
    void transformTree(struct Node *root)
    {
        //code here
        int sum =0;
        solve(root,sum);
    }
};
