class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int x=0,y=0,z=0,i;
        // for(i=0;i<nums.size();i++){
        //     if(nums[i] == 0) x++;
        //     else if(nums[i] == 1) y++;
        //     else z++;
        // }
        // // i=0;
        // nums.clear();
        // while(x--){
        //     nums.push_back(0);
        // }
        // while(y--){
        //     nums.push_back(1);
        // }
        // while(z--){
        //     nums.push_back(2);
        // }
        
        if(nums.size() == 1) return;
        int l=0,h=nums.size()-1,m=0,temp;
        while(m<=h){
            if(nums[m] == 0){
                // swap(l,m);
                temp = nums[l];
                nums[l] = nums[m];
                nums[m] = temp;
                l++;
                m++;
            } else if(nums[m] == 2){
                // swap(h,m);
                temp = nums[h];
                nums[h] = nums[m];
                nums[m] = temp;
                h--;
            }else m++;
        }
        
    }
};