class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        // edge cases - 
        int maxi = 0;
        if(N==1||N==2) return 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i][0]==arr[i+1][0]){
                maxi = max(maxi,__gcd(arr[i][1],arr[i+1][1]));
            }
        }
        return maxi;
    }
};
