/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// 思路：深搜DFS与宽搜BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_num = 0;
        vector<vector<int>> mark;
        for (int i = 0; i < grid.size(); i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++) {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (mark[i][j] == 0 && grid[i][j] == '1') {
                    DFS(mark, grid, i, j); // 或BFS
                    island_num++;
                }
            }
        }
        return island_num;
    }
private:
    // 深度搜索
    void DFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid,
             int x, int y) {
        mark[x][y] = 1;   // 标记已搜寻的位置
        static const int dx[] = {-1, 1, 0, 0};   // 方向数组
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            // 超过数组边界时
            if (newx < 0 || newx >= mark.size() ||
                newy < 0 || newy >= mark[newx].size()) {
                continue;
            }
            if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
                DFS(mark, grid, newx, newy);
            }
        }
    }
    // 宽度搜索
    void BFS(vector<vector<int>> &mark,
             vector<vector<char>> &grid,
             int x, int y) {
        static const int dx[] = {-1, 1, 0, 0};  // 方向数组
        static const int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> Q;   // 宽度优先搜索队列
        Q.push(make_pair(x,y));    // 将(x,y)push进入队列，并做标记
        mark[x][y] = 1;
        while (!Q.empty()) {
            x = Q.front().first;   // 取队列头部元素
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                // 拓展四个方向
                int newx = dx[i] + x;
                int newy = dy[i] + y;
                // 忽略越过地图边界的位置
                if (newx < 0 || newx >= mark.size() ||
                    newy < 0 || newy >= mark[newx].size()) {
                    continue;
                }
                // 如果当前位置未搜索，且为陆地
                if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
                    Q.push(make_pair(newx, newy));
                    mark[newx][newy] = 1;
                }
            }
        }
    }
};
// @lc code=end

