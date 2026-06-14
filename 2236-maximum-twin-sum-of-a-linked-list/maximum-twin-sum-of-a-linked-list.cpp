class Solution {
public:
    int pairSum(ListNode* head) {

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Calculate twin sums
        int ans = 0;

        ListNode* p1 = head;
        ListNode* p2 = prev;

        while (p2) {
            ans = max(ans, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        return ans;
    }
};