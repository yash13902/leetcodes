//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        
        queue<pair<int,int>> q;
        int vis[v] = {0};
        for(int i=0;i<v;i++){
            if(vis[i] == 0){
                q.push({i,-1});
                vis[i] = 1;
                while(!q.empty()){
                    pair<int,int> node = q.front();
                    q.pop();
                    for(auto it : adj[node.first]){
                        if(it == node.second) continue;
                        if(vis[it] == 1) return true;
                        vis[it] = 1;
                        q.push({it,node.first});
                    }
                }   
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends