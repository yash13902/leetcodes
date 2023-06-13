//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int mod = 1e9+7;
    
    long long int recur(string &str, long long int i, long long int j, vector<vector<long long int>> &dp){
        if((j-i+1) == 1) return 1%mod;
        if((j-i+1) == 2){
            if(str[i] == str[j]) return 3%mod;
            else return 2%mod;
        }
        if(dp[i][j] != -1) return dp[i][j]%mod;
        if(str[i] == str[j]){
            return dp[i][j] = (1 + 
                recur(str, i, j-1, dp)%mod + 
                recur(str, i+1, j, dp)%mod)%mod;
        }
        return dp[i][j] = (0 + 
            recur(str, i, j-1, dp)%mod + 
            recur(str, i+1, j, dp)%mod - 
            recur(str, i+1, j-1, dp)%mod + mod)%mod;
    }
    
    long long int  countPS(string str)
    {
       //Your code here
    //   vector<vector<long long int>> dp(str.size()+1, vector<long long int>(str.size()+1, -1));
    //   return recur(str, 0, str.size()-1, dp)%mod;
        int n = str.size();
        vector<vector<long long int>> dp(str.size()+1, vector<long long int>(str.size()+1, 0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         // if(j<i) continue;
        //         if((j-i+1) == 1) dp[i][j] = 1;
        //         else if((j-i+1) == 2){
        //             if(str[i] == str[j]) dp[i][j] = 3;
        //             else dp[i][j] = 2;
        //         }
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j<i) continue;
                if((j-i+1) == 1) dp[i][j] = 1;
                else if((j-i+1) == 2){
                    if(str[i] == str[j]) dp[i][j] = 3;
                    else dp[i][j] = 2;
                }else {
                    if(str[i] == str[j]){
                        dp[i][j] = (1 + 
                            dp[i][j-1]%mod + 
                            dp[i+1][j]%mod)%mod;
                    }else{
                        dp[i][j] = (0 + 
                            dp[i][j-1]%mod + 
                            dp[i+1][j]%mod - 
                            dp[i+1][j-1]%mod + mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1]%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends