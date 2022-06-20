// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,m,ans=1;
        bool flag=false;
        while(l<=n){
            m = n/2 + l/2 + (n%2 + l%2)/2;
            if(isBadVersion(m)){
                n=m-1;
                ans = m;
            }else if(!isBadVersion(m)){
                l=m+1;
            }
        }
        return ans;
    }
};