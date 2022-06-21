class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size());
        int l=0,r=nums.size()-1,k;
        for(k=nums.size()-1;k>=0;k--){
            if(abs(nums[l]) > abs(nums[r])) {
                v[k] = nums[l]*nums[l];
                l++;
            } else{
                v[k] = nums[r]*nums[r];
                r--;
            }
        }
        return v;
    }
};