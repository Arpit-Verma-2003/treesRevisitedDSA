class Solution {
  public:
//   logic  - 
// in a preorder , the rule is, if for current element , there 
// whereever exist a greator element ahead than it then uske aage ke bhi
// saare elements greator hone chaiye coz in preorder , root left right
// so pehele left me chote aaye , but then jab ek bada aya then it means
// right ke elements started to now saare bade hone chaiye .

// Now to do the same while saving space we use stack , so jab chota ara
// add krte raho stack me koi dikkat nhi(left elements) , jab st.top se bada aya toh new
// parent  = st.top nd then pop krdo (right elements). if parent se bhi chota, then return 
// false coz not possible. kyuki right me chote nhi aa sakte ab
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int> st;
        int parent = INT_MIN;
        for(int i=0;i<N;i++){
            while(!st.empty()&&arr[i]>st.top()){
                parent = st.top();
                st.pop();
            }
            if(arr[i]<parent) return 0;
            st.push(arr[i]);
        }
        return 1;
    }
};
