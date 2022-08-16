class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 1) return 0;
        vector<int> v(26,-1);
        for(auto c:s){
            v[c-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'] == 0) return i;
        }
        return -1;
    }
};