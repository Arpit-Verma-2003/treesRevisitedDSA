class Solution
{
    // same vohi ki inorder nikal lo fir n-k return or reverse order me
    // kth return , but to save space complexity, ans vector ki jagah
    // counter badhate raho , when k==counter, store krlo ans & return
    public:
    int ans;
    void solve(Node* root , int k,int& cnt){
        if(root==NULL) return;
        solve(root->right,k,cnt);
        cnt++;
        if(k==cnt){
            ans = root->data;
            return;
        }
        solve(root->left,k,cnt);
    }
    int kthLargest(Node *root, int K)
    {
        int cnt = 0;
        solve(root,K,cnt);
        return ans;
    }
};
