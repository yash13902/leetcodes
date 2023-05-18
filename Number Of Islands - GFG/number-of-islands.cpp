//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{

vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulp = findUPar(u);
        int vlp = findUPar(v);
        if(ulp == vlp) return;
        if(size[ulp] > size[vlp]){
            parent[vlp] = ulp;
            size[ulp] += size[vlp];
        }else{
            parent[ulp] = vlp;
            size[vlp] += size[ulp];
        }
        return;
    }

};

class Solution {
  public:
  
    bool checkNode(int x, int y, int n, int m){
        if(x>=0&&y>=0&&x<n&&y<m) return true;
        return false;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        vector<vector<int>> vis(n, vector<int>(m,0));
        DisjointSet ds(n*m);
        int cnt=0;
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        for(auto c : operators){
            int row = c[0];
            int col = c[1];
            if(vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            for(int ind=0;ind<4;ind++){
                int adjrow = row+drow[ind];
                int adjcol = col+dcol[ind];
                if(checkNode(adjrow, adjcol, n, m)){
                    if(vis[adjrow][adjcol] == 1){
                        int nodeno = row*m+col;
                        int adjnodeno = adjrow*m+adjcol;
                        if(ds.findUPar(nodeno) != ds.findUPar(adjnodeno)){
                            cnt--;
                            ds.unionBySize(nodeno, adjnodeno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends