class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) { 
        int minDist = INT_MAX;
        int index = 0;
        int returnIndex = -1;
        for(auto it : points){
            if(it[0] == x || it[1] == y){
                if(minDist > (abs(x - it[0]) + abs(y - it[1]))){
                    minDist = (abs(x - it[0]) + abs(y - it[1]));
                    returnIndex = index;
                }
            }
            index++;
        }
        return returnIndex;
    }
};