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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recur(root, ans, 1);
        return ans;
    }
    void recur(TreeNode* root, vector<int> &ans, int depth){
        if(!root) return;
        if(ans.size()<depth) ans.push_back(root->val);
        recur(root->right, ans, depth+1);
        recur(root->left, ans, depth+1);
    }
};