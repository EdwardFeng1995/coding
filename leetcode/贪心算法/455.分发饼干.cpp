/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 * 思路：贪心算法
 */
/*bool cmp(int a, int b) {
    return a >= b;
}*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end(), greater<int>());
        std::sort(s.begin(), s.end(), greater<int>());
        int child = 0;
        int cookie = 0;
        while (cookie < s.size() && child < g.size()) {
            if (g[child] <= s[cookie]) {
                cookie ++;
            }
            child++;
        }
        return cookie;
    }
};

