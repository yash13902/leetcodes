class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), err=INT_MAX, sum, min,diff;
        for(int i=0;i<n;i++){
            int low=i+1, high=n-1;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                diff = abs(sum-target);
                if(diff < err){
                    err = diff;
                    min = sum;
                }
                if(diff == 0) return sum;
                if(sum > target) high--;
                else low++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return min;
    }
};