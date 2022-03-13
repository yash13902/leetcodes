class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> v{1,0};
        unordered_map<char, int> l;
        int i, k = 0;
        for(i = 97; i <= 122; i++){
            l.insert({(char)i, widths[k++]});
        }
        k = 0;
        for(i = 0; i < s.length(); i++){
            if(k + l.at(s[i]) <= 100){
                k += l.at(s[i]);
            } else{
                v[0]++;
                k = l.at(s[i]);
            }
        }
        v[1] = k;
        return v;
    }
};