/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        while(head!= NULL){
            v.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<v.size();i=i+k){
            //cout<<"i "<<i<<",k "<<k<<endl;
            if(i+k<=v.size()){
                //cout<<"In for "<<i<<endl;
                reverse(v.begin()+i, v.begin()+i+k);
            }
        }
        // cout<<"ex= ";
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<",";
        // }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i=0;i<v.size();i++){
            ListNode* n = new ListNode(v[i]);
            curr->next = n;
            curr=curr->next;
        }
        return dummy->next;
    }
};