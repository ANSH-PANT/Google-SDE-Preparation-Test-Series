/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

typedef struct hash_map {
    void* old;
    void* new;
    UT_hash_handle hh;
} hmap;

struct Node* copyRandomList(struct Node* head) {
    struct Node *res = NULL, *prev = NULL, *new;
    hmap* map = NULL;
    while (head) {
        new = malloc(sizeof(struct Node));
        if (!new) {
            return NULL;
        }
        new->val = head->val;
        new->random = head->random;
        new->next = NULL;
        hmap* entry;
        HASH_FIND_PTR(map, &head, entry);
        if (!entry) {
            entry = malloc(sizeof(hmap));
            if (!entry) {
                return NULL;
            }
            entry->old = head;
            entry->new = new;
            HASH_ADD_PTR(map, old, entry);
        }
        head = head->next;
        if (!res)
            res = new;
        else
            prev->next = new;
        prev = new;
    }
    new = res;
    while (new) {
        if (new->random) {
            hmap* entry;
            HASH_FIND_PTR(map, &new->random, entry);
            new->random = entry->new;
        }
        new = new->next;
    }
    hmap* entry, *tmp;
    HASH_ITER(hh, map, entry, tmp) {
        HASH_DEL(map, entry);
        free(entry);
    }
    return res;
}
