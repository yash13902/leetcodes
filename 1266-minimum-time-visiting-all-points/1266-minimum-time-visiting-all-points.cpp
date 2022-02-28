class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0, x, y, i;
        for(i = 0; i < points.size()-1; i++){
            x = abs(points[i+1][0] - points[i][0]);
            y = abs(points[i+1][1] - points[i][1]);
            
            time += max(x,y);
        }
        return time;
    }
};