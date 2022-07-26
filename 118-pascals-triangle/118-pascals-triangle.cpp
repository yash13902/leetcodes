class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        int i,j;
        for(i=0;i<numRows;i++){
            vector<int> vv(i+1,1);
            for(j=1;j<i;j++){
                vv[j] = v[i-1][j-1] + v[i-1][j];
            }
            v.push_back(vv);
        }
        return v;
    }
};