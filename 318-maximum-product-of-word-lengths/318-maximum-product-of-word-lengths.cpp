class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            int m = words[i].size();
            vector<int> included(26,0);
            for(auto it:words[i]) included[it-'a'] = 1;
            for(int j = i+1;j<words.size();j++){
                int count = 0;
                int n = words[j].size();
                for(auto it:words[j]){
                    if(included[it-'a'] == 0) count++;
                    else break;
                    if(count == words[j].size()){
                        ans = max(ans,m*n);
                    }
                }
            }
        }
        return ans;
    }
};