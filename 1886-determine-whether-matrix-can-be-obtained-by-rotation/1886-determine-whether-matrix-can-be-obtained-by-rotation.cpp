class Solution {
public:
    
    bool same(vector<vector<int>>& mat, vector<vector<int>>& target){
        int i,j;
        for(i=0;i<mat.size();i++){
            for(j=0;j<mat.size();j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(same(mat,target)) return true;
        int k=3,i,j;
        while(k > 0){
            for(i=0;i<mat.size();i++){
                for(j=0;j<i;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(i=0;i<mat.size();i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(same(mat,target)){
                return true;
            }
            k--;
        }
        return false;
    }
};