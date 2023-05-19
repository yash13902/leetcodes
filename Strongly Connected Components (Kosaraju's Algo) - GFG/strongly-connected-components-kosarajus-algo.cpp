//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(vector<vector<int>> &adj, vector<int> &vis, stack<int> &s, int node){
	    vis[node] = 1;
	    for(auto c : adj[node]){
	        if(!vis[c]) dfs(adj, vis, s, c);
	    }
	    s.push(node);
	}
	
	void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
	    vis[node] = 1;
	    for(auto c : adj[node]){
	        if(!vis[c]) dfs(adj, vis, c);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(adj, vis, s, i);
        }
        vector<vector<int>> rev(V);
        for(int i=0;i<V;i++){
            for(auto c : adj[i]){
                rev[c].push_back(i);
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            vis[i] = 0;
        }
        while(!s.empty()){
            int top = s.top();
            if(!vis[top]){
                cnt++;
                dfs(rev, vis, top);
            }
            s.pop();
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends