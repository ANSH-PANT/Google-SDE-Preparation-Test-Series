/*
Time Complexity: O(n).
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = length(head);
        return f1(head, n, k);
    }
private:
    int length(ListNode* head) {
        int n = 0;
        while(head) {
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* f1(ListNode* head, int n, int k) {
        if(n < k) return head;
        auto head2 = skip(head, k);
        auto ans = f1(head2, n-k, k);
        auto first = reverse(head, k);
        head->next = ans;
        return first;
    }
    
    ListNode* reverse(ListNode* stk1, int k) {
        ListNode* stk2 = nullptr;
        while(k--) {
            auto node = stk1;
            stk1 = stk1->next;
            node->next = stk2;
            stk2 = node;
        }
        return stk2;
    }
    ListNode* skip(ListNode* head, int k) {
        while(k--) {
            head = head->next;
        }
        return head;
    }
};
