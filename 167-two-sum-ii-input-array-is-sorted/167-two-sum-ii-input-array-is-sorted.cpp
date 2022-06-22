class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> index;
        int i,low,high;
        for(i=0;i<numbers.size();i++){
            low = i;
            high = numbers.size()-1;
            while(low < high){
                if(numbers[low] + numbers[high] == target){
                    index.push_back(low+1);
                    index.push_back(high+1);
                    return index;
                }else if(numbers[low] + numbers[high] > target){
                    high--;
                }else{
                    low++;
                }
            }
        }
        return index;
    }
};