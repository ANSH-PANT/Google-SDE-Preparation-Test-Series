/*
Time Complexity: O(n + m)
Space Complexity: O(n)
*/

class Solution {
private:
    void dfs(Node* node, unordered_set<Node*>& visited, unordered_map<Node*, Node*>& clone) {
        visited.insert(node);
        clone[node] = new Node(node->val);
        for (Node* neigh : node->neighbors) {
            if (visited.find(neigh) == visited.end()) {
                dfs(neigh, visited, clone);
            }
            clone[node]->neighbors.push_back(clone[neigh]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> clone;
        unordered_set<Node*> visited;
        dfs(node, visited, clone);
        return clone[node];
    }
};
