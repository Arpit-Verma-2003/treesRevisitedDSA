/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
// logic - if node not null, keep going left while 
// adding the elements into stack, as node = null
// add st.top()(recent element) to inorder and
// go right for further traverse.
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> ans;
        stack<Node*> st;
        Node* temp = root;
        while(true){
            if(temp!=NULL){
                st.push(temp);
                temp=temp->left;
            }
            else{
                if(st.empty()) break;
                temp = st.top();
                ans.push_back(temp->data);
                st.pop();
                temp=temp->right;
            }
        }
        return ans;
    }
};
