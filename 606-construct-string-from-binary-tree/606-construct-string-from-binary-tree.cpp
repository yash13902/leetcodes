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
    
    string preorder(TreeNode* root, string &ans){
        if(root == NULL) return "";
        ans+=to_string(root->val);
        if(root->left){
            ans += "(";
            preorder(root->left,ans);
            ans +=")";
        }
        if(root->right){
            if(!root->left) ans += "()";
            ans += "(";
            preorder(root->right,ans);
            ans +=")";
        }
        return ans;
        
    }
    
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string ans;
        preorder(root, ans);
        return ans;   
    }
};