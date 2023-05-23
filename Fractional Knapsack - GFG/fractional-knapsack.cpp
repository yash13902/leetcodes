//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            v.push_back({(double)arr[i].value/(double)arr[i].weight,{arr[i].weight, arr[i].value}});
        }
        sort(v.begin(), v.end(), greater<pair<double,pair<int,int>>>());
        double ans = 0;
        for(int i=0;i<n;i++){
            if(W == 0) break;
            if(v[i].second.first <= W){
                ans += (double)v[i].second.second;
                W -= v[i].second.first;
            }
            else if(v[i].second.first > W){
                ans += ((double)v[i].second.second/(double)v[i].second.first)*W;
                W -= W;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends