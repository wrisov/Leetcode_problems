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
        vector<Node *> arr;
        arr.push_back(root);
        if(root==NULL) return root;
        while(arr.size()!=0){
            for(int i=0;i<arr.size();i++){
                if(i==arr.size()-1){
                    arr[i]->next=NULL;
                }
                else
                {
                   arr[i]->next=arr[i+1];

                }
            }
            int n=arr.size();  // store it to prevent runtime infinite condition!
            for(int i=0;i<n;i++){
             if(arr[i]->left!=NULL)   arr.push_back(arr[i]->left);
             if(arr[i]->right!=NULL) arr.push_back(arr[i]->right);

            }
            arr.erase(arr.begin(),arr.begin()+n);
        }
           return root;
    }
 
};