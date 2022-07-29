class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0;
        if(x==1) return 1;
        double mul=1;
        long copy = abs(n);
        cout << copy << endl;
        while(copy > 1){
            if(copy%2==0){
                x = x*x;
                copy /= 2;
                cout << x << " " << copy << " " << mul << endl;
            }else{
                copy--;
                mul *= x;
                x = x*x;
                copy /= 2;
                cout << x << " " << copy << " " << mul << endl;
            }
        }
        if(n > 0){
            return mul*x;
        }
        return 1/(mul*x);
    }
};