//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recur(int arr[], int i, int j, vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        int steps = 0;
        for(int k=i;k<j;k++){
            steps = (arr[i-1]*arr[k]*arr[j])+recur(arr, i, k, dp)+recur(arr, k+1, j, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return recur(arr, 1, n-1, dp);
        
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            dp[i][i] = 0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int mini = 1e9;
                int steps = 0;
                for(int k=i;k<j;k++){
                    steps = (arr[i-1]*arr[k]*arr[j])+dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends