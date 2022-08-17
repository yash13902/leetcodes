class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /*discussion approach
        vector<int> d(256, -1);
        int maxLen=0,start=-1;
        for(int i=0;i<s.size();i++){
            if(d[s[i]] > start){
                start = d[s[i]];
            }
            d[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
        */
        
        /* good approach
        set<int> c;
        int l=0,r=0,i,le=0,m;
        while(l<s.size() && r<s.size()){
            if(c.size()==0 || c.find(s[r]) == c.end()){
                c.insert(s[r++]);
                m=r-l;
                for(char d:c){
                    cout << "not found " << d << " ";
                }
                cout << endl;
                le = max(le, m);
            }else{
                cout << "found " << s[r] << endl;
                while(c.find(s[r]) != c.end()){
                    cout << "removing " << s[l] << endl;
                    c.erase(s[l]);
                    l++;
                }
                cout << "now inserting " << s[r] << endl;
                c.insert(s[r++]);
                m=r-l;
                le = max(le, m);
            }
        }
        return le;
        */
        
        // best approach
        
        map<char, int> m;
        int left=0,right=0,n=s.size(),len=0;
        while(right < n){
            if(m.find(s[right]) != m.end()){
                left = max(left, m[s[right]]+1);
            }
            m[s[right]] = right;
            len = max(len, right-left+1);
            right++;
        }
        return len;
    }
};