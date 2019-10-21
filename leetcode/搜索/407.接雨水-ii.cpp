/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 * 思路：
 * 1.搜索队列使用优先级队列(堆)， 越低矮的点优先级越高(最小堆)， 越优先进行搜索。
 * 2.以矩形四周的点作为起始点进行广度优先搜索(这些点要最初push进入队列)。
 * 3.使用一个二维数组对push进入队列的点进行标记， 之后搜索到该点后， 不再push到队列中。
 * 4.只要优先级队列不空， 即取出优先级队列队头元素进行搜索， 按照上下左右四个方向进行拓展，
 *   拓展过程中忽略超出边界与已入队列的点。
 * 5.当对某点(x, y, h)进行拓展时，如果 h 大于 heightMap[newx][newy]:
 *   最终结果 += h - heightMap[newx][newy];
 *   将heightMap[newx][newy]赋值为h(即升高该位置的水面)。
 *   将(newx, newy, heightMap[newx][newy]) push进入优先级队列， 并做标记。
 */

// @lc code=start
struct Qitem {
    int x;
    int y;
    int h;
    Qitem(int _x, int _y, int _h) :
        x(_x), y(_y), h(_h) { }
};

struct cmp {
    bool operator()(const Qitem &a, const Qitem &b) {
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Qitem, vector<Qitem>, cmp> Q;
        if (heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;  // 行数或列数小于3，必然无法积水
        }
        int row = heightMap.size();
        int column = heightMap[0].size();
        vector<vector<int>> mark;   // 标记矩阵
        for (int i = 0; i < row; i++) {  // 初始化
            vector<int> temp;
            // mark.push_back(vector<int>());
            for (int j = 0; j < column; j++) {
                temp.push_back(0);
            }
            mark.push_back(temp);
        }
        
        for (int i = 0; i < row; i++) {
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, column - 1, heightMap[i][column - 1]));
            mark[i][column - 1] = 1;
        }
        
        for (int i = 1; i < column - 1; i++) {
            Q.push(Qitem(0, i , heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row -1, i, heightMap[row - 1][i]));
            mark[row - 1][i] = 1;
        }
        
        static const int dx[] = {-1, 1, 0, 0}; // 方向数组
        static const int dy[] = {0, 0, -1, 1};
        int result = 0;
        while (!Q.empty()) {
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= row ||
                    newy < 0 || newy >= column || mark[newx][newy]) {
                        continue;
                }
                if (h > heightMap[newx][newy]) { // 当前点的高度高出拓展点的高度
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;   // 填水
                }
                Q.push(Qitem(newx, newy, heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }
        }
        return result;
     }
};
// @lc code=end

