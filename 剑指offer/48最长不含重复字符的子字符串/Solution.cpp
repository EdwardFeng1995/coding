// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

// 思路1：
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> hashset;
        int max = 0, begin = 0, end = 0;
        while (begin < n && end < n) {
            if (hashset.find(s[end]) == hashset.end()) {
                hashset.insert(s[end]);
                end++;
                if (end-begin > max) {
                    max = end-begin;
                }
            } else {
                hashset.erase(s[begin]);
                begin++;
            }
        }
        return max;

    }
};

// 思路2：
// j代表第j个字符结尾
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, i, max = 0;
        for (int j = 0; j < s.length(); j++) {
            for (i = begin; i < j; i++) {
                if (s[i] == s[j]) {
                    begin = i+1;
                    break;
                }
            }
            if (j-begin+1 > max) {
                max = j-begin+1;
            }
        }
        return max;
    }
};
