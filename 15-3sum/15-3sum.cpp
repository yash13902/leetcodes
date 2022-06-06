class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > result;
        if(nums.size() < 3)
            return result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            int low = i+1, high = n-1;
            while(low < high){
                vector<int> v(3,0);
                if(nums[high] + nums[low] + nums[i] == 0){
                    v[0] = nums[i];
                    v[1] = nums[low];
                    v[2] = nums[high];
                    result.push_back(v);
                    
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    
                    low++;
                    high--;
                } 
                else if(nums[low] + nums[high] > -nums[i])
                    high--;
                else if(nums[low] + nums[high] < -nums[i])
                    low++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};