class Solution {
public:
    void solve(ListNode* &first, ListNode* &second, ListNode* &curr, int x){
        while(curr != NULL){
            if(curr->val < x){
                first->next = curr;
                first = curr;
            }
            else{
                second->next = curr;
                second = curr;
            }
            curr = curr->next;
        }
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode *smallHead = head, *largeHead = head;
        
        // Step 1 - Find the first small node and first large node
        // Also calculate the position at which they occur
        int sCount = 1, lCount = 1;
        while(smallHead != NULL && smallHead->val >= x){
            smallHead = smallHead->next;
            sCount++;
        }
        while(largeHead != NULL && largeHead->val < x){
            largeHead = largeHead->next;
            lCount++;
        }
        if(smallHead == NULL || largeHead == NULL)   
            return head;
        
        // Step 2 - Traverse the LL such that the two heads are adjacent
        // based on which head occurs first
        ListNode *first = smallHead, *second = largeHead, *curr;
        if(sCount < lCount){
            while(first->next != second)
                first = first->next;
            curr = second->next;
        }
        else{
            while(second->next != first)
                second = second->next;
            curr = first->next;
        }
        
        // Step 3 - Use solve() to form two separate LL and then merge them
        solve(first, second, curr, x);
        first->next = largeHead;
        second->next = NULL;
        return smallHead;
    }
};