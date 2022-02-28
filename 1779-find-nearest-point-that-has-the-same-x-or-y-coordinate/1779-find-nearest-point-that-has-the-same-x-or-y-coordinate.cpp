class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) { 
        int minDist = INT_MAX;
        int index = 0;
        int returnIndex = 0;
        bool flag = false;
        for(auto it : points){
            if(it[0] == x || it[1] == y){
                flag = true;
                if(minDist > (abs(x - it[0]) + abs(y - it[1]))){
                    minDist = (abs(x - it[0]) + abs(y - it[1]));
                    returnIndex = index;
                }
            }
            index++;
        }
        if(flag){
            return returnIndex;
        }else{
            return -1;
        }
    }
};