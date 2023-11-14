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
    TreeNode* epicenter = nullptr;
    
    void preorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent,int start)
    {
        if(!root) return;
        if(root->val==start) epicenter=root;
        if(root->left)  parent[root->left]=root;
        if(root->right) parent[root->right]=root;
        preorder(root->left,parent,start);
        preorder(root->right,parent,start);
    }
    
    int bfs(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        root->val=-1;
        int timee=0;
        while(!q.empty())
        {
            int sz=q.size();
            timee++;
            while(sz--)
            {
                TreeNode* x = q.front();
                q.pop();
                
                if(x->left)
                {
                    if(x->left->val != -1)
                    {
                        q.push(x->left);
                        x->left->val = -1;
                    }
                }
                
                if(x->right)
                {
                    if(x->right->val != -1)
                    {
                        q.push(x->right);
                        x->right->val = -1;
                    }
                }
                
                if(parent[x])
                {
                    if(parent[x]->val != -1)
                    {
                        q.push(parent[x]);
                        parent[x]->val = -1;
                    }
                }
            }
        }
        return timee-1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=nullptr;
        preorder(root,parent,start);
        
        return bfs(epicenter,parent);
        
    }
    
};