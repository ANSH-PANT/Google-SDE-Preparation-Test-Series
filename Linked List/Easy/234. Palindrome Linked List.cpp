/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        auto itr = head;
        while (itr != nullptr) {
            itr = itr->next;
            ++n;
        }
        int n2 = n / 2;
        ListNode* rev = nullptr;
        while (n2--) {
            auto next = head->next;
            head->next = rev;
            rev = head;
            head = next;
        }
        if (n & 1)
            head = head->next;
        while (head != nullptr) {
            if (head->val != rev->val)
                return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};
