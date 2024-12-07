/*
Time Complexity: O(L), where L is the length.
Space Complexity: O(W * L), where W is the number of words.
*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode() { isWord = false; }
};
class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool search(string word) { 
      return searchHelper(root, word, 0); 
    }

    bool searchHelper(TrieNode* node, string& word, int index) {
        if (index == word.length()) {
            return node->isWord;
        }
        char c = word[index];
        if (c == '.') {
            for (auto& p : node->children) {
                if (searchHelper(p.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        } 
        else {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            TrieNode* child = node->children[c];
            return searchHelper(child, word, index + 1);
        }
    }
};
