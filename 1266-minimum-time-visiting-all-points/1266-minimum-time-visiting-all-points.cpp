class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<vector<int>>::iterator p = points.begin();
        vector<vector<int>>::iterator it = points.begin();
        int time = 0;
        while(it < points.end()){
            while(((*p).at(0) != (*it).at(0)) && ((*p).at(1) != (*it).at(1))){
                if((*it).at(0) > (*p).at(0)){
                    ((*p).at(0))++;
                } else{
                    ((*p).at(0))--;
                }
                if((*it).at(1) > (*p).at(1)){
                    ((*p).at(1))++;
                } else{
                    ((*p).at(1))--;
                }
                time++;
            }
            if((*p).at(0) == (*it).at(0)){
                time += abs(((*p).at(1) - (*it).at(1)));
            } else{
                time += abs(((*p).at(0) - (*it).at(0)));
            }
            p = it;
            it++;
        }
        return time;
    }
};