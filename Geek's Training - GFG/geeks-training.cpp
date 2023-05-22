//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int recur(vector<vector<int>> &points, int n, int index, int old, vector<vector<int>> &dp){
        if(index >= n) return 0;
        if(dp[index][old] != -1) return dp[index][old];
        int r = 0, f = 0, l = 0;
        if(old == 0){
            f = points[index][1] + recur(points, n, index+1, 1, dp);
            l = points[index][2] + recur(points, n, index+1, 2, dp);
        }else if(old == 1){
            r = points[index][0] + recur(points, n, index+1, 0, dp);
            l = points[index][2] + recur(points, n, index+1, 2, dp);
        }else{
            r = points[index][0] + recur(points, n, index+1, 0, dp);
            f = points[index][1] + recur(points, n, index+1, 1, dp);
        }
        int a = max(r,f);
        return dp[index][old] = max(a, l);
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4,-1));
        int a1 = recur(points, n, 0, 0, dp);
        int a2 = recur(points, n, 0, 1, dp);
        int a3 = recur(points, n, 0, 2, dp);
        int a = max(a1,a2);
        return max(a, a3);
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