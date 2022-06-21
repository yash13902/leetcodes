class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> s;
        for(auto i : nums){
            s.insert(i*i);
        }
        vector<int> n(s.begin(), s.end());
        return n;
    }
};