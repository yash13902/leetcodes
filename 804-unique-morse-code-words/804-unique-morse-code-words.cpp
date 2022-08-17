class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 1) return 1;
        int i;
        unordered_map<char, string> m = {{'a', ".-"}, 
                                         {'b', "-..."},
                                         {'c', "-.-."},
                                         {'d', "-.."},
                                         {'e', "."},
                                         {'f', "..-."},
                                         {'g', "--."},
                                         {'h', "...."},
                                         {'i', ".."},
                                         {'j', ".---"},
                                         {'k', "-.-"},
                                         {'l', ".-.."},
                                         {'m', "--"},
                                         {'n', "-."},
                                         {'o', "---"},
                                         {'p', ".--."},
                                         {'q', "--.-"},
                                         {'r', ".-."},
                                         {'s', "..."},
                                         {'t', "-"},
                                         {'u', "..-"},
                                         {'v', "...-"},
                                         {'w', ".--"},
                                         {'x', "-..-"},
                                         {'y', "-.--"},
                                         {'z', "--.."}};
        set<string> s;
        string ss="";
        for(i=0;i<words.size();i++){
            for(auto d : words[i]){
                ss += m[d];
            }
            s.insert(ss);
            ss = "";
        }
        return s.size();
    }
};