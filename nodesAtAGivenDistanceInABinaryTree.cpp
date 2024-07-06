/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

// logic - 
// step 1 - mark parents of each node so as it traverse in all direction
// - use a map to store parents
// step 2 - find the target node
// step 3 - use queue, traverse in all 3 directions(parent, left & right) upto
// k distance. 
// - maintain a visited map as we don't want to traverse parent/already visited node
// step 4 - put queue values in an vector , sort and return.

class Solution
{
private:

public:
    void markParents(Node* root,unordered_map<Node*,Node*>&mp){
        if(root==NULL) return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return ;
    }
    Node* findTarget(Node* root,int target){
        if(root==NULL) return NULL;
        if(root->data==target) return root;
        Node* left = findTarget(root->left,target);
        Node* right = findTarget(root->right,target);
        if(left!=NULL) return left;
        else return right;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> ans;
        if(root==NULL) return ans;
        unordered_map<Node*,Node*> mp;
        markParents(root,mp);
        queue<Node*>q;
        Node* node = findTarget(root,target);
        q.push(node);
        int dist = 0;
        unordered_map<Node*,bool> visited;
        visited[node] = true;
        while(!q.empty()){
            if(dist++==k) break;
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left&&!visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right&&!visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(mp[curr]&&!visited[mp[curr]]){
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
