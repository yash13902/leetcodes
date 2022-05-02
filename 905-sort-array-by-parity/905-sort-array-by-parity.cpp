class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto i = nums.begin();
        auto j = nums.begin()+1;
        int temp; 
        while(j != nums.end()){
            if(i == nums.end()){
                break;
            }
            if(*i % 2 == 0){
                i++;
                continue;
            }   
            j = i+1;
            while(j != nums.end()){
                if(*j % 2 == 0){
                    temp = *i;
                    *i = *j;
                    *j = temp;
                    i++;
                    j++;
                    break;
                }else{
                    j++;
                }
            }
        }
        return nums;
    }
};