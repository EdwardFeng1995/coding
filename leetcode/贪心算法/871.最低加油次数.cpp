/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        std::priority_queue<int> Q;  // 最大堆，用来存储经过的加油站的汽油量
        int result = 0;  // 记录加过几次油
        vector<int> end = {target,0};  // 将终点作为一个停靠点，添加到stations数组
        stations.push_back(end);
        int L = 0;  // 记录距离起点的位置
        for (int i = 0; i < stations.size(); i++) {  // 遍历加油站
            int d = stations[i][0] - L;   // 到下一个加油站的距离
            // 如果当前油量不够到达下一个加油站，且之前有加油站，就加油，直到能油量够到达下一站
            while (d > startFuel && !Q.empty()) { 
                startFuel += Q.top();
                Q.pop();
                result++;
            }
            // 如果当前油量不够到达下一个加油站，且之前没有加油站，则无法到达终点
            if (d > startFuel && Q.empty()) {
                return -1;
            }
            // 前进到下一个加油站，油量更新
            startFuel -= d;
            L = L + d;
            // 将下一个加油站的油量加入最大堆
            Q.push(stations[i][1]);
        }
        return result;
    }
};

