//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int m=1003;
    int solve(string s, int i, int j, bool t,  vector<vector<vector<int>>>&dp)
    {
        
        if(i>j) return 0;
        
        if(i==j)
        {
            if(t==true)  return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        
        int ways=0;
        for(int k=i+1 ; k<j; k+=2)
        {
            int TL;
            // if(dp[i][k-1][true]!=-1)  TL = dp[i][k-1][true]%m;
            // else 
            TL = solve(s, i, k-1, true, dp)%m;
            
            int FL;
            // if(dp[i][k-1][false]!=-1)  FL = dp[i][k-1][false]%m;
            // else  
            FL = solve(s, i, k-1, false, dp)%m;
            
            
            int TR;
            // if(dp[k+1][j][true]!=-1)  TR = dp[k+1][j][true]%m;
            // else  
            TR = solve(s, k+1, j, true, dp)%m;
            
             
            int FR;
            // if(dp[k+1][j][false]!=-1)  FR = dp[k+1][j][false]%m;
            // else  
            FR = solve(s, k+1, j, false, dp)%m;
            
            if(s[k]=='&')
            {
                if(t)
                {
                    ways+=(TL*TR)%m;
                }
                else
                {
                    ways+=(TL*FR)%m + (FL*TR)%m + (FL*FR)%m;
                }
            }
            if(s[k]=='|')
            {
                if(t)
                {
                    ways+=(TL*TR)%m + (TL*FR)%m + (FL*TR)%m ;
                }
                else
                {
                    ways+=(FL*FR)%m;
                }
            }
            if(s[k]=='^')
            {
                if(t)
                {
                    ways+=(TL*FR)%m+ (FL*TR)%m ;
                }
                else
                {
                    ways+=(FL*FR)%m + (TL*TR)%m;
                }
            }
            
        }
        
        return dp[i][j][t]=ways%m;
        
    }
    int countWays(int N, string s){
        
        vector<vector<vector<int>>>dp(N, vector<vector<int>>(N, vector<int>(2,-1)));
        //int arr[N+1][N+1][2]={-1};
        return solve(s, 0, s.size()-1, true, dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends