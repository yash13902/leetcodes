class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> sets(nums1.begin(), nums1.end());
        vector<int> v;
        for(auto it : nums2){
            if(sets.count(it)){
                v.push_back(it);
                sets.erase(it);
            }
        }    
        return v;
    }
};