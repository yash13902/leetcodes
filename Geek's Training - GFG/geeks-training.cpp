//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int recur(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp){
        if(day == 0){
            int maxi = 0;
            for(int task=0;task<3;task++){
                if(task == last) continue;
                maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0;
        for(int task=0;task<3;task++){
            if(task == last) continue;
            int point = points[day][task] + recur(points, day-1, task, dp);
            maxi = max(maxi, point);
        }
        return dp[day][last] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(5,-1));
        return recur(points, n-1, 3, dp);
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