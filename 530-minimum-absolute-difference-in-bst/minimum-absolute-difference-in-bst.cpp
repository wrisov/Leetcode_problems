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
    TreeNode* prev = NULL;
    int Min = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return Min;
        getMinimumDifference(root->left);
        
        if(prev!=NULL){
            Min = min(Min, root->val - prev->val);
        }
        
        prev = root;
        
        getMinimumDifference(root->right);
        
        return Min;
    }
};