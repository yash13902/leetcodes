class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> ch;
        stack<int> cnt;
        for(int i = 0;i<s.length();i++){
            if(!ch.empty() && ch.top() == s[i]){
                int num = cnt.top() + 1;
                cnt.pop();
                cnt.push(num);
            }else{
                ch.push(s[i]);
                cnt.push(1);
            }
            if(cnt.top() == k){
                cnt.pop();
                ch.pop();
            }
        }
        string res = "";
        while(!ch.empty()){
            int number = cnt.top();
            while(number){
                res += ch.top();
                number--;
            }
            cnt.pop();
            ch.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};