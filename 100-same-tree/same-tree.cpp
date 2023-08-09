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
    bool x=true;
    void inorder(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)
            return;
        if(p==NULL && q!=NULL)
        {    x=false;
        return;
        }
        if(q==NULL && p!=NULL)
        {    x=false;
        return;
        }
        if(x==false)
            return;
        inorder(p->left,q->left);
            if(p->val!=q->val)
                x=false;
        inorder(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        inorder(p,q);
        return x;
    }
};