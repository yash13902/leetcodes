class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==1)return true;
        int i=0;
        while(i<nums.size()-1 && nums[i] <= nums[i+1]){
            i++;
        }
        if(i==nums.size()-1) return true;
        else if(i==0) nums[i] = nums[i+1];
        else if(i==nums.size()-2) nums[i+1] = nums[i];
        else if(nums[i-1] <= nums[i+1]) nums[i] = nums[i-1];
        else nums[i+1] = nums[i];
        i=0;
        while(i<nums.size()-1 && nums[i] <= nums[i+1]){
            i++;
        }
        if(i==nums.size()-1) {
            return true;
        }
        return false;
    }
};