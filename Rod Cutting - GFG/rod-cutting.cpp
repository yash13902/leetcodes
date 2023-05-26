//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  
  
    int recur(int price[], int index, int n, vector<vector<int>> &dp){
        if(index == 0){
            return n*price[0];
        }
        if(dp[index][n] != -1) return dp[index][n];
        int nottake = 0 + recur(price, index-1, n, dp);
        int take = INT_MIN;
        int rodLength = index+1;
        if(rodLength <= n) take = price[index] + recur(price, index, n-rodLength, dp);
        return dp[index][n] = max(take, nottake);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return recur(price, n-1, n, dp);
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends