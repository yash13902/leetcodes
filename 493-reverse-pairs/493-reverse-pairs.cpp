class Solution {
public:
    
    int merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right){
        int i=left, j=mid, k=left, rev_pairs=0;
        while(i<mid){
            while(j<=right && nums[i] > 2*(long)nums[j]) {
                j++;
            }
            rev_pairs += (j - (mid));
            i++;
        }
        i=left;
        j=mid;
        while(i<mid && j<=right){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        while(i<mid){
            temp[k++] = nums[i++];
        }
        while(j<=right){
            temp[k++] = nums[j++];
        }
        for(i=left;i<=right;i++){
            nums[i] = temp[i];
        }
        return rev_pairs;
        
    }
    
    int merge_sort(vector<int> &nums, vector<int> &temp, int left, int right){
        int rev_pairs=0, mid;
        if(right <= left) return 0;
            mid = (right+left)/2;
            rev_pairs += merge_sort(nums, temp, left, mid);
            rev_pairs += merge_sort(nums, temp, mid+1, right);
            
            rev_pairs += merge(nums, temp, left, mid+1, right);
            
        return rev_pairs;
    }
    
    
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        return merge_sort(nums, temp, 0, nums.size()-1);
    }
};