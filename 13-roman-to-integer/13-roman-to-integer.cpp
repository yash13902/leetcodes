class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        
        int ans=0,i=0;
        while(i<s.size()){
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    ans += 4;
                    i += 2;
                }else if(s[i+1] == 'X'){
                    ans += 9;
                    i += 2;
                } else{
                    ans += 1;
                    i++;
                }
            } else if(s[i] == 'V'){
                ans += 5;
                i++;
            } else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    ans += 40;
                    i += 2;
                }else if(s[i+1] == 'C'){
                    ans += 90;
                    i += 2;
                } else{
                    ans += 10;
                    i++;
                }
            } else if(s[i] == 'L'){
                ans += 50;
                i++;
            } else if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    ans += 400;
                    i += 2;
                }else if(s[i+1] == 'M'){
                    ans += 900;
                    i += 2;
                } else{
                    ans += 100;
                    i++;
                }
            } else if(s[i] == 'D'){
                ans += 500;
                i++;
            } else if(s[i] == 'M'){
                ans += 1000;
                i++;
            }
            
        }
        return ans;
    }
};