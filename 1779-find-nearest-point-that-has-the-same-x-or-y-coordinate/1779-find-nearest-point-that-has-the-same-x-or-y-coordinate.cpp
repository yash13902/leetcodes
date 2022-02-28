class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) { 
        unordered_map<int, int> valid;
        int sum = 0;
        for(auto it : points){
            if(it[0] == x || it[1] == y){
                valid.insert({
                    (abs(x - it[0]) + abs(y - it[1])), sum
                });
            }
            sum++;
        }
        if(valid.size() == 0){
            return -1;
        }
        auto min = valid.begin();
        for(auto it = valid.begin(); it != valid.end(); it++){
            if(it->first < min->first){
                min = it;
            }    
        }
        return min->second;
    }
};