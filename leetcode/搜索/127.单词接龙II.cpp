/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// 思路：单广，找到每一层的parent或child，然后再深搜路径，两种方法，
// 一种是从endWord开始，找每一层单词的parent
// 一种是从beginWord开始，找每一层单词的child
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict = {wordList.begin(),wordList.end()};
        if (!dict.count(endWord)) {
            return result;
        }
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        const int l = beginWord.length();
        int step = 0;
        bool found = false;
        
        while (!q.empty() && !found) {
            step++;
            for (int size = q.size(), j = 0; size > 0 ; size--, j++ ) {
                const string p = q.front();
                q.pop();
                string str = p;
                for (int i = 0; i < l; i++) {
                    string str_temp = str;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (str == endWord) {
                            parents[str].push_back(p);
                            found = true;
                        } else {
                            // 不是一个新词，但是其他词p也可以转换成该词，将p设为该次的parent
                            if (steps.count(str) && step < steps.at(str))
                                parents[str].push_back(p);
                        }
                        if (!dict.count(str)) {
                            continue;
                        }
                        dict.erase(str);
                        q.push(str);
                        steps[str] = steps.at(p) + 1;
                        parents[str].push_back(p);
                    }
                    str = str_temp;
                }
            }
        }
        
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, result);
        }
        return result;
    }
private:
    void getPaths(const string& word,
                  const string& beginWord,
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {
        if (word == beginWord) {
            ans.push_back(vector<string>{curr.rbegin(), curr.rend()});
            return;
        }

        for (const string& p : parents.at(word)) {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict = {wordList.begin(),wordList.end()};
        if (!dict.count(endWord)) {
            return result;
        }
        dict.erase(endWord);
        unordered_set<string> q{beginWord}, p;
        unordered_map<string, vector<string>> children;
        const int l = beginWord.length();
        bool found = false;
        
        while (!q.empty() && !found) {
            for (const string& word : q) {
                dict.erase(word);
            }
            for (const string& word : q) {
                string str = word;
                for (int i = 0; i < l; i++) {
                    string str_temp = str;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (str == endWord) {
                            children[word].push_back(str);
                            found = true;
                        } else if (dict.count(str) && !found) {
                            children[word].push_back(str);
                            p.insert(str);
                        }
                    }
                    str = str_temp;
                }
            }
            swap(p, q);
            p.clear();
        }
        
        if (found) {
            vector<string> path{beginWord};
            getPaths(beginWord, endWord, children, path, result);
        }
        return result;
    }
private:
    void getPaths(const string& word,
                  const string& endWord,
                  const unordered_map<string, vector<string>>& children,
                  vector<string>& path,
                  vector<vector<string>>& ans) {
        if (word == endWord) {
            ans.push_back(vector<string>{path.begin(), path.end()});
            return;
        }

        if (children.find(word) == children.end()) {
            return;
        }
        for (const string& child : children.at(word)) {
            path.push_back(child);
            getPaths(child, endWord, children, path, ans);
            path.pop_back();
        }
    }
};

// 思路：双广，速度很快，设置一个backward标志正向还是反向
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> dict = {wordList.begin(),wordList.end()};
        if (!dict.count(endWord)) {
            return result;
        }
        dict.erase(endWord);
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_map<string, vector<string>> children;
        const int l = beginWord.length();
        bool found = false;
        bool backward = false;
        
        while (!q1.empty() && !q2.empty() && !found) {
            if (q1.size() > q2.size()) {
                swap(q1,q2);
                backward = !backward;
            }
            for (const string& word : q1) {
                dict.erase(word);
            }
            for (const string& word : q2) {
                dict.erase(word);
            }

            unordered_set<string> p;
            for (const string& word : q1) {
                string str = word;
                for (int i = 0; i < l; i++) {
                    string str_temp = str;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;

                        const string* parent = &word;
                        const string* child = &str;
                        
                        if (backward) {
                            swap(parent, child);
                        }
                        if (q2.count(str)) {
                            children[*parent].push_back(*child);
                            found = true;
                        } else if (dict.count(str) && !found) {
                            children[*parent].push_back(*child);
                            p.insert(str);
                        }
                    }
                    str = str_temp;
                }
            }
            swap(p, q1);
        }
        
        if (found) {
            vector<string> path{beginWord};
            getPaths(beginWord, endWord, children, path, result);
        }
        return result;
    }
private:
    void getPaths(const string& word,
                  const string& endWord,
                  const unordered_map<string, vector<string>>& children,
                  vector<string>& path,
                  vector<vector<string>>& ans) {
        if (word == endWord) {
            ans.push_back(vector<string>{path.begin(), path.end()});
            return;
        }

        if (children.find(word) == children.end()) {
            return;
        }
        for (const string& child : children.at(word)) {
            path.push_back(child);
            getPaths(child, endWord, children, path, ans);
            path.pop_back();
        }
    }
};