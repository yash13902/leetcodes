//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int mod = 1e9+7;
    
    int recur(int arr[], int index, int sum, vector<vector<int>> &dp){
        if(index == 0){
            if(sum == 0 && arr[index] == 0) return 2;
            else if(sum==arr[index]||sum==0) return 1;
            return 0;
        }
        if(dp[index][sum] != -1) return dp[index][sum];
        int pick = 0;
        if(sum >= arr[index])
            pick = recur(arr, index-1, sum-arr[index], dp);
        int notpick = recur(arr, index-1, sum, dp);
        return dp[index][sum] = (pick%mod+notpick%mod)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	   //vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	   //return recur(arr, n-1, sum, dp);
	    
	    vector<int> dp(sum+1, 0);
        for(int i=0;i<sum+1;i++){
            if(arr[0] == 0 && i == 0) dp[i] = 2;
            else if(i == arr[0] || i == 0) dp[i] = 1;
            else dp[i] = 0;
        }
        for(int i=1;i<n;i++){
            vector<int> temp(sum+1, 0);
            for(int k=0;k<=sum;k++){
                int pick = 0;
                if(k >= arr[i])
                    pick = dp[k-arr[i]];
                int notpick = dp[k];
                temp[k] = (pick%mod+notpick%mod)%mod;
        	}
        	dp = temp;
        }
        
        return dp[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends