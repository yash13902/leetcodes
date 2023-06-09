//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        int mini = INT_MAX;
        string m;
        int index=0;
        for(int i=0;i<n;i++){
            if(mini > arr[i].size()){
                mini = arr[i].size();
                m = arr[i];
                index = i;
            }
        }
        string res="";
        for(int i=1;i<=mini;i++){
            string temp = m.substr(0,i);
            for(int j=0;j<n;j++){
                if(j == index) continue;
                string com = arr[j];
                int k=0;
                while(k<temp.size()){
                    if(com[k] == temp[k]){
                        k++;
                    }else{
                        if(res == "") return "-1";
                        return res;
                    }
                }
            }
            res = temp;
        }
        if(res == "") return "-1";
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends