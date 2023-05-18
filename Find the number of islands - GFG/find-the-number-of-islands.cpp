//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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

bool checkNode(int x, int y, int n, int m, vector<vector<char>> &grid){
    if(x>=0&&y>=0&&x<n&&y<m&&grid[x][y]=='1') return true;
    return false;
}

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int i,j,cnt=0;
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == '0') continue;
                if(vis[i][j] == 1) continue;
                vis[i][j] = 1;
                cnt++;
                for(int ni=-1;ni<=1;ni++){
                    for(int nj=-1;nj<=1;nj++){
                        if(ni == 0 && nj == 0) continue;
                        int adjrow = i+ni;
                        int adjcol = j+nj;
                        if(checkNode(adjrow, adjcol, n, m, grid)){
                            if(vis[adjrow][adjcol] == 1){
                                int nodeno = i*m+j;
                                int adjnodeno = adjrow*m+adjcol;
                                if(ds.findUPar(nodeno) != ds.findUPar(adjnodeno)){
                                    cnt--;
                                    ds.unionBySize(nodeno, adjnodeno);
                                }
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends