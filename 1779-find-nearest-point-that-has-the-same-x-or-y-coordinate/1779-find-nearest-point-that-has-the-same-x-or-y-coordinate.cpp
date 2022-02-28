class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) { 
        int minDist = INT_MAX;
        int index = 0;
        int returnIndex = -1;
        int sum = 0;
        for(auto it : points){
            if(it[0] == x || it[1] == y){
                sum = (abs(x - it[0]) + abs(y - it[1]));
                if(minDist > sum){
                    minDist = sum;
                    returnIndex = index;
                }
            }
            index++;
        }
        return returnIndex;
    }
};