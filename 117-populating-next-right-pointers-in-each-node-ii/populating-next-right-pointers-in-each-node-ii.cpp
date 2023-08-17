/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> v;
        v.push_back(root);
        if(root == NULL)
        return root;
        while(v.size()!=0){
            for(int i=0;i<v.size();i++){
                if(i==v.size()-1)
                v[i]->next = NULL;
                else
                v[i]->next = v[i+1];
            }
            int n = v.size();
            for(int i=0;i<n;i++){
                if(v[i]->left != NULL)
                v.push_back(v[i]->left);
                if(v[i]->right != NULL)
                v.push_back(v[i]->right);
            }
            v.erase(v.begin(),v.begin()+n);
        }
            return root;

    }
};