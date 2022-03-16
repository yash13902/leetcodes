class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushIdx = 0, popIdx=0;
        int n = pushed.size();
        stack<int> s;
        while(true){
            if(popIdx==n) return true;
            if(s.empty()||popped[popIdx]!=s.top()){
                if(pushIdx==n) return false;
                s.push(pushed[pushIdx++]);
            }
            else{
                s.pop();
                popIdx++;
            }
        }
        
        return false;
        
    }
};