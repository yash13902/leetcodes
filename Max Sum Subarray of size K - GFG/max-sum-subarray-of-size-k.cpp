//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long sum=0,mx=LONG_MIN;
        int i=0,j=0;
        // while(j<n){
        //     sum += arr[j];
        //     if(j+1-i<k) j++;
        //     else if(j+1-i == k){
        //         mx = max(mx, sum);
        //         sum = sum- arr[i];
        //         i++;
        //         j++;
        //     }
        // }
        for(j=0;j<k;j++){
            sum += arr[j];
        }
        mx = max(mx,sum);
        while(j<n){
            sum = sum - arr[i] + arr[j];
            mx = max(mx,sum);
            i++;j++;
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends