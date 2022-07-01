class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int> & b)
    {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), compare);
        int sum=0,box=0;
        for(int i=0;i<b.size();i++){
            while(b[i][0] > 0){
                sum += b[i][1];
                b[i][0]--;
                box++;    
                if(box+1 > t) return sum;
            }
        }
        return sum;
    }
};