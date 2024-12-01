/*
Time Complexity: O((n * m) log(n * m))
Space Complexity: O(n * m)
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        priority_queue<pair<int, ListNode*>> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            while (lists[i] != nullptr) {
                pq.push({-lists[i]->val, lists[i]});
                lists[i] = lists[i]->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* k = nullptr;
        if (pq.empty())
            return head;
        head = pq.top().second;
        k = pq.top().second;
        pq.pop();
        while (!pq.empty()) {
            k->next = pq.top().second;
            k = pq.top().second;
            pq.pop();
        }
        k->next = NULL;
        return head == NULL ? nullptr : head;
    }
};
