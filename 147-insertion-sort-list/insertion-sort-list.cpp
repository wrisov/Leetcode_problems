class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        // Edge case
        if (!head || !head->next) {
            return head;
        }

        // Dummy node for sorted list
        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while (curr) {

            // Store next node
            ListNode* nextNode = curr->next;

            // Find position in sorted list
            ListNode* prev = dummy;

            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert current node
            curr->next = prev->next;
            prev->next = curr;

            // Move to next node
            curr = nextNode;
        }

        return dummy->next;
    }
};