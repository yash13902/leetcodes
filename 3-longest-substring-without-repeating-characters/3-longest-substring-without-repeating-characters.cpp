class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int i, low;
        vector<char> v;
        vector<int> si;
        for(i=0;i<s.size()-1;i++){
            v.push_back(s[i]);
            low = i+1;
            while(low < s.size()){
                if(find(v.begin(), v.end(), s[low]) != v.end()){
                    break;
                } else{
                    v.push_back(s[low]);
                }
                low++;
            }
            si.push_back(v.size()); 
            v.clear();
            
        }
        return *max_element(si.begin(), si.end());
    }
};