class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
{
        
        int i=0,j=matrix[0].size()-1;
        while(j >= 0 && i < matrix.size()){
            if(matrix[i][j] == target){
                return true;
            }else if(j==0 && i==matrix.size()-1){
                return false;
            }else if(target > matrix[i][j]){
                i++;
            }else if(target < matrix[i][j]){
                j--;
            }
        }
        return false;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//     if (matrix.size() == 0 || matrix[0].size() == 0)
//     {
//         return false;
//     }

//     int low;
//     int high;

//     // first search in first column, use binary search
//     for (low = 0, high = matrix.size() - 1; low <= high;)
//     {
//         int middle = (low + high) / 2;
//         if (matrix[middle][0] < target)
//         {
//             low = middle + 1;
//         }
//         else if (matrix[middle][0] > target)
//         {
//             high = middle - 1;
//         }
//         else
//         {
//             return true;
//         }
//     }

//     // when above loop ends, search in row[high]
//     int row = high;
//     if (row >= 0)
//     {
//         for (low = 0, high = matrix[row].size() - 1; low <= high;)
//         {
//             int middle = (low + high) / 2;
//             if (matrix[row][middle] < target)
//             {
//                 low = middle + 1;
//             }
//             else if (matrix[row][middle] > target)
//             {
//                 high = middle - 1;
//             }
//             else
//             {
//                 return true;
//             }
//         }
//     }

//     return false;
        
}
};