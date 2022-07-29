class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=0,candidate=0;
        
        for(auto c : nums){
            if(count == 0){
                candidate = c;
            }
            if(c == candidate) count++;
            else count--;
        }
        
        return candidate;
        
        // sort(nums.begin(),nums.end());
        // int count=1,m=0,ans;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i] == nums[i-1]){
        //         count++;
        //     }else{
        //         if(m<count){
        //             ans = nums[i-1];
        //             m = count;
        //         }
        //         count=1;
        //     }
        // }
        // if(m<count){
        //     ans = nums[nums.size()-1];
        //     m = count;
        // }
        // return ans;
        
        // map<int, int> m;
        // for(auto c : nums){
        //     m[c]++;
        // }
        // map<int,int>::iterator x = max_element(m.begin(), m.end(), [](pair<int,int> a, pair<int,int> b){
        //     return b.second > a.second;
        // });
        // cout << x->second << endl;
        // return x->first;
    }
};