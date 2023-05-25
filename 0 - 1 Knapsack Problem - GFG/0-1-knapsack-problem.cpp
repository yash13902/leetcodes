//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int recur(int target, int index, int wt[], int val[], vector<vector<int>> &dp){
        if(index == 0){
            if(wt[0] <= target) return val[0];
            return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int pick=-1e8, notpick=-1e8;
        if(wt[index] <= target) pick=val[index]+recur(target-wt[index],index-1,wt,val,dp);
        notpick = recur(target,index-1,wt,val,dp);
        return dp[index][target] = max(pick, notpick);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n, vector<int>(W+1, -1));
    //   return recur(W, n-1, wt, val, dp);
    
        // vector<vector<int>> dp(n, vector<int>(W+1, 0));
        // for(int t=1;t<=W;t++){
        //     if(wt[0] <= t) dp[0][t] = val[0];
        //     else dp[0][t] = 0;
        // }
        // for(int i=1;i<n;i++){
        //     for(int t=0;t<=W;t++){
        //         int pick = -1e8, notpick= -1e8;
        //         if(wt[i] <= t) pick=val[i]+dp[i-1][t-wt[i]];
        //         notpick = dp[i-1][t];
        //         dp[i][t] = max(pick, notpick);
        //     }
        // }
        // return dp[n-1][W];
        
        vector<int> dp(W+1, 0);
        for(int t=1;t<=W;t++){
            if(wt[0] <= t) dp[t] = val[0];
            else dp[t] = 0;
        }
        for(int i=1;i<n;i++){
            vector<int> temp(W+1, 0);
            for(int t=0;t<=W;t++){
                int pick = -1e8, notpick = -1e8;
                if(wt[i] <= t) pick = val[i]+dp[t-wt[i]];
                notpick = dp[t];
                temp[t] = max(pick, notpick);
            }
            dp = temp;
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends