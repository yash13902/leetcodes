//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(pq.empty() || pq.size() < k) pq.push(arr1[i]);
            else if(pq.size() == k){
                pq.push(arr1[i]);
                pq.pop();
            }
        }
        for(int i=0;i<m;i++){
            if(pq.empty() || pq.size() < k) pq.push(arr2[i]);
            else if(pq.size() == k){
                pq.push(arr2[i]);
                pq.pop();
            }
        }
        return pq.top();
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