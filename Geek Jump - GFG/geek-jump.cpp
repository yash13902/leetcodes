//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int recur(vector<int> &height, int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int left = INT_MAX;
        int right = INT_MAX;
        left = recur(height, n-1, dp) + abs(height[n] - height[n-1]);
        if(n>1)
        right = recur(height, n-2, dp) + abs(height[n] - height[n-2]);
        return dp[n] = min(left, right);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        // //Memoiztion
        // vector<int> dp(n+1, -1);
        // return recur(height, n-1, dp);
        
        //tabulation
        // vector<int> dp(n, 0);
        // dp[0] = 0;
        // for(int i=1;i<n;i++){
        //     int l = dp[i-1] + abs(height[i-1] - height[i]);
        //     int r = INT_MAX;
        //     if(i > 1) r = dp[i-2] + abs(height[i-2] - height[i]) ;
        //     dp[i] = min(l,r);
        // }
        // return dp[n-1];
        
        //space optimization
        int prev1 = 0, prev2 = 0;
        for(int i=1;i<n;i++){
            int l = prev1 + abs(height[i-1] - height[i]);
            int r = INT_MAX;
            if(i > 1) r = prev2 + abs(height[i-2] - height[i]) ;
            int curr = min(l,r);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends