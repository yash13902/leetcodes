class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto it=nums.begin(); it!=nums.end(); it++){
            if(m[*it] == 0){
                m[*it]++;
            } else{
                return true;
            }
        }
        return false;
    }
};