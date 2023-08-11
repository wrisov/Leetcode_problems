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
 //I commented this code because it causing extra O(N) T.C on every recursive call in solver function to find position it element in inorder so I used unorderd_map to store element with its index to retrive the position in O(1).
//    int findPos(vector<int> inorder,int size,int element)
//    {
//        for(int i=0;i<size;i++)
//        {
//            if(inorder[i]==element)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
   TreeNode* solver(vector<int> &preorder,vector<int> &inorder,int size,int &preIndex,int start,int end,unordered_map<int,int>  &mp)
   {
       if(preIndex>=size || start>end)
       {
           return NULL;
       }

       int element=preorder[preIndex++];
       int pos= mp[element];
       TreeNode* root=new TreeNode(element);
       root->left= solver(preorder,inorder,size,preIndex,start,pos-1,mp);
       root->right=solver(preorder,inorder,size,preIndex,pos+1,end,mp);
       return root;
       
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int preIndex=0;
        int start=0;
        int end=size-1;
        unordered_map<int,int>  mp;
        for(int i=0;i<size;i++)
        {
            mp[inorder[i]]=i;
        }

        TreeNode* root=solver(preorder,inorder,size,preIndex,start,end,mp);
        return root;
    }
};