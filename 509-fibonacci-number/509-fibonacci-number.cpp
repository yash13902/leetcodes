class Solution {
public:
    
    int fib(int n) {
        return (int)((pow(((sqrt(5) + 1)/2),n) - pow((-(sqrt(5) + 1)/2),-n))/sqrt(5));
    }
};