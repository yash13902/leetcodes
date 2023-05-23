//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int recur(int n, int m, vector<vector<int>> &a, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        if(i<0||j1>=m||j2>=m||j1<0||j2<0) return -1e8;
        if(i==n-1){
            if(j1==j2) return a[i][j1];
            return a[i][j1] + a[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2) maxi = max(maxi, a[i][j1]+recur(n,m,a,i+1,j1+dj1,j2+dj2,dp));
                else maxi = max(maxi, a[i][j1]+a[i][j2]+recur(n,m,a,i+1,j1+dj1,j2+dj2,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return recur(n, m, grid, 0, 0, m-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends