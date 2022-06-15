class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;
        
        int n=nums.size()-1;
        unordered_map<int,int> m;
        for(int i=0;i<=n;i++){
            
            if(m.find(nums[i]) != m.end() && abs(m[nums[i]] - i) <= k ){
                return true;
            }else{
                m[nums[i]] = i;
            }
            
        }
        return false;
    }
};