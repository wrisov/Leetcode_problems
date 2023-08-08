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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
        return head;
        if(head==nullptr)
        return head;
        vector<int> v;
        while(head!=nullptr){
            v.push_back(head->val);
            head=head->next;
        }
        int n = v.size();
        k=k%n;
        vector<int> v1;
        for(int i=n-k;i<n;i++){
            v1.push_back(v[i]);
        }
        for(int i=0;i<n-k;i++){
            v1.push_back(v[i]);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr=dummy;
        for(int i=0;i<n;i++){
            ListNode* n1 = new ListNode(v1[i]);
            curr->next=n1;
            curr=curr->next;
        }
        return dummy->next;
    }
};