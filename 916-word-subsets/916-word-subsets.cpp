class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> v;
        vector<int> f(26,0);
        vector<int> temp(26,0);
        bool flag = true;
        for(auto c : words2){
            for(auto d : c){
                temp[d-'a']++;
            }
            for(int i=0;i<26;i++){
                f[i] = max(f[i],temp[i]);
            }
            fill(temp.begin(), temp.end(), 0);
        }
        for(auto c : words1){
            for(auto d : c){
                temp[d-'a']++;
            }
            for(int i=0;i<26;i++){
                if(temp[i] < f[i]){
                    flag = false;
                }
            }
            if(flag){
                v.push_back(c);
            }
            flag = true;
            fill(temp.begin(), temp.end(), 0);
        }
        return v;
    }
};