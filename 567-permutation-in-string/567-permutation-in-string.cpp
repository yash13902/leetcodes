class Solution {
public:
    
    bool checkVec(vector<int> a, vector<int> b){
        for(int i=0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> m(26,0);
        vector<int> n(26,0);
        int i=0,j=0;
        for(i=0;i<s1.size();i++){
            m[s1[i]-'a']++;
        }
        i=0;
        while(j<s2.size()){
            n[s2[j]-'a']++;
            
            if(j-i+1 == s1.size()){
                if(checkVec(m,n)) return true;
            }
            
            if(j-i+1 < s1.size()) j++;
            else{
                n[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};