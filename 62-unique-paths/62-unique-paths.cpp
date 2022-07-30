class Solution {
public:
    
    int ways(int i,int j,int m,int n,vector<vector<int>> &dp){
        int count=0;
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = ways(i+1,j,m,n,dp) + ways(i,j+1,m,n,dp);
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return ways(0,0,m,n,dp);
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        
        for(int i=1;i<=r;i++){
            res = res * (N-r+i)/i;
        }
        return (int)res;
    }
};