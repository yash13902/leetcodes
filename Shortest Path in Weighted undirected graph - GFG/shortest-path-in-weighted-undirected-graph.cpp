//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj[n+1];
        for(auto c : edges){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }
        vector<int> parent(n+1), dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        parent[1] = 1;
        dist[1] = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for(auto c : adj[top.second]){
                if(dist[c[0]] > top.first+c[1]){
                    dist[c[0]] = top.first+c[1];
                    parent[c[0]] = top.second;
                    pq.push({top.first+c[1], c[0]});
                }
            }
        }
        vector<int> ans;
        int node = n;
        if(parent[node] == 0) return {-1};
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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