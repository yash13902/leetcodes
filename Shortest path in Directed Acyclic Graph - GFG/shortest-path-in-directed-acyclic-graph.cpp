//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> vis(N, INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0] = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto c : adj[top.first]){
                if(vis[c.first] > top.second+c.second){
                    vis[c.first] = top.second+c.second;
                    q.push({c.first, top.second+c.second});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(vis[i] == INT_MAX) vis[i] = -1;
        }
        return vis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends