/*
Time Complexity: O(1)
Space Complexity: O(capacity)
*/

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnodeAtFront(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key_) {
        if (mpp.find(key_) != mpp.end()) {
            Node* resnode = mpp[key_];
            deletenode(resnode);
            addnodeAtFront(resnode);
            return resnode->val;
        }
        return -1;
    }
    void put(int key_, int value) {
        if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;
            deletenode(node);
            addnodeAtFront(node);
        } 
        else {
            if (cap == mpp.size()) {
                Node* node = tail->prev;
                deletenode(node);
                mpp.erase(node->key);
            }
            Node* node = new Node(key_, value);
            mpp[key_] = node;
            addnodeAtFront(node);
        }
    }
};
