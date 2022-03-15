class Solution {
public:
    string minRemoveToMakeValid(string s) {
        multimap<char, int> m;
        int i, k = 0;
        string str;
        for(i = 0; i < s.size(); i++){
            if(s[i] == '('){
                str.push_back(s[i]);
                m.insert({s[i], k});
                ++k;
            } else if(s[i] == ')'){
                if(!m.empty()){
                    ++k;
                    str.push_back(s[i]);
                    m.erase(m.begin());
                }
            } else{
                str.push_back(s[i]);
                ++k;
            }
        }
        for(auto it = m.rbegin(); it != m.rend(); it++){
            str.erase(it->second, 1);
            // cout << it.first << it.second << endl;
        }
        return str;
    }
};