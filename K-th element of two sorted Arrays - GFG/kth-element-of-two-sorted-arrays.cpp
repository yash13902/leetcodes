//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int element(int arr1[], int arr2[], int n, int m, int k){
        if(n > m) return element(arr2, arr1, m, n, k);
        
        int low=max(0,k-m),high=min(k,n);
        int cut1,cut2,l1,l2,r1,r2;
        while(low<=high){
            cut1 = low + (high-low)/2;
            cut2 = k - cut1;
            
            l1 = (cut1==0)?INT_MIN:arr1[cut1-1];
            l2 = (cut2==0)?INT_MIN:arr2[cut2-1];
            r1 = (cut1==n)?INT_MAX:arr1[cut1];
            r2 = (cut2==m)?INT_MAX:arr2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }else if(l1 > r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(k == 1) return min(arr1[0], arr2[0]);
        if(k == n+m) return max(arr1[n-1], arr2[m-1]);
        return element(arr1, arr2, n, m, k);
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends