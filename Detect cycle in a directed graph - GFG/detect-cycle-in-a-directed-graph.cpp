//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &pathvis, int i){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto c : adj[i]){
            if(!vis[c]){
                if(dfs(adj, vis, pathvis, c)) return true;
            }else if(vis[c] && pathvis[c]) return true;
        }
        pathvis[i] = 0;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        // vector<int> vis(v);
        // vector<int> pathvis(v);
        // for(int i=0;i<v;i++){
        //     if(!vis[i])
        //         if(dfs(adj, vis, pathvis, i)) return true;
        // }
        // return false;
        
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto c : adj[i]) indegree[c]++;
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto c : adj[node]){
                indegree[c]--;
                if(indegree[c] == 0) q.push(c);
            }
        }
        if(topo.size() == v) return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends