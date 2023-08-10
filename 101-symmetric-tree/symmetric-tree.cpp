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
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool cmp(struct TreeNode* left,struct TreeNode* right)
 {
     if(left==NULL && right==NULL)
     return true;
     if(left==NULL||right==NULL)
     return false;
     return left->val==right->val &&cmp(left->left,right->right)&&cmp(left->right,right->left);
 }
bool isSymmetric(struct TreeNode* root){
if(root==NULL)
return true;
return cmp(root->right,root->left);
}
};