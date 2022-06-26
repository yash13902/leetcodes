class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) ans=max(ans,mArea(grid,i,j));
            }
        }
        return ans;
    }
    
    int mArea(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;
        return 1+mArea(grid,i-1,j)+mArea(grid,i+1,j)+mArea(grid,i,j-1)+mArea(grid,i,j+1);
    }
};