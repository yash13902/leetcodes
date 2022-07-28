class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // vector<int> v(nums.size()-1,0);
        // for(auto c:nums){
        //     v[c-1]++;
        // }
        // for(auto c:v) cout << c << endl;;
        // for(int i=0;i<v.size();i++){
        //     if(v[i] > 1) return i+1;
        // }
        // return -1;
        int i=nums[0],j=nums[0];
        do{
            i = nums[i];
            j = nums[nums[j]];
        }while((i!=j));
        
        j = nums[0];
        while(i!=j){
            i = nums[i];
            j = nums[j];
        }
        
        return i;
        // return nums[i];
    }
};