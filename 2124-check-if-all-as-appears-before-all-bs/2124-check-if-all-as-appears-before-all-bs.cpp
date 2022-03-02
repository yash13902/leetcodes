class Solution {
public:
    bool checkString(string s) {
        int a=-1,b=INT_MAX,c2=0;
        for(int i=0; i < s.length(); i++){
            if(s.at(i) == 'a'){
                a = i;
            }
            if(c2 == 0 && s.at(i) == 'b'){
                c2 = 1;
                b = i;
            }
        }
        if(b-a > 0){
            return true;
        }
        return false;
    }
};