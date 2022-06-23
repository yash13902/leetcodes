class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        s+=" ";
        int prev=0,i;
        for(i=0;i<s.size();i++){
            if(s[i] == ' '){
                v.push_back(s.substr(prev, i-prev));
                prev=i+1;
            }
        }
        s.clear();
        s="";
        for(i=0;i<v.size();i++){
            reverse(v[i].begin(), v[i].end());
            s+=v[i];
            s+=" ";
        }
        return s.substr(0,s.size()-1);
    }
};