class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sum = 0;
        int index = 0;
        for(auto it: patterns){
            if((index = word.find(it, 0)) != string::npos){
                sum++;
            }
        }
        return sum;
    }
};