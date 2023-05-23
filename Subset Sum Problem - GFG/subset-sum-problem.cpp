//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool recur(vector<int> &arr, int sum, int index, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(index == 0) return arr[0] == sum;
        if(dp[index][sum] != -1) return dp[index][sum];
        bool notpick = recur(arr, sum, index-1, dp);
        bool pick = false;
        if(sum >= arr[index]){
            pick = recur(arr, sum-arr[index], index-1, dp);
        }
        return dp[index][sum] = pick | notpick;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return recur(arr, sum, n-1, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends