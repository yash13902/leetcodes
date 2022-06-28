class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = false;
        if(s.size() == 1) return false;
        for(auto c:s){
            if(c == '{' || c == '(' || c == '['){
                st.push(c);
                flag = true;
            }
            else if(c == '}'){
                if(st.size() && st.top() == '{') st.pop();
                else st.push(c);
            }
            else if(c == ']'){
                if(st.size() && st.top() == '[') st.pop();
                else st.push(c);
            }
            else if(c == ')'){
                if(st.size() && st.top() == '(') st.pop();
                else st.push(c);
            }
        }
        if(flag && st.size() == 0) return 1;
        return 0;
    }
};