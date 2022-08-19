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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh,rh;
        if(root->left == NULL){
            lh = INT_MAX;
        }else{
            lh = minDepth(root->left);
        }
        if(root->right == NULL){
            rh = INT_MAX;
        }else{
            rh = minDepth(root->right);
        }
        if(lh == INT_MAX && rh == INT_MAX){
            lh=0;rh=0;
        }
        return 1 + min(lh,rh);
    }
};