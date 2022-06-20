class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, mid, high=nums.size()-1;
        while(low<=high){
            mid = high/2 + low/2 + (high%2 + low%2)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};