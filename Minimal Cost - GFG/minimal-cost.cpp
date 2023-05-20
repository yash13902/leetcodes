//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int recur(vector<int> &dp, vector<int> &height, int n, int k){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        vector<int> dis;
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i >= 0)
                ans = min(ans, recur(dp, height, n-i, k) + abs(height[n] - height[n-i]));
        }
        return dp[n] = ans;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        //memoization
        // vector<int> dp(n+1, -1);
        // return recur(dp, height, n-1, k);
        
        //tabulation
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int ans = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i>=j){
                    ans = min(ans, dp[i-j] + abs(height[i] - height[i-j]));
                }
            }
            dp[i] = ans;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends