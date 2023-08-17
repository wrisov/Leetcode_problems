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
     int totalSum=0;
    
    void solve(TreeNode* root, int currSum){
        
        if(root->left==NULL && root->right==NULL) {
            currSum=currSum*10+root->val;
            totalSum+=currSum;
            return;
        }
        
        if(root->left!=NULL) solve(root->left,currSum*10+root->val);
        if(root->right!=NULL)solve(root->right,currSum*10+root->val);
		
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return totalSum;
    }
};