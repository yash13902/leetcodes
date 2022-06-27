class Solution {
public:
    int minPartitions(string n) {
        int m=INT_MIN;
        for(auto c:n){
            m = max(m,c-'0');
        }
        return m;
    }
};