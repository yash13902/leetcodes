class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> s;
        int i;
        for(i=0;i<m;i++){
            s.insert(nums1[i]);
        }
        for(i=0;i<n;i++){
            s.insert(nums2[i]);
        }
        i=0;
        for(auto it=s.begin();it!=s.end();it++){
            nums1[i++] = *it;
        }
        
    }
};