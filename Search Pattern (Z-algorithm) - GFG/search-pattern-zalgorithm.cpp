//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        void z(string temp, int arr[]){
            arr[0] = 0;
            int n = temp.size();
            int right=0,left=0;
            for(int k=1;k<n;k++){
                if(k>right){
                    left = right = k;
                    while(right < n && temp[right] == temp[right-left]){
                        right++;
                    }
                    arr[k] = right-left;
                    right--;
                }else{
                    int k1 = k - left;
                    if(arr[k1] < right - k +1){
                        arr[k] = arr[k1];
                    }else{
                        left = k;
                        while(right < n && temp[right] == temp[right-left]){
                            right ++;
                        }
                        arr[k] = right-left;
                        right--;
                    }
                }
            }
        }
    
        vector <int> search(string pat, string txt)
        {
            //code hee.
            string temp = pat+"$"+txt;
            int l = temp.size();
            int arr[l];
            
            z(temp, arr);
            
            vector<int> ans;
            for(int i=pat.size()+1;i<l;i++){
                if(arr[i]==pat.size()){
                    ans.push_back(i-pat.size());
                }
            }return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends