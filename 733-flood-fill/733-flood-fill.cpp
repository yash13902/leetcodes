class Solution {
public:
    
    void dfs(vector<vector<int>>& v, int i, int j, int val, int color){
        if(i<0||i>=v.size()||j<0||j>=v[0].size()||v[i][j]==color||v[i][j]!=val){
            return;
        }
        v[i][j]=color;
        dfs(v,i-1,j,val,color);
        dfs(v,i+1,j,val,color);
        dfs(v,i,j-1,val,color);
        dfs(v,i,j+1,val,color);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};