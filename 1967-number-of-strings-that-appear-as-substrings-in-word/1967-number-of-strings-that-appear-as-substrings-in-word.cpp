class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int sum = 0;
        int index = 0;
        for(auto it: patterns){
            if(word.find(it,0) != -1){
                cout << it;
                sum++;
            }
        }
        return sum;
    }
};