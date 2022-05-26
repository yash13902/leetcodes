class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0, r;
        while(n > 0){
            r = n%2;
            if(r == 1) count++;
            n = n/2;
        }
        return count;
    }
};