class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        int i,j,low,high;
        long new_target;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                vector<int> v(4,0);
                low = j+1; 
                high = n;
                while(low < high){
                    new_target = target - nums[i];
                    new_target -= nums[j];
                    new_target -= nums[low];
                    new_target -= nums[high];
                    if(new_target == 0){
                        v[0] = nums[i];
                        v[1] = nums[low];
                        v[2] = nums[high];
                        v[3] = nums[j];
                        result.push_back(v);
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    }else if (0 > new_target) {
                        high--;
                    } else if(0 < new_target){
                        low++;
                    }
                }
                while(i < n-1 && nums[i] == nums[i+1]) i++;
                while(j < n && nums[j] == nums[j+1]) j++;
            }
        }
        return result;
    }
};