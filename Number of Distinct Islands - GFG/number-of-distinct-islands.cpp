//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      #define vv vector<vector<int>>
      int row_t[4] = {-1,0,1,0};
      int col_t[4] = {0,1,0,-1};
  
    void dfs(vv &grid, vv &vis, int row, int col, int orow, int ocol, vector<pair<int,int>> &temp){
        temp.push_back({row-orow, col-ocol});
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+row_t[i];
            int ncol = col+col_t[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() 
                && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                dfs(grid, vis, nrow, ncol, orow, ocol, temp);
            }
        }
        return;
    }
  
    int countDistinctIslands(vv& grid) {
        // code here
        int r = grid.size(), c = grid[0].size(), i, j;
        vv vis(r, vector<int>(c,0));
        set<vector<pair<int,int>>> ans;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                vector<pair<int,int>> temp;
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    dfs(grid, vis, i, j, i, j, temp);
                    ans.insert(temp);
                }
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends