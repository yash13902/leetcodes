//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recur(int index, int w, int val[], int wt[], vector<vector<int>> &dp){
        if(index == 0){
            return val[0]*(w/wt[0]);
            // return 0;
        }
        if(dp[index][w] != -1) return dp[index][w];
        int pick = INT_MIN, notpick = INT_MIN;
        if(w >= wt[index]) pick = val[index] + recur(index, w-wt[index], val, wt, dp);
        notpick = recur(index-1, w, val, wt, dp);
        return dp[index][w] = max(pick, notpick);
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(w+1, -1));
        return recur(n-1, w, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends