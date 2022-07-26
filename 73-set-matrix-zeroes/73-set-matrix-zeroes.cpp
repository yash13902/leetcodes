class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r(matrix.size(),-1);
        vector<int> c(matrix[0].size(),-1);
        int i,j;
        for(i=0;i<matrix.size();i++){
            for(j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    r[i] = 0;
                    c[j] = 0;
                }
            }
        }
        for(i=0;i<r.size();i++){
            if(r[i] == 0){
                for(j=0;j<matrix[0].size();j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(i=0;i<c.size();i++){
            if(c[i] == 0){
                for(j=0;j<matrix.size();j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};