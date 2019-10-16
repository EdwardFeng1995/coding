/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
// 思路：BFS，与双端BFS
// 最优的为双端BFS，从头尾开始搜，相遇时就返回结果
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        unordered_set<string> q1 = {beginWord};
        unordered_set<string> q2 = {endWord};
        int l = beginWord.size();
        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            step++;
            if (q1.size() > q2.size()) {
                swap(q1, q2);
            }
            unordered_set<string> q;
            for (auto str:q1) {
                for (int i = 0; i < l; i++) {
                    string temp = str;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (q2.count(str)) {
                            return step+1;
                        }
                        if (!dict.count(str)) {
                            continue;
                        }
                        dict.erase(str);
                        q.insert(str);
                    }
                    str = temp;
                }
            }
            q1 = q;
        }
        return 0;
    }
};

// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int l = beginWord.length();
        int step = 0;
        while (!q.empty()) {
            step++;
            for (int size = q.size(); size > 0; size--) {
                string str = q.front();
                q.pop();
                for (int i = 0; i < l; i++) {
                    string temp = str;
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (str == endWord) {
                            return step+1;
                        }
                        if (!dict.count(str)) {
                            continue;
                        }
                        dict.erase(str);
                        q.push(str);
                    }
                    str = temp;
                }
            }
        }
        return 0;
    }
};

// 图算法，构建图，然后搜路径，有些蠢，但思路可以借鉴
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }
private:
    bool connect(const string &word1, const string &word2) {
        int cnt = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    void construct_graph(string &beginWord, vector<string> &wordList,
                         map<string, vector<string>> &graph) {
        wordList.push_back(beginWord);
        for (int i =0; i < wordList.size(); i++) {
            graph[wordList[i]] = vector<string>();
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i +1; j < wordList.size(); j++) {
                if (connect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    int BFS_graph(string &beginWord, string &endWord,
                  map<string, vector<string>> &graph) {
        queue<pair<string, int>> Q;   // 搜索队列<顶点，步数>
        set<string> visit;
        Q.push(make_pair(beginWord, 1));
        visit.insert(beginWord);
        while (!Q.empty()) {
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (node == endWord) {
                return step;
            }
            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++) {
                if (visit.find(neighbors[i]) == visit.end()) {
                    Q.push(make_pair(neighbors[i], step+1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

