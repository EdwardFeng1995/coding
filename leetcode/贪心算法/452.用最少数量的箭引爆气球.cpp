/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球\
 * 思路：贪心算法，在射穿一个气球的同时，尽可能地射穿更多的气球
 * 1. 先对各个气球排序
 * 2. 遍历气球数组，同时维护一个设计区间，尽可能击穿更多的气球，每击穿一个新的气球，更新一次射击区间
 * 3. 如果新的气球没办法被击穿了，则需要增加一名弓箭手，设置新的射击区间，继续遍历
 *
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int count = 1;
        std::sort(points.begin(), points.end());
        vector<int> range = points[0];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= range[1]) { // 新气球可以被击穿，更新射击区间
                range[0] = points[i][0];
                if (range[1] > points[i][1]) {
                    range[1] = points[i][1];
                }
            } else {  // 新气球不能被击穿了，增加弓箭手，设置新射击区间。
                count++;
                range = points[i];
            }
        }
        return count;
    }
};

