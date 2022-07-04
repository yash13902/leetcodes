class Solution {
public:
    bool isPowerOfThree(int n) {
        return power(3,n);
    }
    
    bool power(long k, int n){
        if(n < 3){
            if(n==1) return true;
            return false;
        }
        if(k > n) return false;
        if(k == n) return true;
        return power(k*3, n);
    }
};