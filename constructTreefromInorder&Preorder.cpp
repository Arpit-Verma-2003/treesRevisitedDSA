/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

int positionFind(int in[],int element,int start ,int inEnd){
    for(int i=start;i<=inEnd;i++){
        if(in[i]==element) return i;
    }
    return -1;
}

Node* build(int in[],int pre[],int& preInd,int inStart,int inEnd,int n){
    // base condition - 
    if(preInd>=n|| inStart>inEnd) return NULL;
    int element = pre[preInd++];
    Node* root = new Node(element);
    int position = positionFind(in,element,inStart,inEnd);
    if(position == -1) return NULL;
    root->left = build(in,pre,preInd,inStart,position-1,n);
    root->right = build(in,pre,preInd,position+1,inEnd,n);
    return root;
}

class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,int> mp;
        int preInd = 0;
        Node* root = build(in,pre,preInd,0,n-1,n);
        return root;
    }
};
