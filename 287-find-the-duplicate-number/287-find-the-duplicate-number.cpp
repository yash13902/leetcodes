class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()-1,0);
        for(auto c:nums){
            v[c-1]++;
        }
        for(auto c:v) cout << c << endl;;
        for(int i=0;i<v.size();i++){
            if(v[i] > 1) return i+1;
        }
        return -1;
    }
};