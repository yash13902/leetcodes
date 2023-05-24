//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum += arr[i];
	    }
	    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	    for(int i=0;i<n;i++) dp[i][0] = true;
	    dp[0][arr[0]] = true;
	    for(int i=1;i<n;i++){
	        for(int k=1;k<=sum;k++){
	            bool np = dp[i-1][k];
	            bool p = false;
	            if(k >= arr[i])
	                p = dp[i-1][k-arr[i]];
	            dp[i][k] = p || np;
	        }
	    }
	    int mini = INT_MAX;
	    for(int i=0;i<sum;i++){
	        if(dp[n-1][i] == true){
	            int s1 = i;
	            int s2 = sum - i;
	            mini = min(mini, abs(s1-s2));
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends