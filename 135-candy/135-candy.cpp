class Solution {
public:
    int candy(vector<int>& r) {
        if(r.size() == 1) return 1;
        vector<int> v(r.size(),1);
        int i;
        for(i=1;i<r.size();i++) if(r[i] > r[i-1]) v[i] = v[i-1]+1;
        for(i=r.size()-2;i>=0;i--) if(r[i] > r[i+1]) v[i] = max(v[i],v[i+1]+1);
        for(auto c : v) cout << c << endl;
        return accumulate(v.begin(), v.end(), 0);
    }
};