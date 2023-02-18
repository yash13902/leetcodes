//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int> c(26,0);
	    for(auto d : pat){
	        c[d - 'a']++;
	    }
	    vector<int> ana(26,0);
	    int sum=0,i=0,j=0,k=pat.size();
	    while(j<txt.size()){
	        ana[txt[j] - 'a']++;
	        if(j-i+1 < k) j++;
	        else if(j-i+1 == k){
	            if(ana == c) sum++;
	            ana[txt[i] - 'a']--;
	            i++;j++;
	        }
	    }
	    return sum;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends