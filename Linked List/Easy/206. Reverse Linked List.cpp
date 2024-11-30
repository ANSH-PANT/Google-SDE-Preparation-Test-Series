/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *nxt = nullptr;
        while (curr != nullptr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
