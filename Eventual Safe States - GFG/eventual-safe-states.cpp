//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    #define vi vector<int>
    
    bool dfs(int i, vi &vis, vi &pathvis, vi &check, vi adj[]){
        vis[i] = 1;
        pathvis[i] = 1;
        check[i] = 0;
        for(auto c : adj[i]){
            if(!vis[c]){
                if(dfs(c, vis, pathvis, check, adj)){
                    check[i] = 0;
                    return true;
                }
            }else if(pathvis[c]){
                check[i] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vi vis(v,0), pathvis(v,0), ans, check(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]) dfs(i, vis, pathvis, check, adj);
        }
        for(int i=0;i<v;i++){
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends