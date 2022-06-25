class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(auto c:magazine){
            v[c-'a']++;
        }
        for(auto c:ransomNote){
            v[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(v[i] < 0) return false;
        }
        return true;
    }
};