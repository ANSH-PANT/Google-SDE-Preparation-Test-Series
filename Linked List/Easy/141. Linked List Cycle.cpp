/*
Bruteforce Approach
Time Complexity: O(n)
Space Complexity: O(n)
*/

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    while(head != nullptr) {
        if(visited.find(head) != visited.end()) {
            return true;
        }
        visited.insert(head);
        head = head->next;
    }
    return false;
}

/*
Floyd's Tortoise and Hare algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/

bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}
