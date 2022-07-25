class Solution {
public:
    
    int bin(vector<int> &n,int target,int d){
        int l=0,h=n.size()-1,mid,ans=-1;
        while(l<=h){
            mid=(h+l)/2;
            if(n[mid]==target){
                ans=mid;
                if(d==0){
                    h=mid-1;
                }else if(d==1){
                    l=mid+1;
                }
                
            } else if(n[mid] > target){
                h=mid-1;
            }else{
                l=mid+1;   
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        if(nums.size() == 0){
            return ans;
        }
        int x = bin(nums,target,0);
        int y = bin(nums,target,1);
        ans[0]=x;
        ans[1]=y;
        return ans;
    }
};