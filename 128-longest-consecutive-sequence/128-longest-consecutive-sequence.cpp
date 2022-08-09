class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        sort(nums.begin(), nums.end());
        int i,si=0,ei=0,max_len=1,dupli=0;
        while(ei < nums.size()-1){
            if(nums[ei] == nums[ei+1]-1){
                ei++;
                max_len = max(max_len, ei-si+1-dupli);
            }else if(nums[ei] == nums[ei+1]){
                ei++;
                dupli++;
            }else{
                ei++;
                si = ei;
                dupli=0;
            }
        }
        return max_len;
    }
};