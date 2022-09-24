/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void addition(TreeNode* root, int targetSum, vector<int> &temp, vector<vector<int>> &ans){
        if(!root) return;
        temp.push_back(root->val);
        targetSum -= root->val;
        if(!root->right && !root->left){
            if(targetSum == 0){
                ans.push_back(temp);
            }
        } else{
            addition(root->left, targetSum, temp, ans);
            addition(root->right, targetSum, temp, ans);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        addition(root, targetSum, temp, ans);
        
        return ans;
    }
};