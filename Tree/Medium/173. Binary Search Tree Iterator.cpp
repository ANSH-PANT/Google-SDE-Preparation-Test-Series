/*
Time Complexity:
next(): O(height)
hasNext(): O(1)
Space Complexity: O(1)
*/

class BSTIterator {
    TreeNode* root;
    TreeNode* p;

public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        p = root;
        while (p->left)
            p = p->left;
    }
    int next() {
        int result = p->val;
        p = inorderSuccessor(root, p);
        return result;
    }
    bool hasNext() { return (p != nullptr); }

private:
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            TreeNode* successor = p->right;
            while (successor->left)
                successor = successor->left;
            return successor;
        } else {
            TreeNode* successor = nullptr;
            TreeNode* ptr = root;
            while (ptr != p) {
                if (p->val < ptr->val) {
                    successor = ptr;
                    ptr = ptr->left;
                } else {
                    ptr = ptr->right;
                }
            }
            return successor;
        }
    }
};

/*
Time Complexity:
next(): O(1)
hasNext(): O(1)
Space Complexity: O(height)
*/

class BSTIterator {
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        stk.push(root);
        while (root->left) {
            root = root->left;
            stk.push(root);
        }
    }
    int next() {
        int result = stk.top()->val;
        auto nodeptr = stk.top();
        stk.pop();
        if (nodeptr->right) {
            nodeptr = nodeptr->right;
            stk.push(nodeptr);
            while (nodeptr->left) {
                nodeptr = nodeptr->left;
                stk.push(nodeptr);
            }
        }
        return result;
    }
    bool hasNext() { return !stk.empty(); }
};
