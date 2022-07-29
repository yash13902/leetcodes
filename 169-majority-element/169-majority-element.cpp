class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(auto c : nums){
            m[c]++;
        }
        map<int,int>::iterator x = max_element(m.begin(), m.end(), [](pair<int,int> a, pair<int,int> b){
            return b.second > a.second;
        });
        cout << x->second << endl;
        return x->first;
    }
};