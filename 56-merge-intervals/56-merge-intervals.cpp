class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if(b[0] == a[0]) return b[1] > a[1];
            return b[0] > a[0];
        });
        int i=1;
        vector<int> v;
        v.push_back(intervals[0][0]);
        v.push_back(intervals[0][1]);
        while(i<intervals.size()){
            if(intervals[i][0] <= v[1]) {
                if(intervals[i][1] >= v[1])
                    v[1] = intervals[i][1];
            }
            // else if(intervals[i][1] >= v[1]);
            else{
                ans.push_back(v);
                v[0] = intervals[i][0];
                v[1] = intervals[i][1];
            }
            i++;
        }
        ans.push_back(v);
        return ans;
    }
};