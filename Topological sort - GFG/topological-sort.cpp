//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	#define vi vector<int> 
	#define si stack<int>
	//Function to return list containing vertices in Topological order. 
	
// 	void dfs(int i, vi &vis, si &s, vi adj[]){
// 	    vis[i] = 1;
// 	    for(auto c : adj[i]){
// 	        if(!vis[c]) dfs(c, vis, s, adj);
// 	    }
// 	    s.push(i);
// 	    return;
// 	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{   
	    // code here
	   // vi vis(v,0), ans;
	   // si s;
	   // for(int i=0;i<v;i++){
	   //     if(!vis[i]) dfs(i, vis, s, adj);
	   // }
	   // while(!s.empty()){
	   //     ans.push_back(s.top());
	   //     s.pop();
	   // }
	   // return ans;
	   
	   int indegree[v] = {0};
	   for(int i=0;i<v;i++){
	       for(auto c : adj[i]){
	           indegree[c]++;
	       }
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
	   return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends