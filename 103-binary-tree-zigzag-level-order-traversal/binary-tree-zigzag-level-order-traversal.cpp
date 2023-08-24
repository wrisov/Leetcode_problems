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
   int height(TreeNode *root)
    {
        if(root==NULL)
            return(0);
        int left=height(root->left);
        int right=height(root->right);
        if(left>=right)
            return(left+1);
        return(right+1);
    }
    
    
    void leftToRight(TreeNode *root,int k,vector<int> &temp)
    {
        if(root==NULL)
            return;
        if(k==1)
            temp.push_back(root->val);
        leftToRight(root->left,k-1,temp);
        leftToRight(root->right,k-1,temp);
    }
    
    
    void rightToLeft(TreeNode *root,int k,vector<int> &temp)
    {
        if(root==NULL)
            return;
        if(k==1)
            temp.push_back(root->val);
        rightToLeft(root->right,k-1,temp);
        rightToLeft(root->left,k-1,temp);
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int> > ans;
        int ht=height(root);
        int k=1;
        while(k<=ht)
        {
            vector<int> temp;
            
            if(k%2!=0)
                leftToRight(root,k,temp);
            else
                rightToLeft(root,k,temp);
            
            ans.push_back(temp);
            
            temp.clear();
            
            k++;
        }
        return(ans);
    }
};