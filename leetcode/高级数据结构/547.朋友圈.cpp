/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
// 思路1：并查集
class DisjointSet
{
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    }

    int find(int p) {
        while (p != _id[p]) {
            _id[p] = _id[_id[p]];  // 将p的父节点_id[p] 更新为 _id[p] 的父节点 _d[_id[p]], 实现路径压缩
            p = _id[p];
        }
        return p;
    }

    void union_(int p, int q) {
        int i = find(p);  // 查找p所在集合的根节点
        int j = find(q);  // 查找q所在集合的根节点
        if (i == j) {
            return;
        }
        if (_size[i] < _size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }

    void print_set() {
        printf("元素：");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d ", i);
        }
        printf("\n");
        printf("集合：");
        for (int i = 0; i < _id.size(); i++) {
            printf("%d ", _id[i]);
        }
        printf("\n");
    }
    int count() {
        return _count;
    }
private:
    std::vector<int> _id;
    std::vector<int> _size;
    int _count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet disjoint_set(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = i+1; j < M.size(); j++) {
                if (M[i][j]) {
                    disjoint_set.union_(i, j);
                }
            }
        }
        return disjoint_set.count();
    }

};

// 深度优先搜索

// @lc code=end
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visit(M.size(), 0);
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (visit[i] == 0) {
                DFS(i, M, visit);
                count++;
            }
        }
        return count;
    }
private:
    void DFS(int u, vector<vector<int>>& graph, vector<int>& visit){
        visit[u] = 1;
        for (int i = 0; i < graph[u].size(); i++) {
            if (visit[i] == 0 && graph[u][i] == 1) {
                DFS(i, graph, visit);
            }
        }
    }
};
