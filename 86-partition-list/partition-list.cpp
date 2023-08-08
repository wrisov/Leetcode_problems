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
    ListNode* partition(ListNode* head, int x) {
        ListNode* store = new ListNode(0);
        ListNode* temp = store;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(head!=nullptr){
            if(head->val<x){
                temp->next = new ListNode(head->val);
                temp=temp->next;
            } else {
                curr->next = new ListNode(head->val);
                curr=curr->next;
            }
            head=head->next;
        }
        temp->next = dummy->next;
        return store->next;
    }
};