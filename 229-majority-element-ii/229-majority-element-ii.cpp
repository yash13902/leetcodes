class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0,candidate1,candidate2,i;
        vector<int> ans;
        for(i=0;i<nums.size();i++){
            if(candidate1 == nums[i]){
                count1++;
            }else if(candidate2 == nums[i]){
                count2++;
            }else if(count1==0){
                candidate1 = nums[i];
                count1 = 1;
            }else if(count2==0){
                candidate2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        count1=0;count2=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==candidate1) count1++;
            else if(nums[i]==candidate2) count2++;
        }
        if(count1 > (nums.size())/3) ans.push_back(candidate1);
        if(count2 > (nums.size())/3) ans.push_back(candidate2);
        cout << candidate1 << " " << candidate2 << " " << endl;
        return ans;
    }
};