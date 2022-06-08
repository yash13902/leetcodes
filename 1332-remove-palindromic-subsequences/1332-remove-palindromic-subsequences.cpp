class Solution {
public:
    
    bool palin(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        if(s1 == s){
            return true;
        }
        return false;
    }
    
    int removePalindromeSub(string s) {
        
        if(palin(s)) return 1;
        return 2;
    }
};