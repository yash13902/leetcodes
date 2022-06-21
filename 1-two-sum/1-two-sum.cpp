#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        int n;
        for(int i=0;i<nums.size();i++){
            n = target - nums[i];
            if(m.find(n) != m.end()){
                res.push_back(m[n]);
                res.push_back(i);
                return res;
            }else{
                m[nums[i]] = i;
            }
        }
        return res;
    }
};