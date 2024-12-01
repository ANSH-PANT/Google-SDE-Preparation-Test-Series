/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL) 
      return NULL;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    ListNode* curr = prev->next;
    ListNode* next = nullptr;
    for (int i = 0; i < right - left; i++) {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy->next;
}
