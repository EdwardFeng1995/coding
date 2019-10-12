/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int res = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (char_map[i] == 1 || char_map[i]%2 == 1) {
                flag = 1;
            }
            if (char_map[i] >= 2) {
                res = res + char_map[i]/2 * 2;
            }
        }
        return res + flag;
    }
};
// @lc code=end

