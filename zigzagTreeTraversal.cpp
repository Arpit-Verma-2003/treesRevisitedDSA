class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    // logic , simply do level order traversal , bus ek flag rakhlo 
    // and at each even level, reverse krke add krdo
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*>q;
    	q.push(root);
    	if(root==NULL) return ans;
    	int fl = 1;
    	while(!q.empty()){
    	    vector<int> temp;
    	    int s = q.size();
    	    while(s--){
    	        Node* t = q.front();
    	        temp.push_back(t->data);
    	        q.pop();
    	        if(t->left) q.push(t->left);
    	        if(t->right) q.push(t->right);
    	    }
    	    if(fl%2==0) reverse(temp.begin(),temp.end());
    	    for(int i=0;i<temp.size();i++) ans.push_back(temp[i]);
    	    fl=!fl;
    	}
    	return ans;
    }
};
