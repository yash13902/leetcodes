class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v;
        map<int,int> m;
        int count=0;
        for(auto c : arr){
            m[c]++;
        }
        for(auto c : m){
            v.push_back(c.second);
        }
        sort(v.begin(),v.end(),[](int a, int b){
            return a > b;
        });
        int len = arr.size();
        for(auto c : v){
            count++;
            len -= c;
            if(len > arr.size()/2) continue;
            else break;
        }
        return count;
    }
};