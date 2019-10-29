#include <iostream>
#include <vector>
using namespace std;

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

void preorder_trie(TrieNode* node, int layer)
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            for (int j = 0; j < layer; j++) {
                printf("---");
            }
            printf("%c", i + 'a');
            if (node->child[i]->is_end) {
                printf("(end)");
            }
            printf("\n");
            preorder_trie(node->child[i], layer+1);
        }
    }
}

void get_all_word_from_trie(TrieNode *node, string &word,
                            vector<string> &word_list) 
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            word.push_back(i + 'a');
            if (node->child[i]->is_end) {
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.length()-1, 1);
        }
    }
}

int main() 
{
    TrieTree trie_tree;
    trie_tree.insert("abcd");
    trie_tree.insert("abc");
    trie_tree.insert("abd");
    trie_tree.insert("b");
    trie_tree.insert("bcd");
    trie_tree.insert("efg");
    printf("preorder_trie:\n");
    preorder_trie(trie_tree.root(), 0);
    printf("\n");
    vector<string> word_list;
    string word;
    printf("ALL words:\n");
    get_all_word_from_trie(trie_tree.root(), word, word_list);
    for (int i = 0; i < word_list.size(); i++) {
        printf("%s\n", word_list[i].c_str());
    }
    printf("\n");
    printf("Search:\n");
    printf("abc: %d\n", trie_tree.search("abc"));
    printf("\n");
    printf("efg: %d\n", trie_tree.search("efg"));
    printf("\n");
    printf("StartsWith: \n");
    printf("b: %d\n", trie_tree.startsWith("b"));
    return 0;
}

/*
int main()
{
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a'-'a'] = &n1;
    root.child['b'-'a'] = &n2;
    root.child['e'-'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b'-'a'] = &n4;
    n2.child['c'-'a'] = &n5;
    n3.child['f'-'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c'-'a'] = &n7;
    n4.child['d'-'a'] = &n8;
    n5.child['d'-'a'] = &n9;
    n6.child['g'-'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d'-'a'] = &n11;
    n11.is_end = true;

    preorder_trie(&root, 0);
    cout << endl;
    vector<string> word_list;
    string word;
    get_all_word_from_trie(&root, word, word_list);
    for (auto i : word_list) {
        cout << i << endl;
    }

    return 0;
}
*/
