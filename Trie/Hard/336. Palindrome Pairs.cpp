/*
Time Complexity: O(N * L^2)
Space Complexity: O(N * L)
*/

struct TrieNode {
    TrieNode* arr[26];
    bool isEnd = false;
};

struct Trie {
    TrieNode* head;
    TrieNode* curr;
    unordered_map<string, int> m;

    Trie() { 
      head = new TrieNode(); 
    }

    void add(string s, int index) {
        m.insert(make_pair(s, index));
        curr = head;
        for (int i{}; i < s.size(); ++i) {
            if (curr->arr[s[i] - 'a'] == nullptr)
                curr->arr[s[i] - 'a'] = new TrieNode();
            curr = curr->arr[s[i] - 'a'];
        }
        curr->isEnd = true;
        return;
    }

    string str = "";
    string dfsstring = "";
    vector<int> ans;
    int duplicate;

    vector<int> search(string s, int duplicate) {
        curr = head;
        str.clear();
        dfsstring.clear();
        ans.clear();
        this->duplicate = duplicate;
        int index = 0;
        int n = s.size();
        while (index <= n) {
            if (curr->isEnd == true) {
                string v(s.begin() + index, s.end());
                if (isPalin(v)) {
                    auto it = m.find(str);
                    if (it->second != duplicate)
                        ans.push_back(it->second);
                }
            }
            if (index < n && curr->arr[s[index] - 'a'] != nullptr) {
                str.append(1, s[index]);
                curr = curr->arr[s[index] - 'a'];
                ++index;
            }
            else
                break;
        }
        if (index != n) {
            return ans;
        }
        dfs(curr);
        return ans;
    }

    void dfs(TrieNode* node) {
        for (int i{}; i < 26; ++i) {
            if (node->arr[i] != nullptr) {
                dfsstring.append(1, i + 'a');
                if (node->arr[i]->isEnd == true && isPalin(dfsstring)) {
                    string combined = str;
                    combined.append(dfsstring);
                    auto it = m.find(combined);
                    if (it->second != duplicate)
                        ans.push_back(it->second);
                }
                dfs(node->arr[i]);
                dfsstring.pop_back();
            }
        }
        return;
    }

    bool isPalin(const string& v) {
        int left = 0;
        int right = (int)v.size() - 1;
        while (left <= right) {
            if (v[left] != v[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        for (int i{}; i < words.size(); ++i)
            trie->add(words[i], i);
        vector<vector<int>> finalans;
        for (int i{}; i < words.size(); ++i) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            vector<int> v = trie->search(temp, i);
            for (int j{}; j < v.size(); ++j) {
                vector<int> ans(2);
                ans[0] = v[j];
                ans[1] = i;
                finalans.push_back(ans);
            }
        }
        return finalans;
    }
};
