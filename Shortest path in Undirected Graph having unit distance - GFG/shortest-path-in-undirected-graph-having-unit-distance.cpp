//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        vector<int> vis(N, INT_MAX);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src] = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto c : adj[top.first]){
                if(vis[c] > top.second+1){
                    vis[c] = top.second+1;
                    q.push({c,top.second+1});
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends