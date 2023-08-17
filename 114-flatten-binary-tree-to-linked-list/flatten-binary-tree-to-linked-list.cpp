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
    void preOrder(TreeNode* root, vector<int>& v){
        if(root == NULL)
        return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
        return;
        vector<int> v;
        TreeNode* dummy = root;
        preOrder(dummy, v);
        TreeNode* x = new TreeNode(v[0]);
        //root = x;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<endl;
        }
        for(int i=1;i<v.size();i++){
            TreeNode* a = new TreeNode(v[i]);
            root->right = a;
            root->left = NULL;
            root=root->right;
        }
    }
};