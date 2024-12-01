/*
Bruteforce Approach:
Time Complexity: O(n²)
Space Complexity: O(n)
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto curr = head;
        while(curr) {
            auto next = curr->next;
            if(curr->child) {
                auto sub = flatten(curr->child);
                auto tail = getTail(sub);
                curr->next = sub;
                sub->prev = curr;
                tail->next = next;
                if(next) next->prev = tail;
                curr->child = nullptr;
            }
            curr = next;
        }
        return head;
    }

private:
    Node* getTail(Node* head) {
        while(head->next) {
            head = head->next;
        }
        return head;
    }
};

/*
Optimised Approach:
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return f1(head).first;
    }

private:
    pair<Node*, Node*> f1(Node* head) {
        auto curr = head;
        auto lastTail = curr;
        while(curr) {
            auto next = curr->next;
            if(curr->child) {
                auto [sub, tail] = f1(curr->child);
                curr->next = sub;
                sub->prev = curr;
                tail->next = next;
                if(next) next->prev = tail;
                curr->child = nullptr;
                lastTail = tail;
            }
            if(next) lastTail = next;
            curr = next;
        }
        return {head, lastTail};
    }
};
