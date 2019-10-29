/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#define TRIE_MAX_CHAR_NUM 26
struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = 0;
        }
    }
};


class TrieTree{
public:
    TrieTree() {
    }
    ~TrieTree(){
        for (int i = 0; i < _node_vec.size(); i++) {
            delete _node_vec[i];
        }
    }
    void insert(const char *word) {
        // 将word插入至trie
        TrieNode* ptr = &_root;
        while (*word) {
            int pos = *word - 'a';
            if (!ptr->child[pos]) {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end = true;
    }
    bool search(const char *word) {
        // 搜索trie中是否存在word
        TrieNode* ptr = &_root;
        while (*word) {
            int pos = *word - 'a';
            if (!ptr->child[pos]) {
                return false;
            }
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }
    bool startsWith(const char *prefix) {
        // 检查trie中是否有前缀为prefix的单词
        TrieNode* ptr = &_root;
        while (*prefix) {
            int pos = *prefix - 'a';
            if (!ptr->child[pos]) {
                return false;
            }
            ptr = ptr->child[pos];
            prefix++;
        }
        return true;
    }
    TrieNode* root() {
        return &_root;
    }
private:
    TrieNode *new_node() {
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode*> _node_vec;
    TrieNode _root;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        _trie_tree.insert(word.c_str());
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _trie_tree.search(word.c_str());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _trie_tree.startsWith(prefix.c_str());
    }
private:
    TrieTree _trie_tree;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

