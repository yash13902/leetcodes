//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void recur(int c1, int c2, string temp, vector<string> &ans, int N){
        if(temp.size() == N){
            ans.push_back(temp);
            return;
        }
        if(c1 == c2){
            temp += "1"; 
            recur(c1+1, c2, temp, ans, N);
        }
        if(c1 > c2){
            string temp1 = temp + "1";
            string temp2 = temp + "0";
            recur(c1+1, c2, temp1, ans, N);
            recur(c1, c2+1, temp2, ans, N);
        }
        return;
        
    }

	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    string temp="";
	    int c1=0, c2=0;
	    recur(c1, c2, temp, ans, N);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends