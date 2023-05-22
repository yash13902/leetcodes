//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int recur(vector<vector<int>> &points, int index, int old, vector<vector<int>> &dp){
        if(index  == 0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i == old) continue;
                maxi = max(maxi, points[0][i]);
            }
            return maxi;
        };
        if(dp[index][old] != -1) return dp[index][old];
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i == old) continue;
            int point = points[index][i] + recur(points, index-1, i, dp);
            maxi = max(maxi, point);
        }
        return dp[index][old] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(5,-1));
        int a1 = recur(points, n-1, 3, dp);
        return a1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends