//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int recur(int *arr, int index, int n, vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int take = recur(arr, index+2, n, dp) + arr[index];
        int nottake = recur(arr, index+1, n, dp);
        return dp[index] = max(take, nottake);
    }

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	   // vector<int> dp(n+1, -1);
	   // int ans = recur(arr, 0, n, dp);
	   // return ans;
	   
	   vector<int> dp(n, 0);
	   for(int i=n-1;i>=0;i--){
	       int pick = arr[i];
	       if(i+2 < n) pick += dp[i+2];
	       int notpick = 0;
	       if(i+1 < n) notpick += dp[i+1];
	       dp[i] = max(pick, notpick);
	   }
	   return dp[0];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends