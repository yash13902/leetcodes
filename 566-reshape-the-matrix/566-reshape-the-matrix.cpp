class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c) return mat;
        vector<vector<int>> v(r, vector<int>(c,0));
        int i,j,k=0,l=0;
        for(i=0;i<mat.size();i++){
            for(j=0;j<mat[i].size();j++){
                v[k][l++] = mat[i][j];
                if(l == c) l=0, k++;
            }
        }
        return v;
    }
};