class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int flag, mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) return 0;
            if(nums[i] < 0){
                if(abs(mini) > abs(nums[i])) mini = nums[i];
            }else if(nums[i] > 0){
                if(abs(mini) >= nums[i]) mini = nums[i];
            }
        }
        return mini;
    }
};