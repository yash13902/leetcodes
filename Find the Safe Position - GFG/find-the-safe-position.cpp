//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void kill(vector<int> &v, int k, int pos){
        if(v.size() == 1) return;
        // int d;
        // if(pos+k > v.size()){
        //     pos = ((pos+k)%v.size())-1;
        // }else{
        //     pos = (pos+k)-1;
        // }
        pos = (pos+k-1)%v.size();
        v.erase(v.begin()+pos);
        if(pos == v.size()) pos = 0;
        kill(v, k, pos);
        return;
    }
    
    int safePos(int n, int k) {
        // code here
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        kill(v, k, 0);
        return v[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends