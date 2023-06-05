//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int right=0;
        int j=0;
        int mini = INT_MAX;
        string res;
        while(right < str1.size()){
            int j=0;
            while(right<str1.size()){
                if(str2[j] == str1[right]){
                    j++;
                }
                if(j == str2.size()) break;
                right++;
            }
            if(right == str1.size()) break;
            
            int left = right;
            j = str2.size()-1;
            while(left>=0){
                if(str2[j] == str1[left]){
                    j--;
                }
                if(j < 0) break;
                left--;
            }
            if(right - left + 1 < mini){
                mini = right-left+1;
                res = str1.substr(left, mini);
            }
            right = left + 1;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends