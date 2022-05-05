class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;
        int i;
        for(i = 0;i<s.size();i++){
            if(s[i] == '#'){
                if(s1.size() > 0){
                    s1.pop();
                }
            } else{
                s1.push(s[i]);
            }
        }
        for(i = 0;i<t.size();i++){
            if(t[i] == '#'){
                if(t1.size() > 0){
                    t1.pop();
                }
            } else{
                t1.push(t[i]);
            }
        }
        s = ""; t = "";
        while(s1.size() > 0){
            s.push_back(s1.top());
            s1.pop();
        }
        while(t1.size() > 0){
            t.push_back(t1.top());
            t1.pop();
        }
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        if(s == t){
            return true;
        }
        return false;
    }
};