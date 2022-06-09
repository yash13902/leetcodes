class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> index;
        int i=0, low, n=numbers.size(), high;
        for(i=0;i<n;i++){
            high = i;
            low = n-1;
            while(high<low){
                cout << numbers[high] << " " << numbers[low] << endl;
                if(numbers[high] + numbers[low] == target){
                    index.push_back(high+1);
                    index.push_back(low+1);
                    return index;
                } else if(numbers[high] + numbers[low] > target){
                    low--;
                } else if(numbers[high] + numbers[low] < target){
                    high++;
                }
            }
        }
        return index;
    }
};