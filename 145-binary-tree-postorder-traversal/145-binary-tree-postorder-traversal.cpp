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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> values;
        while (current != NULL){
            if (current->right == NULL){
                // Always insert at the beginning
                values.insert(values.begin(), current->val);
                current = current->left; // Reverse of preorder traversal
            }else{
                TreeNode* predecessor = findPredecessor(current);
                if (predecessor->left == NULL){
                    // Link to current
                    predecessor->left = current;
                    values.insert(values.begin(), current->val);
                    current = current->right;   // Reverse of preorder
                }else{
                    predecessor->left = NULL;
                    current = current->left;
                }
            }
        }
        return values;
    }
    TreeNode* findPredecessor(TreeNode* current){
        // Reverse of preorder traversal
        TreeNode* predecessor = current->right; 
        while (predecessor->left != NULL && predecessor->left != current){
            predecessor = predecessor->left;
        }
        return predecessor;
    }
};