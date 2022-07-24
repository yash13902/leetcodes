class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=matrix[0].size()-1, i=0;
        while(j >= 0 && i < matrix.size()){
            if(matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else if(matrix[i][j] == target) return true;
        }
        return false;
    }
};