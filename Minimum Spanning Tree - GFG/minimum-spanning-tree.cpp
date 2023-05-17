//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent,rank,size;
    public : 
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //Prim's Algorithm
        // vector<pair<int,int>> mst;
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // vector<int> vis(V, 0);
        // int sum=0;
        // pq.push({0,0,-1});
        // // ElogE
        // //E
        // while(!pq.empty()){
        //     // log E
        //     auto top = pq.top();
        //     pq.pop();
        //     int wt = top[0];
        //     int node = top[1];
        //     int parent = top[2];
        //     if(vis[node] == 0){
        //         sum += wt;
        //         if(parent!=-1)
        //             mst.push_back({parent, node});
        //         vis[node] = 1;
        //         //E
        //         for(auto c : adj[node]){
        //             if(vis[c[0]] == 0){
        //                 // log E
        //                 pq.push({c[1], c[0], node});
        //             }
        //         }
        //     }
        // }
        // // for(auto c : mst){
        // //     cout << c.first << " " << c.second << endl;
        // // }
        // return sum;
        
        //Kruskal's Algorithm
        
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto c : adj[i]){
                edges.push_back({c[1], {i, c[0]}});
            }
        }
        sort(edges.begin(), edges.end());
        int sum = 0;
        DisjointSet ds(V);
        for(auto c : edges){
            int wt = c.first;
            int u = c.second.first;
            int v = c.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends