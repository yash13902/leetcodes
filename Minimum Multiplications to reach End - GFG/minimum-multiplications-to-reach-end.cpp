//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    #define pi pair<int,int> 
    int mod = 100000;
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(mod, INT_MAX);
        dist[start] = 0;
        set<pi> pq;
        pq.insert({0,start});
        while(!pq.empty()){
            pi temp = *(pq.begin());
            pq.erase(temp);
            int steps = temp.first;
            int num = temp.second;
            if(num == end) return steps;
            for(auto c : arr){
                if(dist[(num*c)%mod] > steps+1){
                    if(dist[(num*c)%mod] != INT_MAX) pq.erase({(num*c)%mod, steps});
                    dist[(num*c)%mod] = steps+1;
                    pq.insert({steps+1, (num*c)%mod});
                }
            }
        }
        if(dist[end] == INT_MAX) return -1;
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends