/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // void setParent(Node* root,map<Node*,Node*>&mp){
    //     // base case
    //     if(!root) return ;
    //     if(root->left){
    //         mp[root->left] = root;
    //         setParent(root->left,mp);
    //     }
    //     if(root->right){
    //         mp[root->right] = root;
    //         setParent(root->right,mp);
    //     }
    // }
    
    // Node* findTargetNode(Node* root,int target){
    //     if(!root) return NULL;
    //     if(root->data==target) return root;
    //     Node* left = findTargetNode(root->left,target);
    //     Node* right = findTargetNode(root->right,target);
    //     if(left) return left;
    //     return right;
    // }
    
    // void countTime(Node* node,int count,map<Node*,bool>&vis,int&maxi,map<Node*,Node*>mp){
    //     if(!node) return ;
    //     vis[node] = true;
    //     maxi = max(maxi,count);
    //     if(node->left&&!vis[node->left]){
    //         countTime(node->left,count+1,vis,maxi,mp);
    //     }
    //     if(node->right&&!vis[node->right]){
    //         countTime(node->right,count+1,vis,maxi,mp);
    //     }
    //     if(mp[node]&&!vis[mp[node]]){
    //         countTime(mp[node],count+1,vis,maxi,mp);
    //     }
    // }
    
    Node* setParent(Node* root,map<Node*,Node*>&mp,int target){
        // base case
        if(!root) return NULL;
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data==target) res = front;
            if(front->left){ 
                q.push(front->left);
                mp[front->left] = front;
            }
            if(front->right) {
                q.push(front->right);
                mp[front->right] = front;
            }
        }
        return res;
    }
    
    int countTime(Node* root,map<Node*,Node*>&mp){
        map<Node*,bool> vis;
        queue<Node*>q;
        q.push(root);
        vis[root] = true;
        int ans = 0;
        while(!q.empty()){
            bool flag = 0;
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                Node* front = q.front();
                q.pop();
                if(front->left&&!vis[front->left]){
                    flag = 1;
                    vis[front->left] = true;
                    q.push(front->left);
                }
                if(front->right&&!vis[front->right]){
                    flag = 1;
                    vis[front->right] = true;
                    q.push(front->right);
                }
                if(mp[front]&&!vis[mp[front]]){
                    flag = 1;
                    vis[mp[front]] = true;
                    q.push(mp[front]);
                }
            }
            if(flag == 1) ans++;
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>mp;
        Node* node = setParent(root,mp,target);
        return countTime(node,mp);
    }
};
