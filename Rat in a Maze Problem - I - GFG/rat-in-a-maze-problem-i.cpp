//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution{
    
    void paths(int row, int col, int n, string temp, vector<vector<int> > &maze, vector<string> &ans, vector<vector<int> > &vis){
    if(row == n-1 && col == n-1){
        ans.push_back(temp);
        return;
    }
    
    //downward
    if(row+1<n && !vis[row+1][col] && (maze[row+1][col] == 1)){
        vis[row][col] = 1;
        paths(row+1, col, n, temp+'D', maze, ans, vis);
        vis[row][col] = 0;
    }
    
    //leftward
    if(col-1>=0 && !vis[row][col-1] && (maze[row][col-1] == 1)){
        vis[row][col] = 1;
        paths(row, col-1, n, temp+'L', maze, ans, vis);
        vis[row][col] = 0;
    }
    
    //rightward
    if(col+1<n && !vis[row][col+1] && (maze[row][col+1] == 1)){
        vis[row][col] = 1;
        paths(row, col+1, n, temp+'R', maze, ans, vis);
        vis[row][col] = 0;
    }
    
    //upward
    if(row-1>=0 && !vis[row-1][col] && (maze[row-1][col] == 1)){
        vis[row][col] = 1;
        paths(row-1, col, n, temp+'U', maze, ans, vis);
        vis[row][col] = 0;
    }
    
    return;
    
}
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        // Your code goes here
        vector<string> ans;
        if(m[0][0] != 1 || m[n-1][n-1] != 1) return ans;
        vector<vector<int> > vis(n, vector<int>(n,0));
        string temp ="";
        paths(0,0,n,temp, m, ans, vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends